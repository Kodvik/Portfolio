#Programa 21 - Lista 06
#x->s1
#y->s2
#contador->s3
#contadorExpoente->s4
#resultadoMultiplicação->s5
#resultadoExpoente->s6

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
    or $t1,$zero,$s1 #t1 recebe x para o primeiro loop da multiplicação

    #calculo de x elevado a y

    ori $s4,$zero,1 #contador começando com 0 para elevar x e y
    elev:
    beq $s4,$s2,saidaelev #caso o contadorExpoente atinja o valor de y siginifica que foi feita a operação

        #fazendo a multiplicação de x * x
        ori $s3,$zero,0 #contador começando em 0 para a multiplicação
        ori $s5,$zero,0
        multip:
        beq $s3,$s1,saidamultip #caso o contador atinja o valor de x siginifica que multi foi feita
            add $s5,$s5,$t1 #adiciona x ao resultado, y vezes... fazendo assim a multiplicação x*y
            addi $s3,$s3,1 #adiciona 1 ao contador
            j multip #retorna para mais um loop de soma para a multiplicação
        saidamultip:   
    or $t1,$zero,$s5 #recebe s5 (resultado da multiplicação em t1 para o proximo loop de multiplicação
    addi $s4,$s4,1 #adiciona 1 ao contador
    j elev #retorna para mais um loop de soma para elevar x a y
    saidaelev:
    sw $t1,8($s0) #guarda o resultado da multiplicação em  k

.data
x: .word 5
y: .word 6
k: .word 0x0 #somente para reservar a posição de memoria para quando terminar o calculo

#fim