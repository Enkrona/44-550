#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>



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

	return 0;
}
