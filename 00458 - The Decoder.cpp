// Problema: 458 - The Decoder
// Autor:    FernandoJerezano
// Fecha:    05-Enero-2018
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
	
	freopen("entrada.txt","r",stdin);
	freopen("salida.txt","w",stdout);
	
	string s;
	
	while(1){
		getline(cin,s);
		if(s.size()==0)
			break;
		for(int i=0;i<s.size();i++){
			printf("%c",s[i]-7);
		}
		printf("\n");

	}
	
	return 0;
}
