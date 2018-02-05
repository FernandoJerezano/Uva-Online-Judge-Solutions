// Problema: 10550 - Combination Lock
// Autor:    FernandoJerezano
// Fecha:    04-Febrero-2018
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

//ofstream out("s.txt");

int abs(int a){
    return a>0 ? a : a*-1;
}

int main(){

    int p,a,b,c;
    int total;
    while(1){
        scanf("%d%d%d%d",&p,&a,&b,&c);
        if(!a && !b && !c && !p)
            break;
        total = 360*3;

        if(p==a){
            //total+=360;
        }else{
            if(p>a){
                total+=(p-a)*9;
            }else{
                total+=(40-a+p)*9;
            }
        }
        p = a;
        if(p==b){
            //total+=360;
        }else{
            if(p>b){
                total+=(40-p+b)*9;
            }else{
                total+=(b-p)*9;
            }
        }
        p = b;
        if(p==c){
            //total+=360;
        }else{
            if(p>c){
                total+=(p-c)*9;
            }else{
                total+=(40-c+p)*9;
            }
        }

        printf("%d\n",total);
        //out<<total<<"\n";

    }

    return 0;
}
