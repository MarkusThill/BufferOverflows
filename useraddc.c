//Markus Thill
//20.05.2010
//
//Dieses Programm legt auf einem UNIX-System einen User mit dem //"markus" und dem Passwort "markus87" an. Hierzu wird die //Systemfunktion execve() verwendet!

#include <stdio.h>

void main() {
   char *name[5];
   name[0] = "/usr/sbin/adduser";
   name[1] = "markus";
   name[2] = "-p";
   name[3] = "$1$7ÏvÙLKÏµ$gSUKG6RALzRA8ryROcTsG0";
   name[4] = NULL;
   execve(name[0], name, NULL);
}
