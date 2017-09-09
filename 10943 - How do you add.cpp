// Problema:	10943 - How do you add?
// Autor: 		FernandoJerezano
// Fecha:     08-Septiembre-2017
#include <iostream>
#include <bits/stdc++.h>
#define MAX_N 105

using namespace std;

const int mod = 1000000;

int table[MAX_N][MAX_N];

int ways(int n, int k){
	
	if(k==1)
		return 1;
	int ans = 0;
	if(table[n][k]!=-1)
		return table[n][k];
	for(int x=0;x<=n;x++){
		ans = ((ans%mod)+(ways(n-x,k-1)%mod))%mod;
	}	
	return table[n][k] = ans;
}

int main(){
	
	//freopen("entrada.txt","r",stdin);
	//freopen("salida.txt","w",stdout);

	int n,k;
	int r;
	
	memset(table,-1,sizeof table);
	
	while(scanf("%d%d",&n,&k)){
		if(n==0 && k==0)
			break;
		r = ways(n,k);
		printf("%d\n",r);
	}
	
	return 0;
}
