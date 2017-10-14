// Problema: 10667 - Largest Block
// Nombre:   FernandoJerezano
// Fecha:    14-Octubre-2017
#include <bits/stdc++.h>
#define MAX_N 105

using namespace std;

int mat[MAX_N][MAX_N];

void init(int s){
	
	for(int i=0;i<s;i++){
		for(int j=0;j<s;j++){
			mat[i][j] = 1;
		}
	}
}

void block(int r1, int c1, int r2, int c2){
	
	for(int i=r1;i<=r2;i++){
		for(int j=c1;j<=c2;j++){
			mat[i][j] = 0;
		}
	}	
}

int max_2d_rect(int s){
	
	for(int i=1;i<s;i++){
		for(int j=0;j<s;j++){
			if(mat[i][j]==1){
				mat[i][j] = mat[i-1][j]+1;
			}
		}
	}
	
	int cont = 0;
	int max = -1;
	
	for(int i=0;i<s;i++){
		for(int j=0;j<s;j++){
			cont = mat[i][j];
			for(int k=j+1;k<s && mat[i][j]<=mat[i][k];k++){
				cont+=mat[i][j];
			}
			for(int k=j-1;k>=0 && mat[i][j]<=mat[i][k];k--){
				cont+=mat[i][j];
			}
			if(cont>max)
				max = cont;
		}
	}
	return max;
	
}

void print_mat(int s){
	
	int i,j;
	
	for(i=0;i<s;i++){
		for(j=0;j<s;j++){
			printf("%d",mat[i][j]);
		}
		printf("\n");
	}
}

int main(){
	
	int t;
	int s,b;
	int r1,r2;
	int c1,c2;
	int r;
	
	//freopen("entrada.txt","r",stdin);
	//freopen("salida.txt","w",stdout);
	
	scanf("%d",&t);
	
	while(t--){
		scanf("%d",&s);
		init(s);
		scanf("%d",&b);
		for(int i=0;i<b;i++){
			scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
			block(r1-1,c1-1,r2-1,c2-1);
		}
		
		r = max_2d_rect(s);
		printf("%d\n",r);
	}
	return 0;
}
