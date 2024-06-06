#include<netinet/in.h>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>
#include<sys/types.h>

void rev(char*str){
        int len = strlen(str);
        int i,j;
        char temp;
        for( i=0,j=len-1; i<j; i++,j--)
        {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
        }
}

int main()
{
        int server_fd, new_socket,valread;
        struct sockaddr_in address;
        int opt=1;
	int x = 2;
        int addrlen = sizeof(address);
        char buffer[1024] = {0};
        server_fd = socket(AF_INET, SOCK_STREAM, 0);
        address.sin_family = AF_INET;
        address.sin_addr.s_addr= INADDR_ANY;
        address.sin_port = htons(4200);
        bind(server_fd, (struct sockaddr*)&address,sizeof(address));
        listen(server_fd, 3);
        new_socket = accept(server_fd,(struct sockaddr*)&address, &addrlen);
	while(x!=1){
        valread = read(new_socket, buffer,1024);
        printf("Received string is: %s\n",buffer);
        rev(buffer);
        send(new_socket, buffer,strlen(buffer),0);
        printf("results sent to client\n");
	valread = read(new_socket, buffer,1024);
	x = *buffer;
	}
        close(new_socket);
        close(server_fd);
        return 0;
}

