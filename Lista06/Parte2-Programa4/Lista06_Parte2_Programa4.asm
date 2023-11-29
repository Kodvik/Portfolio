#Programa 4 - Lista 06 (usando somente add, addi, sub, lógicas)
#x->s0
#y->s1
#z->s2

#inicio

.text	
.globl main
main:
	#inserção de variaveis
	ori $s0,$zero,3 #x=3
    ori $s1,$zero,4 #y=4
	
	#calculo de 15*x
    sll $t0,$s0,4 #t0 = t0 << 4 (t0=16*x)
    sub $t0,$t0,$s0 #t0=4*x-x (t0=15*x)

    #calculando 67*y
    sll $t1,$s1,6 #t1 = t1 << 6 (t0=64*y)
    add $t1,$t1,$s1 #t1 = 64y + y (65y)
    add $t1,$t1,$s1 #t1 = 65y + y (66y)
    add $t1,$t1,$s1 #t1 = 66y + y (67y)

    #calculando 15x + 67y
    add $t2,$t0,$t1 #t2 = 15x + 67y

    #calculando ( 15x + 67y ) * 4 
    sll	$s2,$t2,2 # $s2 = $t2 << 2 (z=(15x+67y)*4)
    
.data

#fim