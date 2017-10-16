// Problema: 11658 - Best Coalitions
// Nombre:   FernandoJerezano
// Fecha:    15-Octubre-2017
#include <iostream>
#include <bits/stdc++.h>
#define INF -10000000
#define MAX_N 105
#define MAX_P 10005

using namespace std;

int shares[MAX_N];
double table[MAX_N][MAX_P];

int n,x;

void init(){
	
	int i,j;
	
	for(i=0;i<MAX_N;i++){
		for(int j=0;j<MAX_P;j++){
			table[i][j] = -1;
		}
	}
}

double maximo(double a, double b){
	return a>b?a:b;
}

double dp_rec(int id, int sha){
	
	//printf("%d %d\n",id,sha);
	
	if(id!=x){
		if(id>=n){
			if(sha<=5000){
				return INF;
			}
			if(sha!=0)
				return (double)shares[x]*100/(double)sha;
			return INF;
		}
		
		if(table[id][sha]==-1){
			return table[id][sha] = maximo(dp_rec(id+1,sha),dp_rec(id+1,sha+shares[id]));
		}
		return table[id][sha];
	}
	return dp_rec(id+1,sha);
}

int main(){
	
	double sha;
	double res;
	int mod;
	int a,b;
	
	//freopen("entrada.txt","r",stdin);
	//freopen("salida.txt","w",stdout);
	
	while(scanf("%d%d",&n,&x)){
		if(!n && !x)
			break;
		
		for(int i=0;i<n;i++){
			scanf("%d.%d",&a,&b);
			shares[i] = a*100+b;
		}
		init();
		x--;
		res = dp_rec(0,shares[x]);
		mod = ((int)(res*1000))%10;
		if(mod>=5)
			res = ceil(res*100)/100;
		else
			res = floorl(res*100)/100;
		printf("%.2lf\n",res);
		
	}
	
	return 0;
}
