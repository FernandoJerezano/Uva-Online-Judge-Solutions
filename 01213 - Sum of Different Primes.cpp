// Problema:	1213 - Sum of Different Primes
// Autor:     	FernandoJerezano
// Fecha:     	02-Octubre-2017
#include <iostream>
#include <bits/stdc++.h>
#define MAX_N 1121
#define MAX_K 25
#define MAX_P 187

using namespace std;

int mat[MAX_N][MAX_P][MAX_K];

bool criba[MAX_N];
vector<int>primes;

int K;

void sieve(){
	
	for(int i=2;i<MAX_N;i++)if(!criba[i]){
		primes.push_back(i);
		for(int j=i*i;j<MAX_N;j+=i){
			criba[j] = true;
		}
	}
	//cout<<primes.size()<<endl;
}

void init(){
	
	for(int i=0;i<MAX_N;i++){
		for(int j=0;j<MAX_P;j++){
			for(int k=0;k<MAX_K;k++){
				mat[i][j][k] = -1;		
			}
		}
	}
}

int count_ways(int w, int k, int id){
	
	if(w==0 && k==0){
		return 1;
	}
	
	if(id>=primes.size())
		return 0;
	
	if(w<0 || k<0)
		return 0;
	
	if(primes[id]>w)
		return 0;
	
	if(mat[w][id][k]==-1){
		return mat[w][id][k] = count_ways(w-primes[id],k-1,id+1)+
							count_ways(w,k,id+1);
	}
	return mat[w][id][k];
}

int main(){
	
	sieve();
	
	//freopen("entrada.txt","r",stdin);
	//freopen("salida.txt","w",stdout);
	
	int n,k;
	int r;
	
	while(scanf("%d%d",&n,&k)){
		if(!n && !k)
			break;
		
		init();
		r = count_ways(n,k,0);
		printf("%d\n",r);
	}
	
	return 0;
}
