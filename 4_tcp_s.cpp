// Server side code for TCP communication
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

using namespace std;
// The main Server function creates a TCP socket binds it to a port listens for incoming connections
int main() {
    // define the port number and create a TCP socket with AF_INET for IPv4 and SOCK_STREAM for TCP communication
    const int server_port = 5555;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }
    // define the server's address structure and initialize it to listen on all available network interfaces
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);

    // bind the socket to the specified address and port for incoming TCP connections
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }
    // listen for incoming TCP connections with a backlog of 5 waiting connections
    if (listen(sock, 5) < 0) {
        perror("error listening to a socket");
    }
    // accept an incoming TCP connection and store the client's address information
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    cout << "Waiting for a new TCP client to connect..." << endl; // Added: waiting for connection handshake
    int client_sock = accept(sock,  (struct sockaddr *) &client_sin,  &addr_len);

    // error accepting the client connection
    if (client_sock < 0) {
        perror("error accepting client");
    }
    // get buffer to receive the response from the client and store the sender's information
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
    // connection is closed
    }
    else if (read_bytes < 0) {
    // error
    }
    else {
        cout << buffer;
    }
    // send a response back to the client and close the socket
    int sent_bytes = send(client_sock, buffer, read_bytes, 0);

    if (sent_bytes < 0) {
        perror("error sending to client");
    }

    close(client_sock);
    close(sock);


    return 0;
}