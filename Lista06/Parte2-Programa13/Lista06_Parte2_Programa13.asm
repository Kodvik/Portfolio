#Programa 13 - Lista 06
#A->s1

#inicio

.text	
.globl main
main:
    
    #preparacao de leitura de da memoria na primeira posição de data 0x10010000
    ori $s0,$zero,0x00001001
    sll $s0,$s0,16 #faz com que s0 tenha 0x10010000

    #carregando valor de A para o registrador s1
    lw $s1,0($s0) # s1 = A 
    
    #preparação da mascara e coleta do bit de sinal
    sll $t0,$s0,15 #faz com que t0 tenha 0x80000000
    and $t1,$t0,$s1 # $t1 = $t0 (mascara) & $s1 (valor de A) - (isolando o bit de sinal em t1)

    #teste de se é positivo ou negativo
    beq	$t1, $zero, pulo	# se t1 e 0 forem iguais, siginifica que é positivo, então vai para pulo
        or $s1,$t0,$s1 # $t0 = $t1 | $t2
    pulo:
    sw $s1,0($s0) #guarda o valor do modulo de A em A 

.data
    A: .word 0x27041989
#fim