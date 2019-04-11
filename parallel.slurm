#!/bin/bash
#SBATCH --nodes=2
#SBATCH --ntasks-per-node=16
#SBATCH --time=4:00:00
#SBATCH --job-name pranjal16
#SBATCH --output=alright_number.txt
#SBATCH --mail-type=FAIL


module load gcc boost openmpi

cd $SLURM_SUBMIT_DIR

mpiexec -n 4 ./walkring

mpiexec -n 5 ./walkring

mpiexec -n 6 ./walkring

mpiexec -n 7 ./walkring

mpiexec -n 8 ./walkring

mpiexec -n 9 ./walkring

mpiexec -n 10 ./walkring

mpiexec -n 11 ./walkring

mpiexec -n 12 ./walkring

mpiexec -n 14 ./walkring

mpiexec -n 15 ./walkring

mpiexec -n 16 ./walkring

mpiexec -n 18 ./walkring

mpiexec -n 20 ./walkring

mpiexec -n 21 ./walkring

mpiexec -n 22 ./walkring

mpiexec -n 24 ./walkring

mpiexec -n 28 ./walkring

mpiexec -n 30 ./walkring

mpiexec -n 32 ./walkring

