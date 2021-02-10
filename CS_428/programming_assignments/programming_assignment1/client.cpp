/* 
	UDP Client
	CS_428
	Binghamton University

	@author: Baptiste Saliba
*/

#include <iostream>
#include <chrono>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 12000
#define SOCKET_READ_TIMEOUT_SEC 1

int main()
{
	int sockfd, n; // sockfd = socket description, n = return value
	char buffer[1024]; // read buffer
	struct sockaddr_in servaddr; // struct for server socket, specs are added at line 26

	memset(&servaddr, 0, sizeof(servaddr)); // 0 out servaddr

	/* Specifications for server */
	servaddr.sin_family = AF_INET; // IPv4
	servaddr.sin_addr.s_addr = INADDR_ANY; // localhost
	servaddr.sin_port = htons(PORT); // port number

	/* Create a UDP socket */
	sockfd = socket(AF_INET, SOCK_DGRAM, 0); // AF_INET: IPv4 protocol, SOCK_DGRAM: UDP(unreliable, connectionless)

	/* Set the read timeout */
	struct timeval timeout;	// Create timeout struct
	timeout.tv_sec = SOCKET_READ_TIMEOUT_SEC; // Assign timeout time seconds
	timeout.tv_usec = 0; // Assign timeout time microseconds
	setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)); // Set the SO_RCVTIMEO (recieve timeout) to the timeout struct we just created

	// Connect client to server
	// If return is -1 it means connection failed
	if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	};

	// Make 10 RTTs
	for (int i = 0; i < 10; i++)
	{
		// Start timer
		auto start = std::chrono::high_resolution_clock::now();

		// Send and Recieve
		send(sockfd, "Hello Server", strlen("Hello Server"), 0);
		n = read(sockfd, buffer, 1024);

		// Stop timer
		auto stop = std::chrono::high_resolution_clock::now();

		// If read fails it returns -1 so by checking if -1 we are checking if the packet was lost
		if (n != -1)
		{
			//Print RTT
			auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
			std::cout << "Round Trip Time: " << duration.count() << " microseconds" << std::endl;
		}
		else
		{
			std::cout << "Packet Lost" << std::endl;
		}
	}

	return 0;
}