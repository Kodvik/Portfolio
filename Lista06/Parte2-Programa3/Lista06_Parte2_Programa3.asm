#Programa 3 - Lista 06 (usando somente add, addi, sub, lógicas)
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
    add $t0,$s0,$s0 # t0=2x
    add $t0,$t0,$t0 # t0=4x
    add $t0,$t0,$t0 # t0=8x
    add $t0,$t0,$t0 # t0=16x
    sub $t0,$t0,$s0 # t0=15x

    #calculando 67*y
    add $t1,$s1,$s1 # t1=2y
    add $t1,$t1,$t1 # t1=4y
    add $t1,$t1,$t1 # t1=8y
    add $t1,$t1,$t1 # t1=16y
    add $t1,$t1,$t1 # t1=32y
    add $t1,$t1,$t1 # t1=64y
    add $t1,$t1,$s1 # t1=65y
    add $t1,$t1,$s1 # t1=66y
    add $t1,$t1,$s1 # t1=67y

    #calculando 15x + 67y
    add $t2,$t0,$t1 #t2 = 15x + 67y

    #calculando ( 15x + 67y ) * 4 
    add $t3,$t2,$t2 #t3= 2 * (15x+67y)
    add $s2,$t3,$t3 #t3= 4 * (15x+67y)
    
.data

#fim