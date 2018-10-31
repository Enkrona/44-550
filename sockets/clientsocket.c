#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>

//  We are not creating a raw SOCKADDR struct
//struct sockaddr 
//{
	//  Should match the domain of the socket
//	sa_family_t sa_family;
//	char sa_data[14];
//}

int main(int argv, char * argc [])
{
	//  looking at BSD implementation! 
	
	//  Creating a IPV4, TCP, Socket
	int socket(AF_INET, SOCK_STREAM, 0);

	// client socket
	//int connect(int sockfd, const struct sockaddr * addr, socklen_t addrlen);
	//	returns 0 on success, and -1 on error
	
	// SENDING DATA:
	// size_t send(int sockfd, const void * bu, size_t len, int flags);
	// size_t write("same as above);
	
	
	// RECIEVE DATA:
	// size_t recv("same as above");
	
	return 0;
}
