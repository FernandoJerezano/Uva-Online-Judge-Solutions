// Prpblema:    11137 - Ingenuous Cubrency
// Autor:       FernandoJerezano
// Fecha:       27-Agosto-2017
#include <iostream>
#include <bits/stdc++.h>
#define MAX 10001
using namespace std;

typedef long long int ll;

ll ways[MAX];

ll pow(ll b, ll e){
    ll r = 1;
    ll i = 1;
    for(i=1;i<=3;i++){
        r = r*b;
    }
    return r;
}

void count_ways(){

    ll cubrency[] = {
    1,8,27,64,125,
    216,343,512,729,1000,
    1331,1728,2197,2744,3375,
    4096,4913,5832,6859,8000,
    9261};

    ll cs = sizeof(cubrency)/sizeof(cubrency[0]);

    ll i,j;

    for(i=0;i<MAX;i++){
        ways[i] = 0;
    }

    ways[0] = 1;

    for(i=0;i<cs;i++){
        for(j=cubrency[i];j<MAX;j++){
            ways[j] += ways[j-cubrency[i]];
        }
    }
}

int main(){

    //freopen("entrada.txt","r",stdin);
    //freopen("salida.txt","w",stdout);

    count_ways();

    ll n;

    while(scanf("%lld",&n)!=EOF){
        printf("%lld\n",ways[n]);
    }
    
    return 0;
}
