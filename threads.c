#include <stdio.h>

/*
 *
 *  We are going to use pthread
 *
 *  a thread is multiple workers on a single core (processing unit) 
 *  Parallel is at the same time, Concurrent is "like" the same time 
 *  Share global memory and Source code, but not local memory
 */

// must be in the form of function pointer


void do_a_thing(void (*my_func) ());
void foo();
void bar();

void do_another_thing(int (*my_func) (int a));
int square(int x);
int cube(int x);


int main(int argc, char * argv [])
{
	// WIP
	do_a_thing(foo);
	do_a_thing(bar);
	do_another_thing(square);
	do_another_thing(cube);
	return 0;

}

void foo()
{
	
	printf("I'm in foo! \n");

}

void bar()
{
	printf("YARRRRRRRRR\n");
}

void do_a_thing(void (* my_func) ())
{
	my_func();
}

void do_another_thing(int(*my_func) (int a))
{
	my_func(4);
}

int square(int x)
{
	return x*x;
}

int cube(int x)
{
	return x*x*x;
}
