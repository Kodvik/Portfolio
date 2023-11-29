#Programa 14 - Lista 06
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
    
    #teste de par ou impar
    ori $t1,$zero,1
    andi $t0,$s1,1 # $t0 = $s1 & 1 (Isolando então o primeiro bit *1*)

    #caso t0 seja 1, o numero é impar, caso seja 0 é par
    beq $t0,$zero,par #se $t0 != $t1 então vá para pulo
        ori $t1,$zero,0x0001 #alocando 1 para poder guardar
        sw $t1, 4($s0) #guarda 0x0001 na proxima posição da memoria.
    par:
        

.data
    A: .word 0x27041989
#fim