#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//  Global variable -- bad idea! 
int bad_idea = 48;

int main (int argc, char * argv [])
{
	//  storing the current pid for testing if a process is a fork
	int pid_test = getpid(); 	

	//  RIP, throwing some forks in the program	
	int c = fork();  
	// returns the pid of child, or in our instance as the parent returns 0	
	
	//  Prints out the pid  -- unique across the entire system :) 
	printf("The process id is: %d \n", getpid());
	printf("The proces id of the fork is: %d\n", c);
	printf("The global var before changing is: %d\n", bad_idea);
	
	//  A fork copies the ENTIRE PROCESS STATE - nothing is different except for fork() pid
	srand(getpid()); 
	//  We must seed the random generated with a pid, because the time will be copied 
	//  Thus, we must put the srand() after the fork to ensure that the pid is the pid from 
	//  	the forked process. 
	//  We could also use time, but have a sleep(1) to sleep for one second to provide 
	//  	some different values to be feed in since the fork copies everything
	
	bad_idea += rand() % 100;
	printf("The random number generated is: %d\n", bad_idea);

	//  A process which is forked has to copy the entire process state (RAM, storage, etc)
	//  	heavy-weight threads
	//  A thread is a light-weight process that has its own process state
	

	//  IDK, I am just testing things out now
	if (getpid() == pid_test)
	{
		printf("This is the end of the parent process! \n");
	}
	
	else
	{
		printf("This is the end of the child process! \n");
	}
	

	return 0;
}
