#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void batter(int sig);



int main(int argc, char* argv[])
{
	//  have the parent process send pitches processes to the child and the child do
	//  	something with the signal
	
	//  Forking the current process
	int cpid = fork();	
	if (cpid == 0)
	{
		//  if in the child process setup the signal handler
		signal(SIGUSR1, batter);
		while(1);
	}
	
	else
	{
		//  Sending nine pitches
		int i = 0;
		sleep(1);
		for (i; i < 10; i++)
		{
			sleep(1);
			kill(cpid, SIGUSR1);
		}		
	}
	
	sleep(1);
	return 0;


}

void batter(int sig)
{	
	//  For now it is just a strike, one processes sending another signals
	printf("STRIKE!\n");
}

