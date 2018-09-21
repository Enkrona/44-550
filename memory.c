#include <stdio.h>

#include <stdlib.h>

/*
 *  Dangling pointers: When stuff changes and it is left there
 *  Anything you allocate, deallocate!
 *  1:1 matching of allocation/deallocate
 *  Try to use const when possible! 
 *  gdb/valgrind are you heros
 *  *void is a pointer to an address which has no type associated
 *  	can be called whatever type we want, battle royale of memory
 *  
 */


int main(int argc, char *argv[])
{
	const int ARRSIZE = 10;

	int *array = (int *)malloc(ARRSIZE * sizeof(int));

	// could also calloc(ARRSIZE, sizeof(int));
	if (array == NULL) 
	{
		printf("Error allocating space\n");
		return 1;
	}

	int i;

	printf("memory address: %d\t0x%X\n", array, array);
	for (i = 0; i < ARRSIZE; i++)
	{
		array[i] = 2 + i * 3;
		printf("%d ", array[i]);
	}

	printf("\ndereferencing array is: %d\n", *array);

	printf("what happens? %f\n", *((double *)array));

	free(array);

	array = NULL;
	
	return 0:
}
