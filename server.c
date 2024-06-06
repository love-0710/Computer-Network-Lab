#include<netinet/in.h>
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<unistd.h>
#include<sys/types.h>

int isPalindrome(char*str){
	int len = strlen(str);
	for(int i=0;i<len;i++)
	{
		if(str[i] != str[len-i-1])
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int server_fd, new_socket,valread;
	struct sockaddr_in address;
	int opt=1;
	int addrlen = sizeof(address);
	char buffer[1024] = {0};
	char *palindrome_reply="Palindrome\n";
	char *not_palindrome_reply = "Not a palindrome\n";
	
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	address.sin_family = AF_INET;
	address.sin_addr.s_addr= INADDR_ANY;
	address.sin_port = htons(4200);
	bind(server_fd, (struct sockaddr*)&address,sizeof(address));
	listen(server_fd, 3);
	new_socket = accept(server_fd,(struct sockaddr*)&address, &addrlen);
	valread = read(new_socket, buffer,1024);
	printf("Received string is: %s\n",buffer);
	if(isPalindrome(buffer)){
	send(new_socket, palindrome_reply,strlen(palindrome_reply),0);
	}
	else{
		send(new_socket, not_palindrome_reply,strlen(not_palindrome_reply),0);
		}
		printf("results sent to client\n");
	close(new_socket);
	close(server_fd);
	return 0;
}
