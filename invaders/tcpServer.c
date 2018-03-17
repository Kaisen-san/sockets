#include <stdio.h> 
#include <conio.h>
#include <winsock.h> 
#include <windows.h> //Repara que utilzaremos este header para utilizarmos a função Sleep(); 
//#include <sys/types.h>
//#include <sys/socket.h>
//#include <netinet/in.h>
//#include <arpa/inet.h>
//#include <netdb.h> 

WSADATA data; 
SOCKET winsock; 
SOCKADDR_IN sock; 

int main() { 
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

	if(bind(winsock,(SOCKADDR*)&sock,sizeof(sock))==SOCKET_ERROR){ 
		printf("Erro colocar utilizar a funcao BIND"); 
		return 0; 
	} 

	listen(winsock,1); 

	while((winsock = accept(winsock,0,0))==SOCKET_ERROR) 
	{ 
		Sleep(1); 
	} 

	printf("Cliente conectado!"); 
	getch();
	closesocket(winsock);
	WSACleanup();

	return 0; 
}
