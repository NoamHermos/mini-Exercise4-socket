// Server side UDP socket
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

using namespace std;
// The main Server function creates a UDP socket binds it to a port receives data prints it and sends a response
int main() {
    // define the port number on which the server will listen for incoming UDP packets
    const int server_port = 5555;
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }
    // define the server's address and initialize it to listen on all available network interfaces with the specified port number
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);

    // bind the socket to the specified address and port number so that it can receive incoming UDP packets
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding to socket");
    }

    // get buffer to receive the response from the client and store the sender's information
    struct sockaddr_in from;
    unsigned int from_len = sizeof(struct sockaddr_in);
    char buffer[4096];
    cout << "Waiting for incoming UDP message..." << endl; // Added: indicates the server is listening
    int bytes = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *) &from, &from_len);
    if (bytes < 0) {
        perror("error reading from socket");
    }

    // print the response received from the client and close the socket and send a response back to the client and close the socket
    cout << "The client sent: " << buffer << endl;

    int sent_bytes = sendto(sock, buffer, bytes, 0, (struct sockaddr *) &from, sizeof(from));
    if (sent_bytes < 0) {
        perror("error writing to socket");
    }

    close(sock);

    return 0;
}