# Server side code for TCP communication
# import socket module for TCP communication
import socket
# create a TCP socket AT_INET for IPv4 and SOCK_STREAM for TCP communication
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# empty string for binding all available interfaces to allow receiving data from any source IP address
server_ip = ''
# define the source port number to bind the socket to, allowing it to listen for incoming data on that port
server_port = 12345
# bind the socket to the specified source IP address and port
server.bind((server_ip, server_port))
# listen for incoming connections allowing a backlog of 5 connections to be queued before the server rejecting new connections
server.listen(5)
# enter an infinite loop to continuously listen for incoming connections and handle them
while True:
    print("Waiting for a new TCP client to connect...") # Added: waiting for connection handshake
    # handshake with the client and accept the incoming connection and store the client's socket info
    client_socket, client_address = server.accept()
    # print the client's address information to indicate that a new connection has been established
    print('Connection from: ', client_address)
    # receive data from the client and store it in the variable 'data' (size of 1024 bytes)
    data = client_socket.recv(1024)
    print("Waiting for data from the connected client...") # Added: waiting for data payload
    # enter a loop to continuously receive data from the client until the client disconnects by sending an empty message
    while not data.decode('utf-8') == '':
        # decode the received raw bytes data to a string using UTF-8 encoding and print it
        print('Received: ', data.decode('utf-8'))
        # send the received data back to the client in uppercase
        client_socket.send(data.upper())
        # receive the next chunk of data from the client
        data = client_socket.recv(1024)
    # print a message indicating that the client has disconnected
    print('Client disconnected')
    # close the client's socket to allow new incoming connections
    client_socket.close()