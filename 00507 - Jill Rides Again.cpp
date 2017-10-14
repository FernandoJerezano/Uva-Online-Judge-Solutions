// Problema: 507 - Jill Rides Again
// Autor:    FernandoJerezano
// Fecha:    09-Octubre-2017
#include <bits/stdc++.h>
#define MAX_N 20005

using namespace std;

int arr[MAX_N];

void kadane(int n, int caso){
	
	int max_end,max_so_far;
	max_end = max_so_far = 0;
	int max_dif = 0;
	int end = 0;
	int dif = 0;
	int max_value = 0;
	
	for(int i=1;i<n;i++){
		max_end = max_end + arr[i];
		if(max_end < 0){
			max_end = 0;
			dif = 0;
		}else{
			dif++;
			if(max_end>=max_so_far){
				max_so_far = max_end;
			
				if(max_so_far > max_value){
					end = i;
					max_value = max_so_far;
					max_dif = dif;
				}
				if(max_so_far == max_value && dif>max_dif){
					max_dif = dif;
					end = i;
				}
			}
		}
	}
	if(end==0)
		printf("Route %d has no nice parts\n",caso);
	else
		printf("The nicest part of route %d is between stops %d and %d\n",caso,end-max_dif+1,end+1);
	
}

int main(){
	
	//freopen("entrada.txt","r",stdin);
	//freopen("salida.txt","w",stdout);
	
	int t,n;
	
	scanf("%d",&t);
	
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		for(int j=1;j<n;j++){
			scanf("%d",&arr[j]);
		}
		kadane(n,i);
	}
	
	return 0;
}
