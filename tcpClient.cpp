#include <sys/types.h>
#include <sys/socket.h>

sockaddr_in serverAddr;
sockaddr &serverAddrCast = (sockaddre &) serverAddr;

// tcp/ip socket
int socketFd = socket(AF_INET, SOCK_STREAM, 0);

bzero(&serverAddr, sizeof(serverAddr));
serverAddr.sin_family = AF_INET;
// host IP em formato decimal com pontos
inet_pton(AF_INET, serverName, serverAddr.sin_addr);
serverAddr.sin_port = htons(13);

connect(sockFd, serverAddrCast, sizeof(serverAddr));
	//... operações read e write no sockFd
shutdown(sockFd, 2);
close(sockFd);
