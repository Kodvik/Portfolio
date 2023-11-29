#Programa 1 - Lista 06
#s0->a
#s1->b
#s2->c
#s3->d
#s4->x
#s5->y

#inicio

.text	
.globl main
main:
	#inserção de variaveis
	ori $s0,$zero,2 #a=2
	ori $s1,$zero,3 #b=3
	ori $s2,$zero,4 #c=4
	ori $s3,$zero,5 #d=5
	
	#operação para x=(a+b)-(c+d)
	add $t0,$s0,$s1 #temp0 = a+b
	add $t1,$s2,$s3 #temp1 = c+d
	sub $s4,$t0,$t1 #x=temp0-temp1
	
	#operação para y=a-b+x
	sub $t0,$s0,$s1 #temp0 = a-b
	add $s5,$t0,$s4 #y=temp0 + x
	
	#operação para b=x-y
	sub $s1,$s4,$s5 #b=x-y

.data

#fim