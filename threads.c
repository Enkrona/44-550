#include <stdio.h>
#include <pthread.h> 

/*
 *
 *  We are going to use pthread
 *
 *  a thread is multiple workers on a single core (processing unit) 
 *  Parallel is at the same time, Concurrent is "like" the same time 
 *  Share global memory and Source code, but not local memory
 *
 *  Also playing with pthread
 *  Threads should never be shared, and pass a pointer to one
 *
 *  We can time commands using !time then the execuatable
 *
 *  In the class example of the bitonic sort, the threaded ran 59x slower because creating 
 *  threads is very slow
 *
 */

// must be in the form of function pointer


void do_a_thing(void (*my_func) ());
void foo();
void bar();

void do_another_thing(int (*my_func) (int a));
int square(int x);
int cube(int x);

//  Playing with pThread
/*
* void pthread_create((pthread_t * thread, const pthread_attr_t *attr, void* (*thread_routine) (void * args)), void * args);
*
* //  Exiting a thread 
* void pthread_exit(void * return_val);
* 
* //  Joining a thread to some data
* void pthread_join(pthread_t thread, void ** retval);
*/

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


