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

void do_a_thing(void * my_func(void));

int main(int argc, cahr* argv [])
{
	// WIP
	do_a_thing(foo);
	do_a_thing(bar);
	
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

void do_a_thing(void * my_func(void))
{

}
