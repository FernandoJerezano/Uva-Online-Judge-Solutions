// Problema:  10664 - Luggage
// Autor:     FernandoJerezano
// Fecha:     28-Septiembre-2017

#include <iostream>
#include <bits/stdc++.h>
#define MAX_N 25
#define MAX_K 205

using namespace std;

int arr[MAX_N];
int table[MAX_N][MAX_K];

int maximo(int a, int b){
	return a>b?a:b;	
}

int subset_sum_bu(int n, int rw){
	int i,w;
	
	for(i=0;i<=rw;i++){
		table[0][i] = 0;
	}
	
	for(i=1;i<=n;i++){
		for(w=0;w<=rw;w++){
			if(arr[i]<=w){
				table[i][w] = maximo(table[i-1][w],table[i-1][w-arr[i]]+arr[i]);
			}else{
				table[i][w] = table[i-1][w];
			}
		}
	}
	return table[n][rw];
}

int main(){
	
	return 0;
}
