#Problema: 12250 - Language Detection
#Autor:    FernandoJerezano
#Fecha:    28-Octubre-2017
c = 1

while True:
	s = input()
	if s=="#":
		break
	if s=="HELLO":
		s = "ENGLISH"
	elif s=="HOLA":
		s = "SPANISH"
	elif s=="HALLO":
		s = "GERMAN"
	elif s=="BONJOUR":
		s = "FRENCH"
	elif s=="CIAO":
		s = "ITALIAN"
	elif s=="ZDRAVSTVUJTE":
		s = "RUSSIAN"
	else:
		s = "UNKNOWN"
		
	print("Case %d:" % c,s)
	c += 1
