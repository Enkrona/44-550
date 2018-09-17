#include <stdio.h>

//  There are no "safety nets", so if we input the wrong data type it will print out not so friendly
//  output. I.e. asking a user for an int then the user providing a char/string would output an int

int main ()
{
	//  We need to declare our variables that will bestoring data, and the array of chars is st
	char str [80];
	int i;
	

	//  ICE
	

	
	//  We are printing to the console then, asking the user for input. Stops at 79 chars to
	//  allow room for our null terminator 
	printf("Enter your last name: ");
	scanf("%79s", str);
	
	//  Same case as above, except for a number
	//  ALWAYS USE " & " WHEN READING IN FROM INTS!! 
	printf("Enteryour age: ");
	scanf("%d", &i);
	
	printf("Mr. %s , %d years old. \n", str, i);

	printf("Enter a hexadecimal number: ");
	scanf("%x", &i);
	
	printf("You have entered %#x (%d). \n", i, i);
	


	return 0;
}
