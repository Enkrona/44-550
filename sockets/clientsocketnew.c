#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <netdb.h>

//  some stuff we need
int sock;

void handler(int sig)
{
	close(sock);
	exit(0);
}


int main(int argv, char * argc [])
{
	//  Creating the socket
	sock = socket(AF_INET, SOCK_STREAM, 0);
	signal(SIGINT, handler);
	int i;
	char data[256] = {};
	struct sockaddr_in server;
	//  Getting our address
	server.sin_family = AF_INET;
	//  Specifiying the port
	server.sin_port = htons(9999);
	printf("Port is %d\n", server.sin_port);
	

	// getting the network info about a host - hostname
	struct hostent * host;
	host = gethostbyname(argc[1]);
		
	//  If a host does not exxist
	if (!host)
	{
		printf("Host not found. Exiting!");
		exit(1);
	}
	
	//  Error checking
	if (sock == -1)
	{
		printf("Error creating socket. Exiting! \n");
		exit(1);	
	}
	
	//  Copies the info from the hostdb lookup to the address info
	memcpy(&server.sin_addr, host->h_addr, host->h_length);
	
	if (connect(sock, (struct sockaddr *) &server, sizeof (struct sockaddr_in)) == -1)
	{
		printf("Error connecing to the socket!\n");
		close(sock);
		exit(1);
	}
	
	
	//  Creating vars for input
	char * input = calloc(100, sizeof(char));

	size_t readin = 100; //  How much data we can read in
	while(1)
	{	
		getline(&input, &readin, stdin);
		write(sock, input, strlen(input) + 1);
		//  Reading in data from the client
		read(sock, data, 256);
		printf("Client recieved: %s\n", data);
	}	
	
	//  Close the connections/sockets
	close(sock);
	

	return 0;
}
