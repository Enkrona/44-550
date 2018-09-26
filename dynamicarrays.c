#include <stdio.h>
#include <stdlib.h>

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
	
	

	return 0;
}
