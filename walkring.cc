// 
// walkring.cc
//
// 1d random walk on a ring
//
// Compile with make using provided Makefile 
//

#include <fstream>
#include <rarray>
#include <cmath>
#include "walkring_output.h"
#include "walkring_timestep.h"
#include "parameters.h"
#include <mpi.h>

using namespace std;

#define MTAG1 1
#define MTAG2 2

// the main function drives the simulation
int main(int argc, char *argv[]) 
{
  // Simulation parameters
  double      L;  // ring length
  double      D;  // diffusion constant
  double      T;  // time
  double      dx; // spatial resolution
  double      dt; // temporal resolution (time step)
  int         Z;  // number of walkers
  std::string datafile; // filename for output
  double      time_between_output;

  // Read parameters from a file given on the command line. 
  // If no file was given, use "params.ini".
  std::string paramFilename = argc>1?argv[1]:"params.ini";
  read_parameters(paramFilename, L, D, T, dx, dt, Z, datafile, time_between_output);

  // Compute derived parameters 
  const int numSteps = int(T/dt + 0.5);  // number of steps to take
  const int N = int(L/dx + 0.5);         // number of grid points
  const int outputEvery = int(time_between_output/dt + 0.5); // how many steps between output
  const double p = D*dt/pow(dx,2);       // probability to hop left or right
  const int outputcols = 48;             // number of columns for sparkline output
    
  int rank,size;

  MPI_Status status;
  MPI_Init(&argc,&argv);
  MPI_Comm_size(MPI_COMM_WORLD,&size);
  MPI_Comm_rank(MPI_COMM_WORLD,&rank);

  // Allocate walker data
  rarray<int,1> w(Z);
  if(rank == 0)
    // Setup initial conditions for w
    w.fill(N/2);
  // Setup initial time
  double time = 0.0;

  // Open a file for data output
  std::ofstream file;
  if(rank == 0)
  {
    walkring_output_init(file, datafile);  
    // Initial output to screen
    walkring_output(file, 0, time, N, w, outputcols);
  }
  
  int array_size = Z/size;

  rarray<int, 1> w_buf(array_size);

  MPI_Scatter(w.data(),array_size,MPI_INT,w_buf.data(),array_size,MPI_INT,1,MPI_COMM_WORLD);
  // Time evolution
  
  for (int step = 1; step <= numSteps; step++) {
    
    walkring_timestep(w_buf, N, p);
  
    // Update time
    time += dt;

    //MPI_Gather(w.data(),array_size,MPI_INT,w.data(),array_size,MPI_INT,1,MPI_COMM_WORLD);    // Periodically add data to the file
    if (step % outputEvery == 0 and step > 0)      {
       MPI_Gather(w_buf.data(),array_size,MPI_INT,w.data(),array_size,MPI_INT,1,MPI_COMM_WORLD);
      if(rank == 0 ) 
	walkring_output(file, step, time, N, w, outputcols);
    }}
  
  //MPI_Gather(w.data(),array_size,MPI_INT,w.data(),array_size,MPI_INT,1,MPI_COMM_WORLD);
  //walkring_output(file, step, time, N, w, outputcols);
  
  if (rank == 0)
    // Close file
    walkring_output_finish(file);
  MPI_Finalize();
  
// All done
  return 0;
}

