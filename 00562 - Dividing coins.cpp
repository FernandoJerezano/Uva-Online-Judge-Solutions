// Problema: 562 - Dividing coins
// Autor:    FernandoJerezano
// Fecha:    28-Septiembre-2017
#include <iostream>
#include <bits/stdc++.h>

#define MAX_M 105
#define MAX_C 52500

using namespace std;

typedef long long int ll;

ll table[MAX_M][MAX_C];
ll arr[MAX_M];

ll maximo(ll a, ll b){	
	return a>b?a:b;
}

ll subset_sum_bu(ll n, ll rw){

	ll i;
	ll w;
	
	for(i=0;i<=rw;i++){
		table[0][i] = 0;
	}
	
	for(i=1;i<=n;i++){
		for(w=0;w<=rw;w++){
			if(arr[i]<=w)
				table[i][w] = maximo(table[i-1][w],table[i-1][w-arr[i]]+arr[i]);
			else
				table[i][w] = table[i-1][w];
		}
	}
	return table[n][rw];
	
}

ll abso(ll a){
	return a>0 ? a : a*-1;
}

int main(){

	//freopen("entrada.txt","r",stdin);
	//freopen("salida.txt","w",stdout);
	
	ll t,n,v;
	ll s,r1,r2;
	
	scanf("%lld",&t);
	
	while(t--){
			
		scanf("%lld",&n);
		
		s = 0;
		
		for(int i=1;i<=n;i++){
			scanf("%lld",&v);
			arr[i] = v;
			s += v;
		}
		
		r1 = subset_sum_bu(n,s/2);
		r1 = s-r1*2;
		
		//printf("S: %lld\n",s);
		//printf("R1: %lld\n",r1);
		//printf("R2: %lld\n",r2);
		printf("%lld\n",r1);
	}	
	return 0;
}
