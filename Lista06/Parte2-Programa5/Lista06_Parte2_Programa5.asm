#Programa 5 - Lista 06 
#x->s0
#y->s1
#z->s2

#inicio

.text	
.globl main
main:
	#inserção de variaveis
        # 100 000 base 10 = 0000 0000 0000 0001 1000 0110 1010 0000 (0x000186a0)
        ori $s0,$zero,0x0001 #x=0x00000001
        sll $s0,$s0,16 #x=0x00010000
        ori $s0,$s0,0x86a0 #x=0x000186a0
        
        # 200 000 base 10 = 0000 0000 0000 0011 0000 1101 0100 0000 (0x00030d40)
        ori $s1,$zero,0x0003 #y=0x00000003
        sll $s1,$s1,16 #y=0x00030000
        ori $s1,$s1,0x0d40 #y=0x00030d40
    
    add $s2,$s0,$s1 # z=x+y
	
.data

#fim