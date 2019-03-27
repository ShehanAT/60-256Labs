/**

 
 
 */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <strings.h>


int main(int argc, char* argv[]) {
    
    int socket_serv, socket_client, addrSize, messageSize;
    struct sockaddr_in server, client;
    char clientMessage[10000];
    
    //Create the server socket.
    socket_serv = socket(AF_INET, SOCK_STREAM, 0);
    
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);
    
    
    //Associate an address with a socket.
    if (bind(socket_serv, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Bind error");
        return -1;
    }
    
    //Specifies a queue limit for incomming connections.
    listen(socket_serv, 3);
    
    //Have ongoing communication with client.
    while(1) {
        printf("Waiting for connection...\n");
        addrSize = sizeof(struct sockaddr_in);
        
        //Accept incomming client connections.
        socket_client = accept(socket_serv, (struct sockaddr *)&client, (socklen_t*)&addrSize);
        
        //Prints an error if the connection could not be made.
        if (socket_client < 0) {
            printf("Could not connect to client.\n");
            return -1;
        }
        printf("Connection accepted.\n");
        
        //Reads the message from the client.
        while ((messageSize = read(socket_client, clientMessage, 1000)) > 0) {
            clientMessage[messageSize] = '\0';
            
            printf("Received command: %s\n", clientMessage);
            
            if (fork() == 0) {
                //Makes the socket an alias for the standard output.
                dup2(socket_client, STDOUT_FILENO);
                
                //Executes the given system call.
                execlp(clientMessage, clientMessage, (char *)0);
            }
            
        }
        
        //Prints a message if the client quits.
        if (messageSize == 0) {
            printf("Client disconnected.\n");
        }
    }
    
    //Closes the server and client sockets.
    close(socket_serv);
    close(socket_client);
    
    return 0;
}

