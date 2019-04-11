For this project, we had to take walkring and parallelize it using mpi. To do this, we mostly only had to modify the
walkring.cc file by adding the proper mpi statements. In this file, we initialized the mpi processes and defined rank 
and size. Then using the scatter functions in MPI, distributed the array that contains the ants to n processors, doing
the operation and then gathering what come out.

Doing this, we found a speedup that seems linear, as can be seen in speedup.png . This finds the time it takes to run the
program given different numbers of processors and is calculated by doing (Walltime with 1 core)/(Walltime with n cores), this
result does make sense.