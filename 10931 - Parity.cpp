// Problema: 10931 - Parity
// Autor:    FernandoJerezano
// Fecha:    26-Diciembre-2017
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int lb;

int maximo(int a, int b){
	return a>b?a:b;
}

int sum_bits(int n){
	int sum = 0;
	lb = 0;
	for(int i=31;i>=0;i--){
		if(n&(1<<i)){
			lb = maximo(lb,i);
			sum++;
		}
	}
	return sum;
}



int main(){

	//freopen("entrada.txt","r",stdin);
	//freopen("salida.txt","w",stdout);
	int n,r;
	
	while(scanf("%d",&n) && n){
		
		r = sum_bits(n);
		printf("The parity of ");
		
		for(int i=lb;i>=0;i--){
			if(n&(1<<i)){
				printf("1");
			}else{
				printf("0");
			}
		}
		
		printf(" is %d (mod 2).\n",r);
		
	}
	return 0;
}
