#include<stdlib.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<stdbool.h>

int main(){
	struct sockaddr_in server;    
	int sd,msgLength;
	ssize_t readBytes;
	char buff[50];
	char result;

	sd=socket(AF_INET,SOCK_STREAM,0);
	server.sin_family=AF_INET;
	server.sin_addr.s_addr=inet_addr("127.0.0.1");
	server.sin_port=htons(5555);

	connect(sd,(struct sockaddr *)&server,sizeof(server));
	readBytes = read(sd, buff, sizeof(buff));
	if (readBytes == -1)
            perror("Error while reading from network via socket!");
        else
            printf("Data from Server: %s\n", buff);
	close(sd);
	return 0;
}
