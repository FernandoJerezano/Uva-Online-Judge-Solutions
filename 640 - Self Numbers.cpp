// Problema: 640 - Self Numbers
// Autor:    FernandoJerezano
// Fecha:    26-Diciembre-2017
#include <iostream>
#include <bits/stdc++.h>
#define MAX_N 1000001

int d(int n){
	int sum = n;
	
	while(n>0){
		sum+= n%10;
		n=n/10;
	}	
	return sum;
}
int arr[MAX_N];

void prec(){
	int p;
	for(int i=1;i<MAX_N;i++){
		p = d(i);
		if(p<MAX_N){
			arr[p] = 1;
		}
	}
}

int main(){
	
	//freopen("salida.txt","w",stdout);
	prec();
	for(int i=1;i<MAX_N;i++){
		if(!arr[i])
			printf("%d\n",i);
	}
	
	return 0;
}
