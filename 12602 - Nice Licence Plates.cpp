// Problema: 12602 - Nice Licence Plates
// Autor:    FernandoJerezano
// Fecha:    24-Diciembre-2017
#include <iostream>
#include <stdio.h>

using namespace std;

int val[250];
int let[5];

void init(){
	int cont = 0;
	int i;
	for(i='A';i<='Z';i++){
		val[i] = cont;
		cont++;
	}
	
	cont = 0;
	for(i='0';i<='9';i++){
		val[i] = cont++;
	}
	
	let[0] = 26*26;
	let[1] = 26;
	let[2] = 1;
}

int abso(int a){
	return a>0 ? a : a*-1;	
}

int main(){
	
	//freopen("entrada.txt","r",stdin);
	//freopen("salida.txt","w",stdout);
	
	int n;
	char cad[20];
	int mul;
	int n1,n2;
	int i;
	
	scanf("%d",&n);
	
	init();
	
	while(n--){
		
		mul = 1000;
		n1 = 0;
		n2 = 0;
		
		scanf("%s",cad);
		
		for(i=0;i<3;i++){
			n1 += val[cad[i]]*let[i];
		}
		
		for(i=4;i<8;i++){
			n2 += mul*val[cad[i]];
			mul/=10;
		}
		
		//cout<<n1<<endl;
		//cout<<n2<<endl;
		
		if(abso(n1-n2)<=100)
			printf("nice\n");
		else
			printf("not nice\n");
		
	}
	
	return 0;
}
