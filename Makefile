#\to run it on collonial1:
#   module avail openmpi
#   module load openmpi/.....    //opens a needed version!!!

all: compile running

compile: 
	mpicc -std=c99 -lm duck_goose.c -o run

running: 
	@echo ' '
	@echo To run code you need to type in terminal:  mpirun -n "X" ./run
	@echo 'where X is a number of processors'
	@echo ' '
