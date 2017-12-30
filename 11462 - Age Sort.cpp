// Problema: 11462 - Age Sort
// Autor:    FernandoJerezano
// Fecha:    28-Diciembre-2017
#include <iostream>
#include <bits/stdc++.h>
#define MAX_N 105

using namespace std;

int values[MAX_N];

void init(){

	for(int i=1;i<=100;i++){
		values[i] = 0;
	}
}

int minimo(int a, int b){
	return a<b ? a : b;
}

int main(){
	
	//freopen("entrada.txt","r",stdin);
	//freopen("salida.txt","w",stdout);
	
	int n,v,m;
	
	while(scanf("%d",&n) && n){
		if(n==0)
			break;
		
		init();
		m = 101;
		for(int i=0;i<n;i++){
			scanf("%d",&v);
			values[v]++;
			m = minimo(m,v);
		}
		printf("%d",m);
		values[m]--;
		for(int i=1;i<=100;i++){
			for(int j=1;j<=values[i];j++){
				printf(" %d",i);
			}
		}
		printf("\n");
	}

	return 0;
}
