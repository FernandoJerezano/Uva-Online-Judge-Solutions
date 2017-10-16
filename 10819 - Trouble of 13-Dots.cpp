// Problema: 10819 Trouble of 13-Dots
// Autor:    FernandoJerezano
// Fecha:    15-Octubre-2017
#include <iostream>
#include <bits/stdc++.h>
#define MAX_N 105
#define MAX_M 10205
#define INF -10000000

using namespace std;

int table[MAX_N][MAX_M];

int p[MAX_N];
int f[MAX_N];

int n,m;

void init(){
	int i,j;
	for(i=0;i<MAX_N;i++){
		for(j=0;j<MAX_M;j++){
			table[i][j] = -1;
		}
	}
}

int maximo(int a, int b){
	return a>b ? a : b;
}

int dp_rec(int id, int w){
	if(w>m && m<1800){
		return INF;
	}
	
	if(w>m+200){
		return INF;
	}
	
	if(id==n){
		if(w>m && w<=2000)
			return INF;
		return 0;
	}
	if(table[id][w]==-1){
		return table[id][w] = maximo(dp_rec(id+1,w),f[id]+dp_rec(id+1,w+p[id]));
	}
	
	return table[id][w];
	
}

int main(){
	
	//freopen("entrada.txt","r",stdin);
	//freopen("salida.txt","w",stdout);
	
	int res;
	
	while(scanf("%d%d",&m,&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d%d",&p[i],&f[i]);
		}
		init();
		res = dp_rec(0,0);
		printf("%d\n",res);
	}
	
	return 0;
}

