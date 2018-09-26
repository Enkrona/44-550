#  this is a comment

CC = gcc
CCFLAGS = -g -o

array: arrays.c
	$(CC) arrays.c $(CCFLAGS) array
	echo "Compiled arrays"
arrayandmemory: arrayandmemory.c
	$(CC) arrayandmemory.c $(CCFLAGS) array_mem
	echo "Compiled marrayandmemory.c, as output array_mem"
