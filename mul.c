#include<stdio.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/time.h>
#include<errno.h>


#define TRUE 1
#define FALSE 0
#define PORT 8888

int main(int argc, char *argv[]){
	int opt= TRUE;
	int master_socket,aadrlen,new_socket, client_socket[30], max_clients=30, activity,valread,sd;
	int max_sd;
	struct sockaddr_in address;
	char buffer[1025];
	
	fd_set readfds;
	
	char *message= "hello from server \r\n";
	
	for(int i=0;i<max_clients,i++){
		client_socket[i]=0;
		}
	
	if(master_socket= socket(AF_INET,SOCK_STREAM,0))==0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	
	}
	
	 address.sin_family = AF_INET;
        address.sin_addr.s_addr = INADDR_ANY;
        address.sin_port = htons(PORT);
        
        if(bind(master_socket, (struct sockaddr*)&address, sizeof(address))<0) {
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	
	printf("Listener on port %d\n",PORT);
	
	if(listen(master_socket, 3)<0) {
		perror("listen");
		  exit(EXIT_FAILURE);
	}
	
	addrlen=sizeof(address);
	puts("Waiting for connections....");
	
	while(TRUE)
	{
		FD_ZERO(&readfds);
		FD_SET(master_socket,&readfds);
		max_sd=master_socket;
		
		for(int i=0;i<max_clients;i++)
		{
			sd=client_socket[i];
			
			if(sd>0)
				FD_SET(sd,&readfds);
				
			if(sd>max_sd)
				max_sd=sd;
		}
		
		
	
	
	
	
	

