#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void ping(int sig);
void pong(int sig);

int cpid;

int main(int argc, char* argv[])
{
	//  have the parent process send something to the child and the child do
	//  	something with the signal
	
	//  Forking the current process
	cpid = fork();	
	if (cpid == 0)
	{
		//  if in the child process setup the signal handler
		//  It will call "ping" 
		signal(SIGUSR1, ping);
		while(1);
	}
	
	else
	{
		// Wait and then send the pong function and kill the child process
		sleep(1);
		signal(SIGUSR2, pong);
		kill(cpid, SIGUSR1); 
		while(1);		
	}
	
	sleep(1);
	//  Ending the child process, otherwise it will just stay running
	kill(cpid, SIGINT);
	sleep(1);
	return 0;


}

void ping(int sig)
{	
	//  For now it is just a strike, one processes sending another signal
	//  The counter for how many strikes have been striked? 
	printf("Ping!\n");
	//  when we recieve theping send a signal back to parent, but it returns 
	//  	the parent pid
	kill(getppid(), SIGUSR2);
}

void pong(int sig)
{
	printf("Pong!\n");
	sleep(1);
	//  An ACTUAL example of when using a global var is right/ok
	//  Sends signal back to the parrent process
	kill(cpid,SIGUSR1);
}


