#include <stdio.h> 
#include <time.h>
#include <stdlib.h>
/*
 *  Pass by value (pbv) vs. Pass by reference (pbr)
 *  In the swap example, the space for the variables is saved in the call stack
 *    It is in the entry which is the call stack
 *  PBV: 
 *  	When we call a method, swap(a,b) has space for variables a,b
 *  	  It takes the value of the variable and copies it to the parameter 
 *  	  every time we call it it is copied to swap(a,b) memory locations 
 *      In the EX form class: the temp is allocated space
 *    	  And the swap occurs
 *     	  When we return, it pops the swap(a,b) from the call stack and the copies
 *     	  are erased
 *     This is done in Java, among other languages
 *  PBR: 
 *  	When we call the method in C, like in our example using pointers
 *  	using swap(&a, &b)
 *  		When called, a is not an int in the stack in the swap memory area,
 *  		but rather it is a pointer refering to the locaion in main where
 *  		the actual value resides
 *		
 *		We can think of this by drawing an arrow to the memory location that 
 *		(a) and (b) are residing
 *
 *		Logically, it follows the pointer  to the location, and makes changes
 *		in the actual memory location it is at. Thereby changing the 
 *		actual value. 
 *			When passing a class in Java it uses PBR
 *	
 */

/*
 * Reasoning:
 * 	streamlining
 * 		- changing values of parameters,
 * 		- passed a struct (but it has a lot of values) and needing to modify 
 * 		  the values is quick. 
 */

void swap(int *a, int *b);
void shuffle(int arr[], int size);
void sort(int arr[], int size);
void printarray(int arr[], int size);


int main(int argc, char* argv[]) 
{
	int my_array [] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	printarray(my_array, 9);
	shuffle(my_array, 9);
	printarray(my_array, 9);
	sort(my_array, 9);
	printarray(my_array, 9);

}

void swap(int *a, int *b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}

void shuffle(int arr[], int size)
{
	// Fisher gates shuffle 
	int nextidx;
	for (int i=0; i<size-1; i++)
	{
		nextidx = rand() %(size - i);
		//  gets the addr of the idx, and the nextidx + i, and swaps them
		swap(&arr[i], &arr[i+nextidx]);
	}
}

void sort(int arr[], int size)
{
	//  Bubble sort
	for (int i=0; i<size-1; i++)
	{
		for (j=0; j<size-1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				swap(&arr[j], &arr[j+]);
			}
		}
	}
}

void print_arr(int arr[], int size)
{
	for (int i=0; i<size; i++)
	{
		prrintf("%d ", arr[i]);
	}
	printf("\n");
}
