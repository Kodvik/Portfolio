#Programa 2 - Lista 06
#x->s0
#y->s1

#inicio

.text	
.globl main
main:
	#inserção de variaveis
	ori $s0,$zero,1 #x=1
	
	#calculo de 5*x
    sll $t0,$s0,2 #t0 = t1 << 2 (t0=4*x)
    add $t0,$t0,$s0 #t0=4*x+x (t0=5*x)

    #calculando 5x+15
    addi $s1,$t0,0x0000000F #y=5x+15
    
.data

#fim