// Problema:	437 - The Tower of Babylon
// Autor:	FernandoJerezano
// Fecha:	02-Septiembre-2017
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Block{

	int x,y,z;
	int dim[3];
	
	Block(){}
	Block(int a, int b, int c){
		x = a;
		y = b;
		z = c;
		dim[0] = a;
		dim[1] = b;
		dim[2] = c;
	}
	
	bool operator<(const Block &b){
		for(int i=0;i<3;i++){
			if(dim[i]>b.dim[i])
				return 1;
			else if(dim[i]<b.dim[i])
				return 0;
		}
		return 0;
	}
};

vector<Block>vec;

int maximo(int a, int b){
	return a > b ? a : b;
}

int c;

void LIS(){
	int max = 0;
	int n = vec.size();
	int lis[n];
	
	for(int i=0;i<n;i++){
		lis[i] = vec[i].z;
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(((vec[j].x > vec[i].x && vec[j].y > vec[i].y) || 
			   (vec[j].x > vec[i].y && vec[j].y > vec[i].x)) &&
			   lis[i]<lis[j]+vec[i].z){
				lis[i] = lis[j]+vec[i].z;
			}
		}
	}
	
	for(int i=0;i<n;i++){
		max = maximo(max,lis[i]);
	}
	printf("Case %d: maximum height = %d\n",c,max);
}

int main(){
	
	//freopen("entrada.txt","r",stdin);
	//freopen("salida.txt","w",stdout);
	
	int n;
	int x,y,z;
	c = 1;
	while(scanf("%d",&n) && n){
		vec.clear();
		while(n--){
			scanf("%d%d%d",&x,&y,&z);
			vec.push_back(Block(x,y,z));
			vec.push_back(Block(x,z,y));
			vec.push_back(Block(y,x,z));
			vec.push_back(Block(y,z,x));
			vec.push_back(Block(z,x,y));
			vec.push_back(Block(z,y,x));
		}
		sort(vec.begin(),vec.end());
		LIS();
		c++;
	}
		
	return 0;
}
