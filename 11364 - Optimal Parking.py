#Problema: 11364 - Optimal Parking
#Autor:    FernandoJerezano
#Fecha:    28-Octubre-2017
import string

def maximo(a,b):
	if a > b:
		return a
	return b;
	

def minimo(a,b):
	if a<b:
		return a
	return b

def abso(a):
	if a>0:
		return a
	return a*-1	
	
t = int(input())	
while t>0:
	
	min = 1000
	max = -1
	n = int(input())

	val = input().split(" ")
	
	for v in val:
		min = minimo(min,int(v))
		max = maximo(max,int(v))
	print( (max-min)*2)
	t = t-1
