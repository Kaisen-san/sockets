#include <sys/types.h>
#include <sys/socket.h>

sockaddr_in serverAddr;
sockaddr &serverAddrCast = (sockaddr &) serverAddr;

// tcp/ip socket
int listenFd = socket(AF_INET, SOCK_STREAM, 0);

bzero(&serverAddr, sizeof(serverAddr));
serverAddr.sin_family = AF_INET;
// qualquer interface internet neste servidor
serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
serverAddr.sin_port = htons(13);

bind(listenFd, &serverAddrCast, sizeof(serverAddr));

listen(listenFd, 5);

for ( ; ; ) {
	int connectFd = accept(listenFd, (sockaddr *) NULL, NULL);
	//... operações read e write no connectFd
	shutdown(connectFd, 2);
	close(connectFd);
}
