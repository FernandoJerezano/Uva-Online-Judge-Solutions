// Problema: 11703 - sqrt log sin
// Autor:    FernandoJerezano
// Fecha:    05-Septiembre-2017
#include <iostream>
#include <bits/stdc++.h>
#define MAX_N 1000005

using namespace std;

typedef int ll;

const ll mod = 1000000;

ll arr[MAX_N];

void prec(){
	
	ll v1,v2,v3;
	
	arr[0] = 1;
	ll i;
	
	for(i=1;i<MAX_N;i++){
		v1 = (ll)(floor( i-sqrt(i) ));
		v2 = (ll)(floor( log(i) ));
		v3 = (ll)(floor( i*(sin(i)*sin(i)) ));
		
		arr[i] = (arr[v1]%mod+arr[v2]%mod+arr[v3]%mod)%mod;
	}
	
}

int main(){
	
	//freopen("entrada.txt","r",stdin);
	//freopen("salida.txt","w",stdout);
	
	ll n;
	
	prec();

	while(scanf("%d",&n) && n!=-1){
		printf("%d\n",arr[n]);
	}
	return 0;
}
