#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdbool.h>
#define PORT 4200
#define MAXLINE 1000

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

int main(){
	char *message = "Hello Client";
	char buffer[100];
        char *palindrome_reply="Palindrome\n";
        char *not_palindrome_reply = "Not a palindrome\n";
	int listenfd,len;
	struct sockaddr_in servaddr,cliaddr;
	bzero(&servaddr,sizeof(servaddr));
	listenfd = socket(AF_INET,SOCK_DGRAM,0);
	servaddr.sin_addr.s-addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);
	servaddr.sin_family = AF_INET;
	bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
	len = sizeof(cliaddr);
	int n = recvfrom(listenfd, buffer,sizeof(buffer),0,(struct sockaddr*)&cliaddr,&len);
	 printf("Received string is: %s\n",buffer);
        if(isPalindrome(buffer)){
         sendto(listenfd,not_palindrome_reply,MAXLINE,0,(struct sockaddr*)&cliaddr, sizeof(cliaddr));

        }
        else{
          	sendto(listenfd,not_palindrome_reply,MAXLINE,0,(struct sockaddr*)&cliaddr, sizeof(cliaddr));
		}
	printf("results sent to client\n");

	buffer[n] = '\0';
	puts(buffer);
	sendto(listenfd,message,MAXLINE,0,(struct sockaddr*)&cliaddr, sizeof(cliaddr));
}
