// Problema:    674 - Coin Change
// Autor:       FernandoJerezano
// Fecha:       27-Agosto-2017
#include <iostream>
#include <bits/stdc++.h>
#define MAX 8001

using namespace std;

int ways[MAX];

void count_ways(){

    int cents[] = {1,5,10,25,50};
    int cs = sizeof(cents)/sizeof(cents[0]);

    for(int i=0;i<MAX;i++){
        ways[i] = 0;
    }

    ways[0] = 1;

    for(int i=0;i<cs;i++){
        for(int j=cents[i];j<=MAX;j++){
            ways[j] += ways[j-cents[i]];
        }
    }
}

int main(){

    //freopen("entrada.txt","r",stdin);
    //freopen("salida.txt","w",stdout);

    int cents;

    count_ways();
    while(scanf("%d",&cents)!=EOF){
        printf("%d\n",ways[cents]);

    }
    
    return 0;
}

