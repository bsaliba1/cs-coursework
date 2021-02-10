// Client side C/C++ program to demonstrate Socket programming 
#include <stdio.h> 
#include <iostream>
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#include <string>


#define PORT 18456

int main(int argc, char const *argv[]) 
{ 
	int network_socket;
	network_socket = socket(AF_INET, SOCK_STREAM, 0);

	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(PORT);
	server_address.sin_addr.s_addr = INADDR_ANY;

	int connection_status;
	connection_status = connect(network_socket, (const sockaddr*) &server_address, sizeof(server_address));
	if(connection_status == -1){
		printf("Could not connect to server\n");
	}

	char* client_message = "Client X: Baptiste";
	size_t size_m = 256;
	char server_response[256];
	memset(server_response, 0, sizeof(server_response));
	recv(network_socket, &server_response, sizeof(server_response), 0);
	printf("%s\n", server_response);

	while(1){
		printf("> ");
		std::string in;
		getline(std::cin, in); 
		send(network_socket, client_message, sizeof(client_message), 0);
		if(strcmp(client_message, "Bye")==0){
			break;
		}
		recv(network_socket, &server_response, sizeof(server_response), 0);
		printf("%s\n", server_response);
	}

	close(network_socket);
	return 0;
}