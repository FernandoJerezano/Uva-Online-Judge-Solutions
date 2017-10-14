// Problema: 10616 - Divisible Group Sums
// Nombre:   FernandoJerezano
// Fecha:    14-Octubre-2017
#include <bits/stdc++.h>
#define MAX_N 205
#define MAX_D 25
#define MAX_M 15

using namespace std;

typedef long long int ll;

ll mat[MAX_N][MAX_M][MAX_D];
ll arr[MAX_N];

ll n,d,m;

void init(){
	
	ll i,j,k;
	
	for(i=0;i<MAX_N;i++){
		for(j=0;j<MAX_M;j++){
			for(k=0;k<MAX_D;k++){
				mat[i][j][k] = -1;
			}
		}
	}
}

ll dp_sol(ll id, ll r, ll sum){
	
	if(r==m){
		if(sum==0)
			return 1;
		return 0;
	}
	
	if(id>=n)
		return 0;
	
	if(mat[id][r][sum]==-1){
		ll ts = sum+arr[id];
		ts = ts%d;
		if(ts<0)
			ts+=d;
		return mat[id][r][sum] = dp_sol(id+1,r+1,ts)+dp_sol(id+1,r,sum%d);
	}
	return mat[id][r][sum];
}

int main(){

	//freopen("entrada.txt","r",stdin);
	//freopen("salida.txt","w",stdout);
	
	ll q;
	ll res;
	ll caso = 1;
	
	while(scanf("%lld%lld",&n,&q)){
		if(!n && !q)
			break;
		for(ll i=0;i<n;i++){
			scanf("%lld",&arr[i]);
		}
		printf("SET %lld:\n",caso);
		for(ll i=1;i<=q;i++){
			init();
			scanf("%lld%lld",&d,&m);
			res = dp_sol(0,0,0);
			printf("QUERY %lld: %lld\n",i,res);
		}
		caso++;
	}
	return 0;
}
