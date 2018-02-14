// Problema: 11679 - Sub-prime
// Autor:    FernandoJerezano
// Fecha:    11-Febrero-2018
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int banks[25];

void init(){
	
	for(int i=0;i<25;i++){
		banks[i] = 0;
	}
}

int main(){

	int b,n;
	int d,c,v;
	int res;
	
	//freopen("entrada.txt","r",stdin);
	//freopen("salida.txt","w",stdout);
	
	while(scanf("%d%d",&b,&n)){
		
		if(!b && !n)
			break;
		init();
		res = 1;
		
		for(int i=1;i<=b;i++){
			scanf("%d",&v);
			banks[i] = v;
		}
		
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&d,&c,&v);
			banks[c] += v;
			banks[d] -= v;
		}
		
		for(int i=1;i<=b;i++){
			//printf("B: %d\n",banks[i]);
			if(banks[i]<0){
				res = 0;
				break;
			}
		}
		
		if(res){
			printf("S\n");
		}else{
			printf("N\n");
		}
	
	}
	
	return 0;
}
