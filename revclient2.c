#include<netinet/in.h>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>
#include<sys/types.h>

int main(){

        int sock = 0, valread;
	int x = 2;
        struct sockaddr_in serv_addr;
        char rev_string[20];
        char buffer[1024] = {0};
        sock = socket(AF_INET,SOCK_STREAM,0);
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        serv_addr.sin_port = htons(4200);

        if(connect(sock, (struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
        {
                printf("Connection failed\n");
                return -1;
        }
	while(x!=1){
        printf("Enter string:");
        scanf("%[^\n]s",rev_string);
        send(sock, rev_string, strlen(rev_string), 0);
        printf("string sent to server: %s\n", rev_string);
        valread= read(sock, buffer, 1024);
        printf("Response from server: %s\n",buffer);
	printf("enter 1 to exit\n");
	scanf("%d",&x);
	send(sock, (char)(x) , strlen((char)(x)), 0);
	}
        close(sock);
        return 0;
}

