// Problema:    147 - Dollars
// Autor:       FernandoJerezano
// Fecha:       27-Agosto-2017
#include <iostream>
#include <bits/stdc++.h>
#define MAX 30001

using namespace std;

typedef long long int ll;

ll ways[MAX];

void count_ways(){
    ll i,j;

    ll cents[] = {5,10,20,50,100,200,500,1000,2000,5000,10000};
    ll cs = sizeof(cents)/sizeof(cents[0]);
    //printf("C: %lld\n",cs);

    for(i=0;i<MAX;i++){
        ways[i] = 0;
    }

    ways[0] = 1;

    for(i = 0; i<cs;i++){
        for(j = cents[i];j<MAX;j+=5){
            ways[j] += ways[j-cents[i]];
        }
    }

}

int main(){

    //freopen("entrada.txt","r",stdin);
    //freopen("salida.txt","w",stdout);

    double d;
    double d2;
    ll n;
    count_ways();

    while(true){
        scanf("%lf",&d);
        d2 = d;
        d2 = d2*10.0;
        n = (ll)(d2*10.0);
        if(n==0)
            break;
        if(n<10000){
            printf("% 6.2lf% 17lld\n",d,ways[n]);
        }else{
            printf("%.2lf% 17lld\n",d,ways[n]);
        }
    }
    return 0;
}
