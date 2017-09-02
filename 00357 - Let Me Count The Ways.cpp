// Problema:    357 - Let Me Count The Ways
// Autor:       FernandoJerezano
// Fecha:       27-Agosto-2017
#include <iostream>
#include <bits/stdc++.h>
#define MAX 30001

using namespace std;

typedef long long int ll;

ll ways[MAX];

void count_ways(){

    ll cents[] = {1,5,10,25,50};
    int cs = sizeof(cents)/sizeof(cents[0]);

    for(ll i=0;i<MAX;i++){
        ways[i] = 0;
    }

    ways[0] = 1;

    for(ll i=0;i<cs;i++){
        for(ll j=cents[i];j<MAX;j++){
            ways[j] += ways[j-cents[i]];
        }
    }
}

int main(){

    //freopen("entrada.txt","r",stdin);
    //freopen("salida.txt","w",stdout);

    count_ways();

    ll n;

    while(scanf("%lld",&n)!=EOF){
        if(ways[n]==1){
            printf("There is only 1 way to produce %lld cents change.\n",n);
        }else{
            printf("There are %lld ways to produce %lld cents change.\n",ways[n],n);
        }
    }
    
    return 0;
}
