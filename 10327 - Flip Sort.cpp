// Problema: 10327 - Flip Sort
// Autor:    FernandoJerezano
// Fecha:    28-Diciembre-2017
#include <iostream>
#include <bits/stdc++.h>
#define MAX_N 1005

using namespace std;

int n;
int arr[MAX_N];

int bubble_sort(int n){
	int cont = 0;
	int temp;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1-i;j++){
			if(arr[j]>arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				cont++;
			}
		}
	}
	
	
	return cont;
	
}

int main(){

	int r;
	
	//freopen("entrada.txt","r",stdin);
	//freopen("salida.txt","w",stdout);
	
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d",&arr[i]);
		}
		r = bubble_sort(n);
		printf("Minimum exchange operations : %d\n",r);
	}
	return 0;
}


