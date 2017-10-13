// Problema: 10131 - Is Bigger Smarter?
// Autor:    FernandoJerezano
// Fecha:    01-Septiembre-2017
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Elephant{
	
	int w,iq,pos;
	Elephant(){}
	Elephant(int W, int IQ, int p){
		w = W;
		iq = IQ;
		pos = p;
	}
	
	bool operator<(const Elephant &E){
		if(E.iq!=iq)
			return iq>E.iq;
	}
};

vector<Elephant> vec;

void LIS(int n){
	
	int lis[n];
	int ind[n];
	int m;
	int mi;
	
	for(int i=0;i<n;i++){
		lis[i] = 1;
		ind[i] = -1;
	}
	
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(vec[i].w>vec[j].w && 
			   vec[j].iq>vec[i].iq &&
			   lis[i]<=lis[j]+1){
				lis[i] = lis[j]+1;
				ind[i] = j;
			}
		}
	}
	
	m = 0;
	mi = 0;
	/*
	printf("----\n");
	printf("I\tPOS\tLIS\tIND\n");
	for(int i=0;i<n;i++){
		printf("%d\t%d\t%d\t%d\n",i,vec[i].pos,lis[i],ind[i]);
	}
	printf("----\n");
	*/
	
	for(int i=0;i<n;i++){
		if(lis[i]>m){
			m = lis[i];
			mi = i;
		}
	}
	
	printf("%d\n",m);
	
	stack<int>s;
	int index = mi;
	while(index!=-1){
		s.push(vec[index].pos);
		//printf("%d\n",vec[index].pos);
		index = ind[index];
	}
	
	int v;
	
	while(!s.empty()){
		v = s.top();
		printf("%d\n",v);
		s.pop();
	}
}

int main(){
	
	int w,iq,pos = 1;
	int n;
	
	//freopen("entrada.txt","r",stdin);
	//freopen("salida.txt","w",stdout);
	
	vec.clear();
	
	while(scanf("%d",&w)!=EOF){
		scanf("%d",&iq);
		vec.push_back(Elephant(w,iq,pos));
		pos++;
	}
	
	sort(vec.begin(),vec.end());
	/*
	for(int i=0;i<vec.size();i++){
		printf("%d\t%d\t%d\n",vec[i].w,vec[i].iq,vec[i].pos);
	}
	*/
	n = vec.size();
	LIS(n);
	
	return 0;
}
