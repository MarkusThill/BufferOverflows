//Markus Thill
//26.05.2010
//Dies ist der Client des in der Ausarbeitung vorgestellten //Netzwerkdienstes. Mit diesem Client kann sich über den Port //7777 mit dem entsprechenden Server verbunden  und Daten an //diesen übertragen werden.

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

int main(int argc, char *argv[])
{
	int sock, run, r;
	char buf[BUF_SIZE];
	struct sockaddr_in server;
	struct hostent *hp;
	if(argc != 2)
	{
		fprintf(stderr, "usage: client <hostname> \n");
		exit(2);
	}

	/* Socket anlegen */
	sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock < 0)
	{
		perror("open stream socket");
		exit(1);
	}
	server.sin_family = AF_INET;

	/* Hole Internet-Host-Adresse des Clients die per 	Kommandozeilenargument übergeben wurde*/
	hp = gethostbyname(argv[1]);
	if(hp == NULL)
	{
		fprintf(stderr,"%s unknown host.\n",argv[1]);
		exit(2);
	}

	/* Internet-Adresse zu der Server-Adresse kopieren*/
	bcopy(hp->h_addr, &server.sin_addr, hp->h_length);

	/* Port setzen */
	server.sin_port = htons(PORT);

	/*Verbindung öffnen*/
	if(connect(sock,&server,sizeof(struct sockaddr_in)) < 0)
	{
		perror("connecting stream socket");
		exit(1);
	}

	/* Lese Eingabe von STDIN*/
	while(run=read(0,buf,BUF_SIZE))
	{
		fprintf(stdout, "%s", buf);
		if(run<0)
		{
			perror("error reading from stdin");
			exit(1);
		}
		
		/* Schreibe gelesenen Puffer in den Stream*/
		if(write(sock,buf,run) < 0)
		{
			perror("writing on stream socket");
			exit(1);
		}
	}
	close(sock);
}