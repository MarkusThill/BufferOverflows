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

void fc() {
   char *name[2];
   name[0] = "/bin/sh";
   name[1] = NULL;
   execve(name[0], name, NULL);
}

void calc(char *str) {
	char buff[512];
	strcpy(buff, str);
	buff[0] = buff[0];
}

int main(int argc, char *argv[]) {
	char text[1024], ed[2];
	int listenfd, connfd;
	struct sockaddr_in serveraddr;
	ssize_t n;

	if(argc>1)
		calc(argv[1]);

	listenfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl (INADDR_ANY);
	serveraddr.sin_port = htons (PORT);

	bind(listenfd, (SA *) &serveraddr, sizeof(serveraddr));

	listen(listenfd, LISTENQ);
	for( ; ;) {

		connfd = accept(listenfd, (SA *) NULL, NULL);

		do {
			write(connfd, "\nEingabe:\n", 10);
			n = read(connfd, text, sizeof(text) - 1);
			text[n] = 0;

			calc(text);
			write(connfd, "\nGedreht:\n", 10);
			write(connfd, text, strlen(text));

			printf("\n\n%d\n\n", text[0]);
			} while(text[0] != '!');

		close(connfd);
	}
	return 0;
}
