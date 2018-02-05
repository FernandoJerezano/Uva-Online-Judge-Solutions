// Problema: 10189 - Minesweeper
// Autor:    FernandoJerezano
// Fecha:    04-Febrero-2018
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#define M 105
#define N 105

using namespace std;

//ofstream out("s.txt");

int r,c;

int rd[] = {-1,-1, 0, 1, 1, 1, 0,-1};
int cd[] = { 0,-1,-1,-1, 0, 1, 1, 1};

char mapa[M][N];
int int_map[M][N];
char row[M];

int is_valid(int i, int j){
    return (i>=0 && i<r && j>=0 && j<c);
}

int count_mines(int x, int y){

    int cont = 0;
    int a,b;
    //printf("Coord: %d %d\n",x,y);
    for(int i=0;i<8;i++){
        a = x+rd[i];
        b = y+cd[i];
        if(is_valid(a,b) && mapa[a][b]=='*'){
            cont++;

            //printf("Mina: %d %d\n",a,b);

        }
    }
    return cont;
}

void gen_tab(){

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(mapa[i][j]=='.'){
                //printf("%d %d\n",i,j);
                int_map[i][j] = count_mines(i,j);
            }
        }
    }
}

void print_tab(){

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){

            if(mapa[i][j]=='*'){
                printf("*");
                //out<<"*";
            }else{
                printf("%d",int_map[i][j]);
                //out<<int_map[i][j];
            }
        }
        printf("\n");
        //out<<"\n";
    }
}

int main(){
    int casos = 1;
    scanf("%d%d",&r,&c);
    while(1){

        if(!r && !c)
            break;
        for(int i=0;i<r;i++){
            scanf("%s",&row);
            for(int j=0;j<c;j++){
                mapa[i][j] = row[j];
                int_map[i][j] = 0;
            }
        }
        /*
        printf("\n");
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                printf("%c",mapa[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        */
        gen_tab();
        printf("Field #%d:\n",casos);
        //out<<"Field #"<<casos<<":\n";
        print_tab();

        scanf("%d%d",&r,&c);
        if(c!=0 && r!=0){
            printf("\n");
            //out<<"\n";
        }
        casos++;


    }

    return 0;
}
