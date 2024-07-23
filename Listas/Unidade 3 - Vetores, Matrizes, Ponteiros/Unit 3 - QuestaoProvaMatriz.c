#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define M 1
#define N 5
#define U 3

void cadastraCartela(int cartela[][N]){
    for (int i = 0; i <M; i++){
        printf("Digite os números da cartela %d \n",i+1);
        for (int j=0;j<N;j++){
            printf("\n Digite o numero: ");
            cartela[i][j]=i+j;
        }
    }
}

void cadastraResultado(int resultado[]){
    printf("Digite os numeros sorteados\n");
    for (int i = 0; i<U;i++){
        printf("Digite o numero: ");
        resultado[i] = i+1; 
    }
}

void computaPontos(int cartela[][N], int resultado[], int pontos[]){
    int totalPontos = 0;
    for (int i=0;i<M;i++){
        for (int j=0;j<N;j++){
            for (int k = 0;k<U;k++){
                if(cartela[i][j]==resultado[k]){
                    totalPontos++;
                }
            }
        }
        pontos[i] =totalPontos;
    }
    
}

void imprimePontos(int pontos){
  for(int i = 0; i<M;i++){
    printf("\n Pontos da cartela %d e %d", i+1,pontos[i]);
  }
}

int main(){
    int cartela[M][N];
    int resultado[U];
    int pontos[M];
    cadastraCartela(cartela);
    cadastraResultado(resultado);
    computaPontos(cartela,resultado,pontos);
    imprimePontos(pontos);
}