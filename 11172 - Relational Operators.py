#Problema: 11172 - Relational Operators
#Autor:    FernandoJerezano
#Fecha:    28-Octubre-2017

t = int(input())

while t>0:
	
	val = input().split(" ")
	a = int(val[0])
	b = int(val[1])
	if a==b:
		print("=")
	elif a>b:
		print(">")
	else:
		print("<")
		
	
	t -= 1
