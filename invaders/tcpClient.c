#include <stdio.h>
#include <winsock.h>
#include <conio.h>

WSADATA data;
SOCKET winsock;
SOCKADDR_IN sock;

int main(){
	if(WSAStartup(MAKEWORD(1,1),&data)==SOCKET_ERROR){
		printf("Erro ao inicializar o winsock");
		return 0;
	}

	if((winsock = socket(AF_INET,SOCK_STREAM,0))==SOCKET_ERROR){
		printf("Erro ao criar socket");
		return 0;
	}

	sock.sin_family=AF_INET;
	sock.sin_port=htons(1234);
	sock.sin_addr.s_addr=inet_addr("127.0.0.1");

	if(connect(winsock,(SOCKADDR*)&sock,sizeof(sock))==SOCKET_ERROR){
		printf("Erro ao se conectar");
		return 0;
	}

	printf("Conectado!");
	getch();
	closesocket(winsock);
	WSACleanup();

	return 0;
}
