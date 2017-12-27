// Problema: 11461 - Square Numbers
// Autor:    FernandoJerezano
// Fecha:    26-Diciembre-2017
#include <iostream>
#include <bits/stdc++.h>
#define MAX_N 100005

using namespace std;

int arr[MAX_N];

void prec(){

	for(int i=1;i*i<MAX_N;i++){
		arr[i*i] = 1;
	}
	
	for(int i=1;i<MAX_N;i++){
		if(arr[i]==1){
			arr[i] = 1+arr[i-1];
		}else{
			arr[i] = arr[i-1];
		}		
	}
	
}

int main(){
	
	//freopen("entrada.txt","r",stdin);
	//freopen("salida.txt","w",stdout);
	prec();
	
	int a,b,r;
	
	while(1){
		scanf("%d%d",&a,&b);
		if(a==0 && b==0)
			break;
		r = arr[b]-arr[a-1];
		printf("%d\n",r);
		
	}	
	
	return 0;
}




