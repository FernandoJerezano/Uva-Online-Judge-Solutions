#Problema: 11547 - Automatic Answer
#Autor:    FernandoJerezano
#Fecha:    28-Octubre-2017

t = int(input())

def abso(a):
	if a>0:
		return a
	return a*-1

while t>0:
	n = int(input())
	n = n*567
	n = int(n/9)
	n = n+7492
	n = n*235
	n = int(n/47)
	n = n-498
	n = int(n/10)
	n = abso(n)
	n = n%10
	print(int(n))
	t -= 1
