// Problema:  1121 - Subsequence
// Autor:     FernandoJerezano
// Fecha:     10-Septiembre-2017
#include <bits/stdc++.h>
#define MAX 100005

using namespace std;

typedef long long int ll;

ll arr[MAX];
ll n,s;

ll minimo(ll a, ll b){
	return a<b?a:b;
}

ll min_sub(){
	
	ll i = 0;
	ll c = 0;
	ll ms = 0;
	ll sub = MAX;
	
	while(i<=n){
		
		while(ms>=s && c<i){
			sub = minimo(sub,i-c);
			ms-=arr[c];
			c++;
			//printf("%lld\n",ms);
		}
		if(i<n)
			ms += arr[i];
		//printf("%lld\n",ms);
		i++;
	}
	if(sub==MAX)
		return 0;
	return sub;
}

int main(){
	
	//freopen("entrada.txt","r",stdin);
	//freopen("salida.txt","w",stdout);
	
	ll r;
	
	while(scanf("%lld%lld",&n,&s)!=EOF){
		
		for(ll i=0;i<n;i++){
			scanf("%lld",&arr[i]);
		}
		
		r = min_sub();
		printf("%lld\n",r);
	}
	
	return 0;
}
