//  Pointers are just a memory address, not the actual value we want
/* 
 * Volunteer @address[1] 
 *
 *
 * Student is a person. 
 * Student A is the volunteer. 
 *
 * Student* volunteer  -- this is creating a variable called volunteer, which keeps the address of 
 *                        a student. [Student*]  is a 
 * Volunteer = &A; 
 *  & -- actually gets the address (same as addressOf)  
 *
 * volunteer = 17; 
 */

//  Pointers give us more specific and absolute locations for vars

/*
 * a = 6; its address in the ex: is "10" 
 * ptr = &a;  getting the address of the variable a, which is 10
 * ptr = 10; Which is the memory address
 * 
 *
 *
 *
 *
 */

#include <stdio.h>

void swap(int *a, int *b);


int main(int arc, char* argv[])
{
	//  We are just creating a variable here, the variable lives somewhere in RAM
	int a = 6;
	int b = 15;
	printf("%d\n", a);
	
	//  now printing the memory address (pointer) 
	printf("%d\n", &a);

	
	//  more examples!
	int * ptr;  //  This is a pointer for the int, where we are declaring the pointer
	ptr = &a;   //  Storing the address of a into the pointer. 
	printf("%d\n", *ptr);  // this says go to where the pointer is pointing and use that value
			       //  also known as following the pointer

	//  EX 2: Changing the value of a, and displaying the values
	printf("a = %d, *ptr = %d\n", a, *ptr);
	a = 10; 
	printf("a = %d, *ptr = %d\n", a, *ptr);
	printf("Address is: 0x%d\n", ptr); 

	//  EX 3: Changing the value of the pointer, and displaying the values 
	printf("b = %d, *ptr = %d\n", b, *ptr);
	*ptr = 42;
	printf("b = %d, *ptr = %d\n", b, *ptr);	

	//  EX 4: Returning different things form functions, and modifying values
	printf("a = %d, b= %d\n", a, b);
	printf("After swap: \n");
	swap(&a, &b);
	printf("a = %d, b= %d\n", a, b);

	return 0;


}

//  EX 4: Swapping two values/pointers? 
void swap(int *a, int *b)
{
	//  Standard swap code - but this wont work because it operates on a copy of 
	//  the values, not the original a, b
	/*
	 * int num1=6, num2=7;
         * int temp = num2;
	 * num2 = num1;
	 * num1 = temp;
	*/ 

	//  But we want to swap the values at &a, and &b
	int temppoint = *b;  //  assigning the temppoint the value of b
	*b = *a;	     //  follow the pointer of b, and assign a that value
	*a = temppoint;      //  take the value of temppoint and assign it to a
	
}
