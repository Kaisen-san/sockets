#include <sys/types.h>
#include <sys/socket.h>

int socketId = socket(AF_INET, SOCK_DGRAM, 0);

sockaddr_in serverAddr, clientAddr;
sockaddr &serverAddrCast = (sockaddr &) serverAddr;
sockaddr &clientAddrCast = (sockaddr &) clientAddr;

// permite conexões para qualquer endereço do host
serverAddr.sin_family = AF_INET;
serverAddr.sin_port = htons(serverPort);
serverAddr.sin_addr.s_addr = INADDR_ANY);

// associa o processo com a porta
bind(socketId, &serverAddrCast, sizeof(addr));

// recebe de um cliente
int size = sizeof(clientAddr);
recvfrom(socketId, buffer, bufferSize, 0, clientAddrCast, &size);

// envia para o cliente (o que acabou de enviar mensagem)
sendto(socketId, buffer, bufferSize, 0, clientAddrCast, size);

close(socketId);
