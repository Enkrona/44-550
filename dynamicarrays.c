/*
 *  Pointers allow us to do... ANYTHING. 
 *  As long as you have *handwaving* IMAGINATION *handwaving*
 *  We can change array sizes, we can make newfunctions,
 */

#include <stdio.h>
#include <stdlib.h>

//  Make a function which doubles the array for us, and frees the old memory
//  takes a pointer to a pointer for the array, and a pointer to the size
//  as it will change
void double_alloc(int ** arr, int * size);

int main(int argc, char *argv[])
{

	int arr_size = 15;
	int * my_array = malloc(arr_size*sizeof(int));
	int i = 0;
	for (i = 0; i < arr_size; i++)
	{
		my_array[i] = i * i + 3;
	}
	
	for (i = 0; i<arr_size; i++)
	{
		printf("%d ", my_array[i]);	
	}
	printf("\n");
	
	double_alloc(&my_array, &arr_size); 	

	/*  OLD CODE FOR DOUBLING 
	//  Creating a pointer for the array values so we can resize	
	int * temp = my_array;
	//  Doubling gp
	my_array = malloc(arr_size * 2 * sizeof(int));

	//  We are copying the values over to the NEW! my_array	
	for (i = 0; i < arr_size; i++)
	{
		my_array[i] = temp[i];
	}

	arr_size *= 2;
	*/


	//  Free the rams, no memory leaks. No pre-orders	
	free(my_array);
	
	
	return 0;
}

void double_alloc(int ** arr, int * size)
{
	int * temp = *arr;
	*arr = malloc((*size) * 2 * sizeof(int));
	int i = 0;
	for (i = 0; i < *size; i++)
	{
		(*arr)[i] = temp[i];
	}
	free(temp);
	(*size) *= 2;
}
