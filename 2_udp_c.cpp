// Client side code for UDP communication
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

using namespace std;
// The main Client function creates a UDP socket sends prints the response and closes the socket
int main() {
    // define the destination IP address and port number to which the client will send data
    const char* ip_address = "127.0.0.1";
    const int port_no = 5555;
    // create a UDP socket using the socket() system call with AF_INET for IPv4 and SOCK_DGRAM for UDP communication
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }
    // define the server's address structure using sockaddr_in and initialize it with the destination IP address and port number
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);

    // define the data to be sent to the server and send the data to the server specified by the sockaddr_in structure
    char data[] = "hello";
    int data_len = sizeof(data);
    cout << "Sending 'hello' to: " << ip_address << ":" << port_no << endl; // Added: target info
    int sent_bytes = sendto(sock, data, data_len, 0, (struct sockaddr *) &sin, sizeof(sin));
    if (sent_bytes < 0) {
        perror("error writing to socket");
    }

    // get buffer to receive the response from the server and a sockaddr_in structure to store the sender's information
    struct sockaddr_in from;
    unsigned int from_len = sizeof(struct sockaddr_in);
    char buffer[4096];
    int bytes = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *) &from, &from_len);
    if (bytes < 0) {
        perror("error reading from socket");
    }
    // print the response received from the server and close the socket
    cout << "The server sent: " << buffer << endl;

    close(sock);

    return 0;
}