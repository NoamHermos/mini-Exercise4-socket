# mini-Exercise4-socket

https://github.com/NoamHermos/mini-Exercise4-socket.git

Exercise4 Socket practice:

## Modifications to the original code

I made a few small changes to the original code to add better logging. 

### UDP Python

**Client**: Added print statements to show the target IP and port before sending, and to confirm when the response is received.
**Server**: Added a print right before recvfrom() so it's clear the server is actively waiting for messages and not just stuck.

### UDP C++

**Client**: Added a cout before sendto() to show where the payload is being sent.
**Server**: Added a cout before recvfrom() to indicate the server is listening.

### TCP Python

**Client**: Added a print to confirm the connection was successful, and a quick instruction on how to exit the loop.
**Server**: Added prints to show exact server states (waiting for a new client to connect vs. waiting for data from an already connected client).

### TCP C++
**Client**: Added a cout after connect() to confirm the connection to the server is established.
**Server**: Added a cout before accept() to show that the server is open and waiting for a new client.