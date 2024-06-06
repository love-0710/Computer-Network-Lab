#include<netinet/in.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>
#define PORT 4200

int main(int argc, char const* argv[])
{
        int server_fd,new_socket;
	int i;
        ssize_t valread;
        struct sockaddr_in address;
        int opt=1;
        socklen_t addrlen = sizeof(address);
        int a[5]={0};

        if((server_fd=socket(AF_INET, SOCK_STREAM, 0))<0){
                perror("Socket creation failed");
                exit(EXIT_FAILURE);
        }

        //if(setsockopt(server_fd,SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)){
        //}

        address.sin_family = AF_INET;
        address.sin_addr.s_addr= INADDR_ANY;
        address.sin_port =htons(PORT);

        if(bind(server_fd, (struct sockaddr*)&address, sizeof(address))<0) {
                perror("bind failed");
                exit(EXIT_FAILURE);
        }

        if(listen(server_fd, 3)<0) {
                perror("listen");
                  exit(EXIT_FAILURE);
        }

        if((new_socket =accept (server_fd, (struct sockaddr*)&address, &addrlen)) <0){
                perror("accept");
                 exit(EXIT_FAILURE);
        }
        valread = read(new_socket, a, 5*sizeof(int));
	int sum=0;
	
	for(i=0;i<5;i++)
	{	printf(" %d ",a[i]);
		sum = sum+a[i];
	}
	printf(" %d ", sum);
        send(new_socket, &sum, sizeof(int), 0);
        printf("sum sent\n");

        close(new_socket);

        close(server_fd);
        return 0;
}
