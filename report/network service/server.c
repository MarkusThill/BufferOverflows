//Markus Thill
//25.05.2010
//
//Dies ist der fehlerhafte Dienst, der in der Funktion calc() //keine Bereichsüberschreitungs-Prüfung vornimmt. Dadurch kann //eine Eingabe des Clients einen Buffer-Overflow auslösen. 

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define LISTENQ 1024
#define SA struct sockaddr
#define PORT 7777

/*Test-Funktion. Nicht weiter wichtig*/
void fc() {
   char *name[2];
   name[0] = "/bin/sh";
   name[1] = NULL;
   execve(name[0], name, NULL);
}

/*Fehlerhafte Funktion*/
void calc(char *str) {
	char buff[512];
	strcpy(buff, str);
}

int main(int argc, char *argv[]) {
	char text[1024], ed[2];
	int listenfd, connfd;
	struct sockaddr_in serveraddr;
	ssize_t n;
	
	//Testen der Funktion clac mit einem Kommandozeilenargument
	if(argc>1)
		calc(argv[1]);

	//Socket anlegen
	listenfd = socket(AF_INET, SOCK_STREAM, 0);

	//Server-Adresse initialisieren
	bzero(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl (INADDR_ANY);
	serveraddr.sin_port = htons (PORT);

	//Adresse an Socket binden
	bind(listenfd, (SA *) &serveraddr, sizeof(serveraddr));

	//Auf dem Port hören
	listen(listenfd, LISTENQ);
	for( ; ;) {

		//Lesen einer Eingabe
		connfd = accept(listenfd, (SA *) NULL, NULL);

		do {
			//Den Client zur Eingabe auffordern
			write(connfd, "\nEingabe:\n", 10);

			//Lesen der Client-Eingabe, sofern vorhanden
			n = read(connfd, text, sizeof(text) - 1);
			text[n] = 0;

			//Funktion mit dem Eingabepuffer aufrufen
			calc(text);
			//write(connfd, "\nGedreht:\n", 10);
			write(connfd, text, strlen(text));

			printf("\n\n%d\n\n", text[0]);
			} while(text[0] != '!');

		close(connfd);
	}
	return 0;
}
