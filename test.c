#include <stdio.h>

int main(int argc, char* argv[])
{
	int a;
	short s;
	long l;
	float f;
	double d;
	

	// In class testing of conditionals 9-7-18	
	unsigned int temperature = -10;
	
	printf("Now processing a basic while loop. \n");
	int countup=0; 
	while (countup<10)
	{
		printf("%d\n", countup);
		countup++;	
	}
	
	printf("\nNext we are processing a do while loop. \n");	
	countup = 0;
	do 
	{
		printf("%d\n", countup);
		countup++;
	}
	while (countup < 10);

	if (temperature <  45)
	{
		printf("It is cold my dudes.\n");
	}	
	
	else if (temperature > 75)
	{
		printf("It is too hot my dudes.\n");
	}
	
	else
	{
		printf("It is JUST RIGHT my dudes.\n\n\n");
	}
	
	printf("\nNow processing a basic for loop. \n");
	int i = 0;
	for (; i<10; i++)
	{
		printf("%d\n", i);
	}

		
	// with an unsigned int use %u, in class we discovered that unsigned int -10 is the largest
	// value we can represent 	
	printf("The temperature outside is %u\n", temperature);
	
	printf("The size of an int is %d\n", sizeof(a));
	printf("The size of a short is %d\n", sizeof(s));
	printf("The size of a long is %d\n", sizeof(l));
	printf("The size of a float is %d\n", sizeof(f));
	printf("The size of a double is %d\n", sizeof(d));
	
	// These are some examples from class in 9/7 describing printfs
	printf("I am %d feet tall\n", 6);
	printf("My name is %s\n", "u wot m8?");
	printf(" %d %s %f\n", 42, "towel", 1.234);
	
	
	

	return 0;


}
