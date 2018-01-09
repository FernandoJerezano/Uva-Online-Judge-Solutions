// Problema: 11340 - Newspaper
// Autor:    FernandoJerezano
// Fecha:    02-Enero-2018
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	//freopen("entrada.txt","r",stdin);
	//freopen("salida.txt","w",stdout);
	
	map<char,int> mapa;
	int t,m;
	string s;
	string k;
	int tot,v;
	
	cin>>t;
	while(t--){
		cin>>m;
		mapa.clear();
		while(m--){
			cin>>k>>v;
			mapa[k[0]] = v;
		}
		
		cin>>m;
		cin.ignore();
		tot = 0;
		while(m--){
			getline(cin,s);
			//cout<<"Leyendo: "<<s<<endl:
			for(int i=0;i<s.size();i++){
				tot += mapa[s[i]];
			}
		}
		printf("%.2f$\n",tot/100.0);
	}
	
	
	return 0;
}
