#include <signal.h>
#include <stdio.h>


void dennis(int signal);

int main(int argc, char * argv [] )
{
	//  Need to pass it two pieces of information, sig handler and action
	signal(SIGINT, dennis);
	
	//  Sending signals to processes
	//  Creating a fork and storing the pid
	int cpid = fork();
	//  Here we send the SIGTERM sigal to the process we forked
	kill(cpid, SIGINT);

	while(1);

	return 0;

}


void dennis(int signal)
{
	printf("Ah ah ah, you didn't say the magic word!\n");
}


