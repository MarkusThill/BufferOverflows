//Markus Thill
//25.05.2010
//Dieses Programm besitzt eine "geheime" Funktion, die im //Regelfall nie ausgeführt wird. Durch einen Buffer-Overflow kann //der Programmfluss jedoch so manipuliert werden, dass die //Funktion geheim() dennoch ausgeführt wird.

#include <stdio.h>
#include <string.h>
#include <unistd.h>

void geheim(void)
{
	printf("\n\nHallo!!!\n\n");
	exit(0);
}

void oeffentlich(char *args) 
{
	char buff[7];
	strcpy(buff, args);
}

int main(int argc, char *argv[])
{
	if(argc < 2)
		return 1;
	oeffentlich(argv[1]);

	printf("\ngeheim: (%p) \n", geheim);
	return 0;
}
