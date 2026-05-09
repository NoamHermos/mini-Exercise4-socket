# Server side code for UDP communication
# import socket module for UDP communication
from socket import socket, AF_INET, SOCK_DGRAM
# create a UDP socket AT_INET for IPv4 and SOCK_DGRAM for UDP communication
s = socket(AF_INET, SOCK_DGRAM)
# empty string for binding all available interfaces to allow receiving data from any source IP address
src_ip = ''
# define the source port number to bind the socket to, allowing it to listen for incoming data on that port
src_port = 12345
# bind the socket to the specified source IP address and port
s.bind((src_ip, src_port))
# enter an infinite loop to continuously listen for incoming data
while True:
    print("Waiting for incoming UDP message...") # Added: indicates the server is listening
    # receive data from any sender and store the data in the variable 'data' and the sender's information in 'sender_info'
    data, sender_info = s.recvfrom(2048)
    # decode the received raw bytes data to a string using UTF-8 encoding and print it
    print(data.decode('utf-8'))
    # print the sender's information (IP address and port number)
    print(sender_info)

    # send the received data back to the sender in uppercase
    s.sendto(data.upper(), sender_info)