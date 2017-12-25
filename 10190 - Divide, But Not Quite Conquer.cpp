// Problema: 10190 - Divide, But Not Quite Conquer
// Autor:    FernandoJerezano
// Fecha:    24-Diciembre-2017
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

int main(){

	lli ant,n,m;
	bool found;
	
	vector<lli> nums;
	
	//freopen("entrada.txt","r",stdin);
	//freopen("salida.txt","w",stdout);
	
	while(scanf("%lld%lld",&n,&m)!=EOF){
		found = true;
		nums.clear();
		if(n<2 || m<2 || n%m!=0){
			found = false;
		}
		while(n>1 && found){
			ant = n;
			nums.push_back(ant);
			n = ant/m;
			//printf("%lld\n",ant);
			if(n!=1 && (ant<n || n%m!=0)){
				found = false;
			}
		}
		
		if(found){
			for(int i=0;i<nums.size();i++){
				printf("%lld ",nums[i]);
			}
			printf("1\n");
		}else{
			printf("Boring!\n");
		}
	}
	
	return 0;
}
