# Client side code for TCP communication
# import socket module for TCP communication
import socket
# create a TCP socket AT_INET for IPv4 and SOCK_STREAM for TCP communication
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# define the destination IP address (localhost) and port number to connect to the server
dest_ip = '127.0.0.1'
dest_port = 12345
print(f"Successfully established TCP connection to {dest_ip}") # Added: connection confirmation
print("Type 'quit' to terminate the session.") # Added: user instruction
# connect the socket to the specified destination IP address and port number to establish a TCP handshake with the server
s.connect((dest_ip, dest_port))
# enter a loop to continuously send messages to the server and receive responses until the user types 'quit'
msg = input("Message to send: ")
while not msg == 'quit':
    # encode the message as bytes using UTF-8 encoding and send it to the server
    s.send(bytes(msg, 'utf-8'))
    # receive a response from the server and store it in the variable 'data'
    data = s.recv(4096)
    # decode the received raw bytes data to a string using UTF-8 encoding and print it
    print("Server sent: ", data.decode('utf-8'))
    # prompt the user to enter another message to send to the server or type 'quit' to exit the loop
    msg = input("Message to send: ")
# close the socket to terminate the TCP connection with the server
s.close()