#include <stdio.h>
#include <stdlib.h>

//  Now we know that argc is the length of the char array argv which would be arguments passed
//  into the program we make

void cleanup(int ** p);

int main(int argc, char* argv[])
{
	const int ARRSIZE = 50;
	int * array = (int *)malloc(ARRSIZE * sizeof(int));

	//  committing actual heresy, a pointer to a pointer 
	int ** array_pointer; 
	printf("array pointer address: 0x%X\n", array_pointer);
	//  this is useful if we cleanup the 
	
	//  Printing the number of arguments passed in. This will always be at least 1
	//  which is the location of the executable. 
	printf("%d arguments \n" , argc);
	

	//  making some values up	
	array[0] = 10;
	array[1] = 20; 

	if (array == NULL)
	{
		printf("Error allocating space \n");
		return 1;
	}
	
	int i; 
	printf("memory address: %d\t0x%X\n", array, array);
	for (i = 0; i < ARRSIZE; i++)
	{
		array[i] = 2 + i * 3;
		printf("%d ", array[i]); 
	}
	
	printf("\n derefrencing array is: %d\n", *array);
	printf("What happens? %f\n", *((double *)array));
	
	// Testing our new cleanup method
	cleanup(&array);
	cleanup(&array);

	//  Giving the memory back to the OS
	//  freeing the memory twice will cause it to crash due to a double free error
	//free(array);
	free(array);
	array = NULL;
	
	return 0;


}

void cleanup(int ** p)
{
	if(*p != NULL)
	{
		free(*p);
	}
	else
	{
		 printf("\nMemory has already been freed. Nothing will be performed. \n");
	}
	*p = NULL;
}
