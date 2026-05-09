# Client side code for UDP communication
# import socket module for UDP communication
from socket import socket, AF_INET, SOCK_DGRAM

# create a UDP socket AT_INET for IPv4 and SOCK_DGRAM for UDP communication 
s = socket(AF_INET, SOCK_DGRAM)

# define the destination IP address
# in this case, we use localhost IP to send data to the same machine
dst_ip = '127.0.0.1'
dst_port = 12345
print(f"Sending request to {dst_ip}:{dst_port}") # Added: confirmation before sending
# send a message 'Hello' to the specified destination IP and port
s.sendto(b'Hello', (dst_ip,dst_port))
# receive a response from the server 
# and store the data in the variable 'data' and the sender's information in 'sender_info'
data, sender_info = s.recvfrom(2048)
print("Received response from server:") # Added: indicates a response has been received
# decode the received raw bytes data to a string using UTF-8 encoding and print it
print(data.decode('utf-8'))
# print the sender's information (IP address and port number)
print(sender_info)
# close the socket
s.close()
