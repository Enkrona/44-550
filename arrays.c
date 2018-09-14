#include <stdio.h>

//  Arrays in C are just like those in Java, fixed size, contigous, 0 index, etc.
//  Except they do no keep track of length! 

int main (int argc, char* argv[])
{
	//  Creating an array of size 5
	const ARRAY_SIZE = 5;
	int my_array[ARRAY_SIZE];
	int i;
	for (; i < ARRAY_SIZE; i++)
	{ 
		printf("%d \n", my_array[i];	
	}

	//  Array EX 2: 
	double another_aray[4] = {1.0, 2.0, 3.0, 4.0};
	int and_another[] = {1, 2, 3, 4};
	//  Size is 5
	int one_more[4] = {1, 2};
	//  contians [1, 2, 0, 0] 

	//  In class example 3:
	int ages [5];
	ages[0] = 10;
	ages[1] = 24;
	ages[3] = 42;
	ages[4] = 17;
	//  Ages would appears as ages = [10, 24, 30, 42, 17]
	

	//  working! 	
	for (int i=0; i <5; i++)
	{
		printf("%d ", ages[i]);
		printf("\n"); 	

	}	
	
	//  If we were to specify a ages[5] = 15; but did not change the size of the array,
	//  and we change the for loop to be i < 6, then:  
	//  it will naturally creep into the next memory address where it would see 
	//  i, which would be 5
	
	//  If we change the for loop iterator to "i < 1000", we would encounter a
	//  " Segmentation fault" which is when the program tries to read memory it
	//  does not own.

	//  Functions can take arrays as a parameter, any changes to the array contents whilst
	//  in the function, it is changing the original data. To address this, you can pass 
	//  the function a CONST_ARRAY. This way it cannot change the data! 	
	
	

	return 0;
}



