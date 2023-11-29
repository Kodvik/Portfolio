#Programa 9 - Lista 06
#x->s1
#z->s2
#y->s3
#objetivo final -> y = 127x – 65z + 1

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

    #calculo de 127x
    sll $t0,$s1,7 # $t0 = $s1 << 7 (t0 = 128x)    
    sub $t0,$t0,$s1 #t0 = 128x - x (127x)

    #calculo de 65z
    sll $t1,$s2,6 # $t1 = $s2 << 6 (t1 = 64z)
    add $t1,$t1,$s2 #t1 = 64z + z

    #calculo de 127x - 65z + 1
    sub $t3,$t0,$t1 # $t3 = 127x - 65z
    addi $t3,$t3,1	# t3 = t3 + 1
    
    #guardando valor em y
    sw $t3, 8($s0) # y recebe resultado da conta 
    

.data
    x: .word 5
    z: .word 7
    y: .word 0 # esse valor deverá ser sobrescrito após a execução do programa.
#fim