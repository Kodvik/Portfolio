#Programa 17 - Lista 06
#x->s1
#y->s2
#contador->s3
#resultadoMultiplicação->s4

#inicio

.text	
.globl main
main:
    
    #preparacao da memoria na primeira posição de data 0x10010000 e da mascara de sinal
    lui $s0,0x1001 #primeira posicao de memoria
    lui $t0,0x0001 #somente para não iniciar como zero para o loop

    #carregando os valores para os registradores
    lw $s1,0($s0) #s1 recebe x
    lw $s2,4($s0) #s2 recebe y

    #fazendo a multiplicação de x * y
    ori $s3,$zero,0 #contador começando em 0 para a multiplicação
    multip:
    beq $s3,$s2,saidamultip #caso o contador atinja o valor de y siginifica que multi foi feita
        add $s4,$s4,$s1 #adiciona x ao resultado, y vezes... fazendo assim a multiplicação x*y
        addi $s3,$s3,1 #adiciona 1 ao contador
        j multip #retorna para mais um loop de soma para a multiplicação
    saidamultip:   
    sw $s4,8($s0) #guarda o resultado da multiplicação em  k

.data
x: .word 150
y: .word 30
k: .word 0x0 #somente para reservar a posição de memoria para quando terminar o calculo

#fim