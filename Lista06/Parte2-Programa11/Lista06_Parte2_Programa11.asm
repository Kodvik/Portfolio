#Programa 9 - Lista 06
#x->s1
#z->s2
#y->s3
#objetivo final -> y = x – z + 300000

#inicio

.text	
.globl main
main:
    
    #preparacao de leitura de da memoria na primeira posição de data 0x10010000
    ori $s0,$zero,0x00001001
    sll $s0,$s0,16

    #leitura dos dados
    lw $s1,0($s0) #s1 recebe x
    lw $s2,4($s0) #s2 recebe z

    #obtenção de 300000
    add $t0,$s1,$s2 #t0=x+z (100000+200000 = 300000)
    sub $t1,$s1,$s2 #t1=x-z (100000-200000 =-100000)
    add $t2,$t1,$t0 #t2= 300000 +(-100000)
    
    #guardando resultado
    sw $t2, 8($s0) # y = resultado da conta 
    
.data
    x: .word 100000
    z: .word 200000
    y: .word 0 # esse valor deverá ser sobrescrito após a execução do programa.
#fim