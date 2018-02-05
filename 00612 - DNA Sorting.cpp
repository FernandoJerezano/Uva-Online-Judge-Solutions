// Problema: 612 - DNA Sorting
// Autor:    FernandoJerezano
// Fecha:    01-Febrero-2018
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Palabra{

    string pal;
    int uns;
    int ind;
    Palabra(){}
    Palabra(string p, int u, int i){
        pal = p;
        uns = u;
        ind = i;
    }
    /*
    bool operator<(const Palabra &p){
        if(p.uns != uns)
            return p.uns > uns;
        return p.ind > ind;
    }
    */
};

int unsortedness(string s){

    int cont = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='A')
            continue;
        for(int j=i+1;j<s.size();j++){
            if(s[i]>s[j])
                cont++;
        }
    }
    return cont;
}

bool cmp(Palabra p1, Palabra p2){

    if(p1.uns != p2.uns )
        return p1.uns < p2.uns;
    return p1.pal < p2.pal;
}

int main(){

    freopen("entrada.txt","r",stdin);
    freopen("salida.txt","w",stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    int n,m;
    int u;
    string s;
    //cin>>t;
    vector<Palabra> pals;
    cin>>n>>m;
    while(n && m){

        pals.clear();

        for(int i=0;i<m;i++){
            cin>>s;
            u = unsortedness(s);
            pals.push_back(Palabra(s,u,i));
        }
        sort(pals.begin(),pals.end(),cmp);

        for(int i=0;i<m;i++){
            cout<<pals[i].pal<<"\n";
        }
        cin>>n>>m;
        if(!n && !m)
            break;
        else
            cout<<"\n";
    }
    return 0;
}
