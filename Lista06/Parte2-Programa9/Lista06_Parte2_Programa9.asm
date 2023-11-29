#Programa 9 - Lista 06
#x1->s1
#x2->s2
#x3->s3
#x4->s4
#x5->s5

#inicio

.text	
.globl main
main:
    
    #preparacao de leitura de da memoria na primeira posição de data 0x10010000
    ori $s0,$zero,0x00001001
    sll $s0,$s0,16

    #leitura dos dados
    lw $s1,0($s0) #s1 recebe x1
    lw $s2,4($s0) #s2 recebe x2
    lw $s3,8($s0) #s3 recebe x3
    lw $s4,0xc($s0) #s4 recebe x4
    
    #somas
    add $t0,$s1,$s2 #x1+x2
    add $t1,$s3,$s3 #x3+x4
    add $t2,$t0,$t1 #x1+x2+x3+x4
    sw	$t2,0xc($s0) # salva t2 em soma

.data
    x1: .word 15
    x2: .word 25
    x3: .word 13
    x4: .word 17
    soma: .word -1
#fim