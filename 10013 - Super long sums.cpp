// Problema: 10013 - Super long sums
// Autor:    FernandoJerezano
// Fecha:    28-Diciembre-2017
#include <iostream>
#include <bits/stdc++.h>
#define MAX_N 1000001

using namespace std;

int num1[MAX_N];
int num2[MAX_N];
int res[MAX_N];

int n,m;
int a1,a2;

void sum(){
	int sum = 0;
	int carry = 0;
	for(int i=m-1;i>=0;i--){
		sum = num1[i]+num2[i] + carry;
		carry = 0;

		if(sum>9){
			carry = 1;
			sum %=10;
		}
		res[i] = sum;
	}
	printf("%d",carry*10+res[0]);
	
	for(int i=1;i<m;i++){
		printf("%d",res[i]);
	}
	printf("\n");
}

int main(){
	
	//freopen("entrada.txt","r",stdin);
	//freopen("salida.txt","w",stdout);
	
	scanf("%d",&n);
	
	while(n--){
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			scanf("%d%d",&num1[i],&num2[i]);
		}
		sum();
		if(n!=0)
			printf("\n");
	}
	


	return 0;
}
