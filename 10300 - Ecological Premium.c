// Problema: 10300 - Ecological Premium
// Autor:    FernandoJerezano
// Fecha:    04-Febrero-2018
#include <stdio.h>

int main(){

    int f,t;
    int a,b,c;
    long long int s;

    while(scanf("%d",&t) && t!=EOF){
        while(t--){

            scanf("%d",&f);
            s = 0;

            while(f--){

                scanf("%d%ld%d",&a,&b,&c);
                s += (long long int)a*c;
            }
            printf("%lld\n",s);
        }
    }

    return 0;
}
