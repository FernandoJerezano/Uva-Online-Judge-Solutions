// Problema:  11059 - Maximum Product
// Autor:     FernandoJerezano
// Fecha:     07-Octubre-2017
#include <bits/stdc++.h>
#define MAX_N 20
#define MEN -100000000000000000

using namespace std;

typedef long long int ll;

ll arr[MAX_N];

ll maximo(ll a, ll b){
	return a>b?a:b;	
}

int main(){
	
	ll n,v;
	ll m;
	ll t;
	ll c = 1;
	
	//freopen("entrada.txt","r",stdin);
	//freopen("salida.txt","w",stdout);
	
	while(scanf("%lld",&n)!=EOF){
		m = MEN;
		for(ll i=0;i<n;i++){
			scanf("%lld",&arr[i]);
		}
		
		for(ll i=0;i<n;i++){
			t = 1;
			for(ll j=i;j<n;j++){
				t = t*arr[j];
				m = maximo(m,t);
			}
		}
		if(m<0)
			m = 0;
		printf("Case #%lld: The maximum product is %lld.\n\n",c,m);
		c++;
	}
		
	return 0;
}
