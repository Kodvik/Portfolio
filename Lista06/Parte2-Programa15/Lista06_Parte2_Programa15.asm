#Programa 15 - Lista 06
#Escrever um programa que crie um vetor de 100 elementos na memória onde vetor[i] = 2*i + 1. 
#Após a última posição do vetor criado, escrever a soma de todos os valores armazenados do vetor. 
#Use o MARS para verificar a quantidade de instruções conforme o tipo (ULA, Desvios, Mem ou Outras)A->s1

#inicio

.text	
.globl main
main:
    
    #preparacao da memoria na primeira posição de data 0x10010000
    ori $s0,$zero,0x00001001
    sll $s0,$s0,16 #faz com que s0 tenha 0x10010000
    or $s1,$zero,$zero #$s0 igual a zero para ser contador
    ori $s2,$zero,99 #s1 igual a 99 para marcar a ultima posição do vetor 
    or $s3,$zero,$zero #s0 será manterá a soma

    loop:
        beq $s1,$s2,saidaloop #caso s1 seja igual a 99 está na ultima posição então sai do loop
        sll $t1,$s1,1 #t1 recebe 2i
        add $t1,$t1,1 #adiciona o +1 do final da formula (vetor[i]=2i+1) a cada passagem
        add $s3,$s3,$t1 #adiciona o valor da passagem ao somador
        sw $t1,0($s0) #salva o valor do item no vetor
        addi $s1,$s1,1 #adiciona +1 a i
        addi $s0,$s0,4 #avança para a proxima posição da memoria
        j loop #volta para o inicio do loop
    saidaloop:
     sw $s3,0($s0) #salva o valor da soma de todos os items do vetor

.data
#fim