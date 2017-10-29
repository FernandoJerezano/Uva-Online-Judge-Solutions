#Problema: 11727 - Cost Cutting
#Autor:    FernandoJerezano
#Fecha:    28-Octubre-2017
import string
t = int(input())
v = 0
for i in range(t):
	
	val = input().split(" ")
	a = val[0]
	b = val[1]
	c = val[2]
	
	val.sort()
	
	print("Case %d:" % (i+1),val[1])
			
		
