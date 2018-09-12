#include <stdio.h>
#include "header.h"

// funtion definitions
void greet(int id)
{
	printf("Gretings Agent %d\n" , id);

}

int foo()
{
	return bar();
}

int bar()
{
	return 24;
}
