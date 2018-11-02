#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>


//  some stuff we need
int sock;
int client;

void handler(int sig)
{
	close(sock);
	clone(client);
	exit(0);
}


int main(int argv, char * argc [])
{
	//  looking at BSD implementation! 
	//  For a server we need to:
	//  	* Create a socket
	//  	* Bind to a port
	//  	* Listen on that address and port
	//  	* Send/Recieve data on the socket
	
	// int listen(int sockfd, int backlog);
	// int accept(int sockfd, struct sockaddr * addr, socklen_t * addrlen);
	
	//  Creating the socket
	sock = socket(AF_INET, SOCK_STREAM, 0);
	signal(SIGINT, handler);
	int i;
	char data[256] = {};
	struct sockaddr_in my_address;
	//  Getting our address
	my_address.sin_family = AF_INET;
	//  Specifiying the port
	my_address.sin_port = htons(9999);
	printf("Port is %d\n", my_address.sin_port);
	//  Allow connecin from any port
	my_address.sin_addr.s_addr = INADDR_ANY;
	
	//  Error checking
	if (sock == -1)
	{
		printf("Error creating socket. Exiting! \n");
		exit(1);	
	}
	
	if (bind(sock, (struct sockaddr *) &my_address, sizeof (struct sockaddr_in)) == -1)
	{
		printf("Error binding the socket!\n");
		close(sock);
		exit(1);
	}
	
	//  Now start listening
	if (listen(sock, 10) == -1)
	{
		//  If more than 10 people try to connect
		printf("Listening errored, exiting!\n");
		close(sock);
		exit(1);
	}
	
	//  OPEN THE GATES - (allow someone)
	client = accept(sock, NULL, NULL);
	//  Creating vars for input
	char * input = calloc(100, sizeof(char));

	size_t readin = 100; //  How much data we can read in
	while(1)
	{	
		//  Reading in data from the client
		read(client, data, 256);
		printf("Server recieved: %s\n", data);
		getline(&input, &readin, stdin);
		//  Write the input from client and send the null char
		write(client, input, strlen(input) + 1);
	}	
	
	//  Close the connections/sockets
	close(sock);
	close(client);
	

	return 0;
}
