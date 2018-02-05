// Problema: 192 - Greedy Gift Givers
// Autor:    FernandoJerezano
// Fecha:    04-Febrero-2018
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Person{
	
	int money;
	int give;
	int rec;
	int acq;
	int ind;
	string name;
	
	Person(string n){
		name = n;
	}
	
	Person(string n, int m, int a,int i){
		name = n;
		give = rec = 0;
		money = m;
		acq = a;
		ind = i;
	}
};

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	//freopen("entrada.txt","r",stdin);
	//freopen("salida.txt","w",stdout);
	
	vector<Person> people;
	map<string,int> names;
	
	int total;
	string name;
	int money;
	int acq;
	int p;
	
	cin>>total;
	
	while(true){
		//cout<<"Personas: ";
		
		//cout<<"Nombres: ";
		for(int i=0;i<total;i++){
			cin>>name;
			names[name] = i;
			people.push_back(name);
			people[i].rec = 0;
		}
		
		for(int i=0;i<total;i++){
			//cout<<"Lista: ";
			cin>>name>>money>>acq;
			
			people[names[name]].money = money;
			people[names[name]].acq = acq;
			
			for(int j=0;j<acq;j++){
				cin>>name;
				p = names[name];
				people[p].rec += money/acq;
				//cout<<people[p].name<<" recibe: "<<money/acq<<endl;
			}
		}
		
		for(int i=0;i<total;i++){
			
			name = people[i].name;
			if(people[i].acq==0){
				money = people[i].rec;
			}else{
				money = people[i].rec-people[i].money/people[i].acq*people[i].acq;
			}
			cout<<name<<" "<<money<<"\n";
			//cout<<people[i].money<<" "<<people[i].acq<<" "<<people[i].rec<<endl;
		}
		cin>>total;
		if(cin.eof())
			break;
		else
			cout<<"\n";
		
		people.clear();
		names.clear();
		
	}
	return 0;
}
