#Programa 6 - Lista 06 
#x->s0
#y->s1
#z->s2

#inicio

.text	
.globl main
main:
	#inserção de variaveis
        # maior numero inteiro possivel em 32 bits é 0x7FFFFFFF uma vez que o bit mais significativo é de sinal
        ori $s0,$zero,0x7fff #x=0x00007FFF
        sll $s0,$s0,16 #x=0x7FFF0000
        ori $s0,$s0,0xffff #x=0x7FFFFFFF
        
        # 300 000 base 10 = 0000 0000 0000 0100 1001 0011 1110 0000 (0x000493e0)
        ori $s1,$zero,0x0004 #y=0x00000004
        sll $s1,$s1,16 #y=0x00040000
        ori $s1,$s1,0x93e0 #y=0x000493e0

        #calculo de 4y
        sll	$t0,$s1,2 # $t0 = $s1 << 2 (t0=4*y)
        
    
    sub $s2,$s0,$s1 # z=x-4y
	
.data

#fim