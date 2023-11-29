#Programa 19 - Lista 06
#n1->s0
#n2->s1
#bitSignificantes n1 -> t0
#bitSignificantes n2 -> t1
#lo->s2
#hi->s3
#s6 -> contador de deslocamentos
#s7 -> posição inicial de memoria

#inicio

.text	
.globl main
main:
    
    #preparacao da memoria na primeira posição de data 0x10010000 e da mascara de sinal
    lui $s7,0x1001 #primeira posicao de memoria

    #carregando os valores para os registradores
    lw $s0,0($s7) #s1 recebe n1
    lw $s1,4($s7) #s2 recebe n2
    add $t0,$zero,$zero #iniciando t0 como zero para contar os bits
    add $t1,$zero,$zero #iniciando t1 como zero para contar os bits
    addi $s6,$zero,32 #inicia o contador de deslocamentos em 32 não passar da posição de memoria
    lui $t2,0x8000 #mascara com 1 no bit mais significativo para contar
    add $s5,$zero,1 #só para poder utilizar o sub para contagem regresiva

    testeDeSignificancia:
    
    testeSignificanciaN1:
        and $t3,$t2,$s0 #faz o teste com a mascara no bit mais significativo
        beq $t3,$zero,saidaTesteSignificanciaN1 #pula a soma caso seja diferente de 0
            addi $t0,$t0,1 #adiciona 1 ao contador de bits significativos se for 1
    saidaTesteSignificanciaN1:
    
    testeSignificanciaN2:
        and $t4,$t2,$s1 #faz o teste com a mascara no bit mais significativo
        beq $t4,$zero,saidaTesteSignificanciaN2 #pula a soma caso seja diferente de 0
            addi $t1,$t1,1 #adiciona 1 ao contador de bits significativos se for 1
    saidaTesteSignificanciaN2:

    srl $t2,$t2,1 #desloca a mascara para a direita 1 bit
    sub $s6,$s6,$s5 #subtrai 1 do contador
    beq $s6,$zero,saidaTesteDeSignificancia #caso s6 seja zero, foram lidos todos os bits
        j testeDeSignificancia #caso s6 não seja zero, volta para fazer mais loops de teste
    saidaTesteDeSignificancia:
    
    #caso o professor peça para ser t0 e t1 retirar comentarios
    #mult $t0, $t1 # $t0 * $t1 = Hi e Lo
    #mflo $s2 #copia Lo para $s2
    #mfhi $s3 #copia Hi para $s3

    #caso o professor peça para ser s0 e s1 retirar comentarios
    mult $s0, $s1 #s0 * $s1 = Hi e Lo
    mflo $s2 #copia Lo para $t2
    mfhi $s3 #copia Hi para $s1

.data
n1: .word 0x0030057c
n2: .word 0x00001a9d
#fim