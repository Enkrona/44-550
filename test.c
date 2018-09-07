#include <stdio.h>

int main(int argc, char* argv[])
{
	int a;
	short s;
	long l;
	float f;
	double d;

	printf("The size of an int is %d\n", sizeof(a));
	printf("The size of a short is %d\n", sizeof(s));
	printf("The size of a long is %d\n", sizeof(l));
	printf("The size of a float is %d\n", sizeof(f));
	printf("The size of a double is %d\n", sizeof(d));

	return 0;


}
