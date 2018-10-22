#include <stdio.h>

int main()
{
	//  This is a demo of overrun. We are using a short which is 8 bits
	//  	this example seeks to display how overflow works by going past the 
	//  	complement of the variable, and will display a neg value.
	short s = 10000000;
	while (s > 0) s+=2;
	printf("%d\n", s);
	return 0;
}
