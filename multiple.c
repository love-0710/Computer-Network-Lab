#include<stdio.h>
#include<string.h>
#include<sys/time.h>
#include<sys/socket.h>
#include<errno.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<netinet.h>



#define TRUE 1;
#define FALSE 0;
#define PORT 8888;

int main(Int argc, char*argv[]){
	int opt = TRUE;
	int master_socket, addrlen,new_socket,client_socket[30];
	max_clients = 30,activity,i,valread,sd;
	int max_sd;
	struct sockaddr_in address;
	
	char buffer[1025];
	fd_set readfds;
	char*message = "Hello from server!!\r\n";
	for(i = 0;i<max_clients;i++)
	{
		client_socket[i] = 0;
	}
	
	if((master_socket = socket(AF_INET,SOCK_STREAM,0))==0)
	{
		perror("SOCKET FAILED");
		exit(EXIT_FAILURE);
	}
	
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);
	if(bind(master_socket,(struct sockaddr*)&address,sizeof(address))<0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	printf("LISTENER on port %d \n", PORT);
	if(listen(master_socket,3)<0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}
	addrlen = sizeof(address);
	puts("waiting for connections....");
	while(TRUE){
		FD_ZERO(&readfds);
		FD_SET(master_socket,&readfds);
		max_sd = master_socket;
		for(i=0;i<max_clients;i++){
			sd = client_socket[i];
			if(sd>0)
				FD_SET(sd, &readfds);
			if(sd>max_sd)
				max_sd=sd;
			}
	activity = select(max_sd+1,&readfds,NULL,NULL,NULL);
	if((activity<0)&&(errno!=EINTR))

		printf("SELECT ERROR");
	}
	if(FD_ISSET(master_socket,&readfds))
	{
		if((new_socket=accept(master_socket,(struct sockaddr*)&address,(socklen_t*)&addrlen))<0)
		{
			perror("accept");
			exit(EXIT_FAILURE);
		}
		printf("NEW connection,socket fd is %d ,ip is: %s,port: %d\n",new_socket,inet_ntoa(address.sin_addr),ntohs(address.sin_port));
		if(send(new_socket,message,strlen(message),0!=strlen(message))
		{
			perror("send");
		}
		puts("Welcome message sent successfully!!");
		for(i =0;i<max_clients;i++)
		{
			if(client_socket[i] == 0)
				{
					client_socket[i] = new_socket;
					 
	
		

