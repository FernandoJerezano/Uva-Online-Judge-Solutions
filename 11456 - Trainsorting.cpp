// Problema: 11456 - Trainsorting
// Autor:    FernandoJerezano
// Fecha:    03-Septiembre-2017
#include <iostream>
#include <bits/stdc++.h>
#define MAX_N 2005

using namespace std;

int n;
int arr[MAX_N];

int maximo(int a, int b){
	return a>b?a:b;
}

int train_sorting(){
	
	int lis[n];
	int lds[n];
	int max;
	
	for(int i=0;i<n;i++){
		lis[i] = lds[i] = 1;
	}
	
	// LIS
	for(int i=n-1;i>=0;i--){
		for(int j=i+1;j<n;j++){
			if(arr[i]<arr[j]){
				lis[i] = maximo(lis[i],lis[j]+1);
			}
		}
	}
	
	// LDS
	for(int i=n-1;i>=0;i--){
		for(int j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
				lds[i] = maximo(lds[i],lds[j]+1);
			}
		}
	}
	
	max = -1;
	for(int i=0;i<n;i++){
		max = maximo(max,lis[i]+lds[i]-1);
	}
	return max;
}

int main(){
	
	//freopen("entrada.txt","r",stdin);
	//freopen("salida.txt","w",stdout);
	
	int t,r;
	
	scanf("%d",&t);
	
	while(t--){
		
		r = -1;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&arr[i]);
		}
		if(n!=0)
			r = train_sorting();
		if(r<0)
			r = 0;
		
		printf("%d\n",r);
	}

	return 0;
}













