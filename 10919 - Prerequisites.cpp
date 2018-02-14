// Problema: 10919 - Prerequisites?
// Autor:    FernandoJerezano
// Fecha:    11-Febrero-2018
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("entrada.txt","r",stdin);
	//freopen("salida.txt","w",stdout);
	vector<string> mat1;
	map<string,int> mapa;
	
	int k,m;
	int c,r;
	int cont = 0;
	string s,p;
	bool res;
	while(cin>>k && k){

		cin>>m;
		
		for(int i=0;i<k;i++){
			cin>>s;
			mapa[s] = i;
		}
		
		res = true;
		
		while(m--){
			cont = 0;
			cin>>c>>r;
			for(int	i=0;i<c;i++){
				
				cin>>p;
				
				if(mapa.count(p)){
					cont++;
				}
			}
			if(cont<r){
				res = false;
			}
		}
		
		if(res)
			printf("yes\n");
		else
			printf("no\n");
		mapa.clear();
	}
	
	return 0;
}
