#Problema: 1124 - Celebrity jeopardy
#Autor:    FernandoJerezano
#Fecha:    28-Octubre-2017
import string
values = input()
try:
    while values:
        print (values)
        values = input()
except EOFError:
    exit
