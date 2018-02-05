#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>


#define PORT 7777
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
	int sock, run, r;
	char buf[BUF_SIZE];
	struct sockaddr_in server;
	struct hostent *hp;
	if(argc != 2)
	{
		fprintf(stderr, "usage: client <hostname> \n");
		exit(2);
	}

	/* create socket */
	sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock < 0)
	{
		perror("open stream socket");
		exit(1);
	}
	server.sin_family = AF_INET;

	/* get internet address of host specified by command line */
	hp = gethostbyname(argv[1]);
	if(hp == NULL)
	{
		fprintf(stderr,"%s unknown host.\n",argv[1]);
		exit(2);
	}

	/* copies the internet address to server address */
	bcopy(hp->h_addr, &server.sin_addr, hp->h_length);

	/* set port */
	server.sin_port = htons(PORT);

	/* open connection */
	if(connect(sock,&server,sizeof(struct sockaddr_in)) < 0)
	{
		perror("connecting stream socket");
		exit(1);
	}

	/* read input from stdin */
	while(run=read(0,buf,BUF_SIZE))
	{
		fprintf(stdout, "%s", buf);
		if(run<0)
		{
			perror("error reading from stdin");
			exit(1);
		}
		
		/* write buffer to stream socket */
		if(write(sock,buf,run) < 0)
		{
			perror("writing on stream socket");
			exit(1);
		}
	}
	close(sock);
}
