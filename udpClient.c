#include <sys/types.h>
#include <sys/socket.h>

int socketId = socket(AF_INET, SOCK_DGRAM, 0);

sockaddr_in, serverAddr, clientAddr;
sockaddr &serverAddrCast = (sockaddr &) serverAddr;
sockaddr &clientAddrCast = (sockaddr &) clientAddr;

// especifica o endereço e porta do servidor
serverAddr.sin_family = AF_INET;
serverAddr.sin_port = htons(serverPort);
struct hostent *hp = gethostbyname(hostName);
memcpy((char*)&serverAddr.sin_addr, (char*)hp->h_addr, hp->h_length);

// não é necessario fazer bind se não for peer-to-peer
int size = sizeof(clientAddr);
sendto(socketId, buffer, bufferSize, 0, clientAddrCast, &size);

recvfrom(socketId, buffer, bufferSize, 0, clientAddrCast, size);

close(socketId);
