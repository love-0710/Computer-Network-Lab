#include<netinet/in.h>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>
#include<sys/types.h>

int main(){

	int sock = 0, valread;
	struct sockaddr_in serv_addr;
	char palindrome_string[20];
	char buffer[1024] = {0};
	sock = socket(AF_INET,SOCK_STREAM,0);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = "192.168.10.30";
	serv_addr.sin_port = htons(8888);
	
	if(connect(sock, (struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
	{
		printf("Connection failed\n");
		return -1;
	}
	printf("Enter string:");
	scanf("%[^\n]s",palindrome_string);
	send(sock, palindrome_string, strlen(palindrome_string), 0);
	printf("string sent to server: %s\n", palindrome_string);
	valread= read(sock, buffer, 1024);
	printf("Response from server: %s\n",buffer);
	close(sock);
	return 0;
}
