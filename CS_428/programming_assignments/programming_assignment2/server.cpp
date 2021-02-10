// Server side C/C++ program to demonstrate Socket programming
// Source: https://www.geeksforgeeks.org/socket-programming-in-cc-handling-multiple-clients-on-server-without-multi-threading/
#include <stdio.h>
#include <string.h> //strlen
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>    //close
#include <arpa/inet.h> //close
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h> //FD_SET, FD_ISSET, FD_ZERO macros
#define PORT 18456
#define MAX_CLIENTS 30

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char const *argv[])
{
    char *message = "Connected to server \r\n";
    char x_before_y[34] = "X:Baptiste received before Y:Mike";
    char y_before_x[34] = "Y:Mike received before X:Baptiste";
    int server_socket;
    int addrlen, sd, valread, activity;
    int i, max_sd, new_socket, dest; 
    int both_received = 0;
    char buffer[1025];
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    fd_set readfds;

    int client_socks[MAX_CLIENTS];
    for (int i = 0; i < MAX_CLIENTS; i++)
    {
        client_socks[i] = 0;
    }

    struct sockaddr_in server_address, client_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (const sockaddr *)&server_address, sizeof(server_address)))
    {
        perror("Bind Failed");
        exit(EXIT_FAILURE);
    };

    listen(server_socket, 6);
    //accept the incoming connection

    addrlen = sizeof(server_address);
    puts("Waiting for connections ...");

    while (1)
    {
        //clear buffer
        memset(buffer, 0, sizeof(buffer));

        //clear the socket set
        FD_ZERO(&readfds);

        //add master socket to set
        FD_SET(server_socket, &readfds);
        max_sd = server_socket;

        //add child sockets to set
        for (i = 0; i < MAX_CLIENTS; i++)
        {
            //socket descriptor
            sd = client_socks[i];

            //if valid socket descriptor then add to read list
            if (sd > 0)
                FD_SET(sd, &readfds);

            //highest file descriptor number, need it for the select function
            if (sd > max_sd)
                max_sd = sd;
        }

        //wait for an activity on one of the sockets , timeout is NULL ,
        //so wait indefinitely
        activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);

        if ((activity < 0) && (errno != EINTR))
        {
            printf("select error");
        }

        //If something happened on the master socket ,
        //then its an incoming connection
        if (FD_ISSET(server_socket, &readfds))
        {
            if ((new_socket = accept(server_socket,
                                     (struct sockaddr *)&server_address, (socklen_t *)&addrlen)) < 0)
            {
                perror("accept");
                exit(EXIT_FAILURE);
            }

            //inform user of socket number - used in send and receive commands
            printf("New connection , socket fd is %d , ip is : %s , port : %d  \n", new_socket, inet_ntoa(server_address.sin_addr), ntohs(server_address.sin_port));

            //send new connection greeting message
            if (send(new_socket, message, strlen(message), 0) != strlen(message))
            {
                perror("send");
            }

            puts("Welcome message sent successfully");

            //add new socket to array of sockets
            for (i = 0; i < MAX_CLIENTS; i++)
            {
                //if position is empty
                if (client_socks[i] == 0)
                {
                    client_socks[i] = new_socket;
                    printf("Adding to list of sockets as %d\n", i);

                    break;
                }
            }
        }

        //else its some IO operation on some other socket
        for (i = 0; i < MAX_CLIENTS; i++)
        {
            sd = client_socks[i];

            if (FD_ISSET(sd, &readfds))
            {
                //Check if it was for closing , and also read the
                //incoming message
                if ((valread = read(sd, buffer, 1024)) == 0)
                {
                    //Somebody disconnected , get his details and print
                    getpeername(sd, (struct sockaddr *)&server_address, (socklen_t *)&addrlen);
                    printf("Host disconnected , ip %s , port %d \n", inet_ntoa(server_address.sin_addr), ntohs(server_address.sin_port));

                    //Close the socket and mark as 0 in list for reuse
                    close(sd);
                    client_socks[i] = 0;
                }

                else
                {
                    both_received++; //Increment flag which says whether a pair of messages has been received
                    buffer[valread] = '\0'; //set last char to NULL terminate
                    if(both_received % 2 == 0 ){ //Check if pair of messages received
                       if(buffer[7] == 'Y'){ // If last message received was from Y then we know x came first
                           send(client_socks[0], x_before_y, strlen(x_before_y), 0);
                           send(client_socks[1], x_before_y, strlen(x_before_y), 0);
                       }else{ // If last message came from X then we know Y came first
                           send(client_socks[0], y_before_x, strlen(y_before_x), 0);                           
                           send(client_socks[1], y_before_x, strlen(y_before_x), 0);
                       }
                        printf("Sent acknowledgment to both X and Y\n"); //Print acknowledgment
                    }
                }
            }
        }
    }
    close(server_socket);
    return 0;
}
