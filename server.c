#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdbool.h>

int main(){
	struct sockaddr_in server, client;
	int sd, nsd, clientLen;
	bool result;
	sd=socket(AF_INET,SOCK_STREAM,0);
	server.sin_family=AF_INET;    
	server.sin_addr.s_addr=INADDR_ANY; 
	server.sin_port=htons(5555);
	bind(sd,(struct sockaddr *)&server,sizeof(server));
	listen(sd,5);	     
	write(1,"Waiting for Client to connect\n",sizeof("Waiting for Client to connect\n"));
	while(1){
		clientLen = sizeof(client);
		nsd=accept(sd,(struct sockaddr *)&client,&clientLen);

		write(1,"Connected to the client\n",sizeof("Connected to the client\n"));
		if(!fork()){
			close(sd);
			write(nsd,"Hi Client, I'm the child process\n",sizeof("Hi Client, I'm the child process\n"));
			exit(0);
		}
		else{
			close(nsd);
		}
	}
	return 0;
}
