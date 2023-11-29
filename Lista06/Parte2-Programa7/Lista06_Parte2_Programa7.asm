#Programa 7 - Lista 06 


#inicio

.text	
.globl main
main:
	#inserção de variaveis
    ori $8, $0, 0x01 #instrução inicial dada

    #manipulação
    sll		$t1,$8,1	# $t1 = $8 << 1 (t1 = 0x00000002)
    or		$8,$8,$t1	# $8 =  $8 | $t1 (0x00000001 or 0x00000002, logo $8 = 0x00000003)    
    sll		$t1,$8,2	# $t1 = $8 << 2 (t1 = 0x0000000c)
    or		$8,$8,$t1   # $8 =  $8 | $t1 (0x00000003 or 0x0000000c, logo $8 = 0x0000000f)

    #apos obter o primeiro f, somente necessario repetir o deslocamento
    sll		$t1,$8,4	# $t1 = $8 << 4 (t1 = 0x000000f0)
    or		$8,$8,$t1   # $8 =  $8 | $t1 (0x0000000f or 0x000000f0, logo $8 = 0x000000ff)
    sll		$t1,$8,8	# $t1 = $8 << 8 (t1 = 0x0000ff00)
    or		$8,$8,$t1   # $8 =  $8 | $t1 (0x000000ff or 0x0000ff00, logo $8 = 0x0000ffff)
    sll		$t1,$8,16	# $t1 = $8 << 16 (t1 = 0x0000ff00)
    or		$8,$8,$t1   # $8 =  $8 | $t1 (0x0000ffff or 0xffff0000, logo $8 = 0xffffffff)    

.data

#fim