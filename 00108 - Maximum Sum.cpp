// Problema:	108 - Maximum Sum
// Autor:		  FernandoJerezano
// Fecha:		  08-Septiembre-2017
#include <bits/stdc++.h>
#define MAX_N 105

int mat[MAX_N][MAX_N];

int maximo(int a, int b){
	return a>b?a:b;
}

int max_sub_2d(int n){
	
	int max_sub_rect = -127*100*100;
	int sub_rect;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++)
		for(int k=i;k<n;k++) for(int l=j;l<n;l++){
			sub_rect = mat[k][l];
			if(i>0) sub_rect -= mat[i-1][l];
			if(j>0) sub_rect -= mat[k][j-1];
			if(i>0 && j>0) sub_rect += mat[i-1][j-1];
			max_sub_rect = maximo(max_sub_rect,sub_rect);
		}
	return max_sub_rect;
	
}

int main(){
	
	//freopen("entrada.txt","r",stdin);
	//freopen("salida.txt","w",stdout);
	
	int n;
	int r;
	int a;
	
	while(scanf("%d",&n)!=EOF){
	
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&a);
				mat[i][j] = a;		
				if(i>0)	mat[i][j] += mat[i-1][j];
				if(j>0) mat[i][j] += mat[i][j-1];
				if(i>0 && j>0){
					mat[i][j] -= mat[i-1][j-1];
				}
			}
		}
		r = max_sub_2d(n);
		printf("%d\n",r);
	}
	
	return 0;
}
