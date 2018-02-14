// Problema: 11559 - Event Planning
// Autor:    FernandoJerezano
// Fecha:    11-Febrero-2018
#include <iostream>
#include <bits/stdc++.h>
#define M 2000000

using namespace std;

int minimo(int a, int b){
	return a<b ? a : b;
}

int main(){
	
	//freopen("entrada.txt","r",stdin);
	//freopen("salida.txt","w",stdout);
	
	int n,b,h,w;
	int p,a;
	int min = 0;
	int res;
	
	while(scanf("%d%d%d%d",&n,&b,&h,&w)!=EOF){
		
		min = M;
		
		for(int i=0;i<h;i++){
			scanf("%d",&p);
			for(int j=0;j<w;j++){
				scanf("%d",&a);
				if(n<=a){
					res = n*p;
					min = minimo(min,res);
				}
			}
		}
		if(min<=b){
			printf("%d\n",min);
		}else{
			printf("stay home\n");
		}
	}
	return 0;
}
