#Problema: 12279 - Emoogle Balance
#Autor:    FernandoJerezano
#Fecha:    28-Octubre-2017
import string

c = 1

while True:
	t = int(input())
	if t==0:
		break;
	val = input().split(" ")
	
	m = 0
	n = 0
	
	for v in val:
		if int(v)==0:
			m += 1
		else:
			n += 1
			
	print("Case %d:" % c,n-m)
	c += 1
