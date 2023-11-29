#Programa 16 - Lista 06
#Inicializar os registradores com os valores acima
#x->s1
#y->s2
#z->s3
#contador->s4
#resultadoMultiplicação -> s5
#resultadoDivisão -> s6
#mascaraDeSinal-> s7

#não utilizar o t0 para contas, ele vai estar mantendo a validação do loop de divisão

#inicio

.text	
.globl main
main:
    
    #preparacao da memoria na primeira posição de data 0x10010000 e da mascara de sinal
    lui $s0,0x1001 #primeira posicao de memoria
    lui $s7,0x8000 #1 no bit mais significativo (bit de sinal)
    lui $t0,0x0001 #somente para não iniciar como zero para o loop

    #carregando os valores para os registradores
    lw $s1,0($s0) #s1 recebe x
    lw $s2,4($s0) #s2 recebe y
    lw $s3,8($s0) #s3 recebe z
    or $s5,$zero,$zero #resultadoMultiplicação começa com 0
    
    #como não posso usar o multi ainda, vou fazer com add e branch 

    #vou fazer a divisao primeiro para reduzir a quantidade de operações na multiplicação
    or $t1,$zero,$s2 #carrega t1 com o valor de s2 (y) para poder fazer a divisao
    ori $s4,$zero,0 #contador começando em 0
    divis:
    beq $t0,$zero,saidadivis #caso a o bit mais significativo seja diferente de 0, sai do loop por ter passado de zero
        sub $t1,$t1,$s3 #subtrai s3 (z) de t1
        and $t0,$t0,$t1 #valida se o valor de t1 ainda é positivo
        addi $s4,$s4,1 #adiciona 1 ao contador (quociente da divisao)
        j divis #volta para divis
    saidadivis:
    
    or $s6,$s6,$s4 #guarda valor de s4 (contador) em s6 (resultadoDivisao)
    ori $s4,$zero,1 #contador começando em 1 para a multiplicação

    #fazendo a multiplicação de x e (y/z)
    multip:
    beq $s4,$s6,saidamultip #caso o contador atinja o valor de y siginifica que multi foi feita
        add $s5,$s5,$s1 #adiciona x ao resultado, y vezes... fazendo assim a multiplicação x*y
        addi $s4,$s4,1 #adiciona 1 ao contador
        j multip #retorna para mais um loop de soma para a multiplicação
    saidamultip:   

.data
x: .word 0x186A00
y: .word 0x13880
z: .word 0x61A80

#fim