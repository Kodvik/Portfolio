#Programa 8 - Lista 06 


#inicio

.text	
.globl main
main:
	#inserção de variaveis
    #ori $8, $0, 0x12345678 #instrução inicial dada nao funcionaria uma vez que não da para inserir de uma
    #vez somente com sll e ori
    ori $8,$zero,0x00001234
    sll $8,$8,16
    ori $8,$8,0x00005678
    

    #manipulação para $9
    srl	$9, $8, 24	# $9 = $8 >> 24 ($9 recebe 0x00000012)
    
    #manipulação para $10
    ori $t9,$zero, 0x000000FF #t9 recebe 0x000000FF
    sll $t9,$t9,16 #t9 recebe 0x00FF0000
    and $10, $8, $t9 # $10 recebe 0x00340000
    srl $10, $10, 16 # $10 = $10 >> 16 ($10 recebe 0x00000034)

    #manipulação para $11
    andi $11, $8, 0x0000FF00
    srl $11, $11, 8 # $11 = $11 >> 8 ($11 recebe 0x00000056)

    #manipulação para $12
    andi $12, $8, 0x000000FF

.data

#fim