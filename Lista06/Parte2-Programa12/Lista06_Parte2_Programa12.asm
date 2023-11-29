#Programa 9 - Lista 06
#x->s1
#ponteiro1->s0
#ponteiro2->s1
#ponteiro3->s2

#inicio

.text	
.globl main
main:
    
    #preparacao de leitura de da memoria na primeira posição de data 0x10010000
    ori $s0,$zero,0x00001001
    sll $s0,$s0,16 #ponteiro1 agora possui o endereço de x
    sw	$s0, 8($s0)	#guardando o ponteiro de x em ponteiro1
    

    #alocação dos ponteiros
    addi $s1,$s0,4 #ponteiro2 agora possui o endereço de ponteiro1
    sw $s1,0xc($s0) #guardando o ponteiro1 em ponteiro2
    addi $s2,$s1,4 #ponteiro3 agora possui o endereço de ponteiro2
    sw $s2,0x10($s0) #guardando o ponteiro2 em ponteiro3

    #coleta de dados
    lw $t1, 0($s0) #k recebe x a partir do ponteiro1

    #multiplicando x por 2
    sll $t1,$t1,1 # $t1 = $t1 << 1 (multiplicado por 2)
    sw $t1,4($s0) # k recebe 2x
    
.data
    x: .word 2
    k: .word 0 #valor sera substituido posteriormente
    ponteiro1: .word 0
    ponteiro2: .word 0
    ponteiro3: .word 0
#não entendi muito bem o enunciado mas acho que era isso que queria
#fim

