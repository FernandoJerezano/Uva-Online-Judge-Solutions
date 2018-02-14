// Problema: 10963 - The Swallowing Ground
// Autor:    FernandoJerezano
// Fecha:    11-Febrero-2018
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int abso(int a){
	return a>0 ? a : a*-1;
}

int main(){
	
	//freopen("entrada.txt","r",stdin);
	//freopen("salida.txt","w",stdout);

	int t,w;
	int a, b;
	int d, r;
	
	scanf("%d",&t);
	
	while(t--){
		
		scanf("%d",&w);
		
		scanf("%d%d",&a,&b);
		d = abso(a-b);
		r = 1;
		--w;
		while(w--){
			
			scanf("%d%d",&a,&b);
			if(abso(a-b)!=d){
				r = 0;
			}
		}
		
		if(r){
			printf("yes\n");
		}else{
			printf("no\n");
		}
		if(t!=0)
			printf("\n");
	}
	return 0;
}
