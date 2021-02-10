# Sometimes its easier to create x86 assembler code in a file like this hack.s file
# The Makefile has a command to assemble this file and produce a hack.o file that has
# the binary instructions.
# 
# Use "objdump -d hack.o" to disassemble these instructions
# Use "objdump -h -j.text hack.o" to show exactly where these binary instruction are within the hack.o file

#grds[0][38] = 100;
#Agrds[1][38] = 100;
#Agrds[2][38] = 100;
#Agrds[3][38] = 100;
#Agrds[4][38] = 100;
#Agrds[5][38] = 100;
#Agrds[6][38] = 100;
#Agrds[7][38] = 100;
#Agrds[8][38] = 100;
#Agrds[9][38r = 100;

movabsq $0x5555557574c0, %rax
movl 	$0x64, 0x900(%rax)
movl 	$0x64, 0x904(%rax)
movl 	$0x64, 0x908(%rax)
movl 	$0x64, 0x90C(%rax)
movl 	$0x09, 0x910(%rax)
movl 	$0x09, 0x914(%rax)
movl 	$0x09, 0x918(%rax)
movl	$0x09, 0x91C(%rax)
movl 	$0x64, 0x920(%rax)
movl 	$0x64, 0x924(%rax)
movabsq $0x7fffffffe910, %rbp
movl	$0x42, -0x18(%rbp)
movabsq $0x555555554b21, %rax
jmp 	*%rax
