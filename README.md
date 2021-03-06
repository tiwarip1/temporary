For this project, we had to take walkring and parallelize it using mpi. To do this, we mostly only had to modify the
walkring.cc file by adding the proper mpi statements. In this file, we initialized the mpi processes and defined rank 
and size. Then using the scatter functions in MPI, distributed the array that contains the ants to n processors, doing
the operation and then gathering what come out.

Doing this, we found a speedup that seems linear, as can be seen in speedup.png . This finds the time it takes to run the
program given different numbers of processors and is calculated by doing (Walltime with 1 core)/(Walltime with n cores), this
result does make sense.

commit 7112184324f1db23b3aa257df0709a224d63272a
Author: HerpDerp <herpitehderpo@gmail.com>
Date:   Thu Apr 11 19:23:57 2019 -0400

    finished the project

 README.md   |   9 ++++++++-
 plot.py     |  13 +++++++++++++
 speedup.png | Bin 0 -> 111281 bytes
 3 files changed, 21 insertions(+), 1 deletion(-)

commit a9bd002d9273d8955fbf1a3f6ca90e993557ef02
Author: Pranjal Tiwari <herpitehderpo@gmail.com>
Date:   Thu Apr 11 19:08:10 2019 -0400

    finished the sbatch process

 alright_number.txt | Bin 10789 -> 95619 bytes
 output.dat         |  55 ++++++++++++++++++++++++++++++++++++++++++++---------
 parallel.slurm     |   8 +-------
 params.ini         |   2 +-
 walkring           | Bin 2346680 -> 2346680 bytes
 walkring.cc        |  18 ++++++------------
 walkring.o         | Bin 653936 -> 653936 bytes
 7 files changed, 54 insertions(+), 29 deletions(-)

commit 586be0dc068e25c469ae6a235c073559fa43dfe4
Author: Pranjal Tiwari <herpitehderpo@gmail.com>
Date:   Thu Apr 11 16:36:05 2019 -0400

    got the parallelization working

 alright_number.txt   |  64 ++++++++++++++++++++++++++++++++++++
 diff_16.txt          |  91 +++++++++++++++++++++++++++++++++++++++++++++++++++
 output.dat           |  54 +++++-------------------------
 parallel.slurm       |  59 +++++++++++++++++++++++++++++++++
 parallel.slurm~      |  59 +++++++++++++++++++++++++++++++++
 params.ini           |   2 +-
 walkring             | Bin 2345080 -> 2346680 bytes
 walkring.cc          |  69 ++++++++++++++++++++++++--------------
 walkring.o           | Bin 650328 -> 653936 bytes
 walkring_timestep.cc |   5 ++-
 walkring_timestep.o  | Bin 578064 -> 578888 bytes
 11 files changed, 331 insertions(+), 72 deletions(-)

commit 3ad05d09bdc957e0ab19c2f7ab4b466044a72f64
Author: Pranjal Tiwari <herpitehderpo@gmail.com>
Date:   Thu Apr 11 13:33:54 2019 -0400

    ran in parallel for atleast 2 cores

 output.dat  |  62 +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++-
 walkring    | Bin 2345112 -> 2345080 bytes
 walkring.cc |  21 ++++----------------
 walkring.o  | Bin 650664 -> 650328 bytes
 4 files changed, 65 insertions(+), 18 deletions(-)

commit 2ee72b5404715358f6af48107d56ed99cd1acf92
Author: Pranjal Tiwari <herpitehderpo@gmail.com>
Date:   Wed Apr 10 13:33:57 2019 -0400

    tried to get mpi to work, but I'm getting some errors I don't understand

 Makefile             |   2 +-
 diffring             | Bin 0 -> 1991624 bytes
 diffring.o           | Bin 0 -> 161624 bytes
 diffring_output.o    | Bin 0 -> 257344 bytes
 diffring_timestep.o  | Bin 0 -> 78528 bytes
 mpi                  |   1 +
 output.dat           |   2 ++
 parameters.o         | Bin 0 -> 2757416 bytes
 sparkline.o          | Bin 0 -> 522952 bytes
 ticktock.o           | Bin 0 -> 66288 bytes
 walkring             | Bin 0 -> 2345112 bytes
 walkring.cc          |  35 ++++++++++++++++++++++++++++++++---
 walkring.o           | Bin 0 -> 650664 bytes
 walkring_output.o    | Bin 0 -> 257120 bytes
 walkring_timestep.cc |   4 ++++
 walkring_timestep.o  | Bin 0 -> 578064 bytes
 16 files changed, 40 insertions(+), 4 deletions(-)

commit 89e017ef0d40f625faac973175b4e6c1410ae725
Author: Pranjal Tiwari <herpitehderpo@gmail.com>
Date:   Mon Apr 8 16:21:50 2019 -0400

    initial commit

 Makefile             |  65 ++++++++++++++++++++++
 assignment7.pdf      | Bin 0 -> 241905 bytes
 diffring.cc          |  76 ++++++++++++++++++++++++++
 diffring_output.cc   |  59 ++++++++++++++++++++
 diffring_output.h    |  35 ++++++++++++
 diffring_timestep.cc |  39 ++++++++++++++
 diffring_timestep.h  |  25 +++++++++
 parameters.cc        |  71 ++++++++++++++++++++++++
 parameters.h         |  25 +++++++++
 params.ini           |   8 +++
 sparkline.cc         | 149 +++++++++++++++++++++++++++++++++++++++++++++++++++
 sparkline.h          | 102 +++++++++++++++++++++++++++++++++++
 ticktock.cc          |  54 +++++++++++++++++++
 ticktock.h           |  20 +++++++
 walkring.cc          |  74 +++++++++++++++++++++++++
 walkring_output.cc   |  61 +++++++++++++++++++++
 walkring_output.h    |  37 +++++++++++++
 walkring_timestep.cc |  58 ++++++++++++++++++++
 walkring_timestep.h  |  31 +++++++++++
 19 files changed, 989 insertions(+)

commit 1fd3e33b85d9506f13781cf49fa1a8fcd9c96bfd
Author: Pranjal Tiwari <herpitehderpo@gmail.com>
Date:   Mon Apr 8 16:19:30 2019 -0400

    Create README.md

 README.md | 1 +
 1 file changed, 1 insertion(+)