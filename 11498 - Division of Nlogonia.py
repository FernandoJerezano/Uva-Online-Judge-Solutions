#Problema: 11498 - Division of Nlogonia
#Autor:    FernandoJerezano
#Fecha:    28-Octubre-2017
import string

while True:
	t = int(input())
	if t==0:
		break;
	val = input().split(" ")
	x = int(val[0])
	y = int(val[1])

	
	while(t>0):
		val = input().split(" ")
		a = int(val[0])
		b = int(val[1])
		
		if a==x or b==y:
			print("divisa")
		else:
			if a>x:
				if b>y:
					print("NE")
				else:
					print("SE")
			else:
				if b>y:
					print("NO")
				else:
					print("SO")
		t -= 1
		 
