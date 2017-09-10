// Problema:  11369 - Shopaholic
// Autor:     FernandoJerezano
// Fecha:     09-Septiembre-2017
#include <iostream>
#include <bits/stdc++.h>
#define MAX_N 20005

using namespace std;

int arr[MAX_N];

int main(){
	
	//freopen("entrada.txt","r",stdin);
	//freopen("salida.txt","w",stdout);
	
	int t;
	int n;
	int v;
	int sum;
	
	scanf("%d",&t);
	
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&v);
			arr[i] = -v;
			
		}
		
		sum = 0;
		
		sort(arr,arr+n);
		
		for(int i=2;i<n;i+=3){
			sum+=arr[i];
		}
		printf("%d\n",-sum);
	}	
	return 0;
}
