//
// Created by 201810357 on 07/07/2018.
//

#include <cstdio>

/**
 *  1. Desenvolver um programa que crie um vetor com 15 posições,
 *  solicite ao usuário que preencha esse vetor com os valores pares.
 *  Caso um valor digitado não seja par, solicite ao usuário que digite novamente, no mesmo instante.
 * */


int main(){
    int numeros[15];

    printf("Olá, digite 15 valores pares.\n\n");

    for(int i = 0; i < 15; i++){
        int valor = 0;
        printf("%i - ", i+1);
        do{
            scanf("%i",&valor);
            if(valor % 2 != 0){
                printf("Digite um valor par!\n");
                printf("%i - ", i+1);
            } else{
                numeros[i] = valor;
            }
        }while (valor % 2 != 0);
    }


    printf("Valores digitados: \n\n");

    for(int i = 0; i < 15; i++){
        printf("Valor[%i] = %i \n", i, numeros[i]);
    }

}

