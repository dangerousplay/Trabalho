//
// Created by 201810357 on 23/06/2018.
//


/*2. Solicite ao usuário que digite 10 valores inteiros, coloque-os em um vetor.
 * Ordene o vetor em ordem crescente e apresente o vetor digitado sem a ordenação
 * e depois ordenado.*/


//Utilizando apenas C para este exercío
#include <stdlib.h>
#include <stdio.h>

int main() {
    size_t tamanho = 10;

    int *numeros = (int *) calloc(sizeof(int *), tamanho);
    int *numerosOrdenados = (int *) calloc(sizeof(int *), tamanho);

    int index = 0;


    printf("Olá, digite %i números inteiros: \n", tamanho);

    for (int i = 0; i < tamanho; i++, index++) {
        int numero = 0;
        scanf("%i", &numero);
        numeros[index] = numero;
        numerosOrdenados[index] = numero;
    }

    for (int i = 1; i < tamanho; i++) {
        for (int x = 0; x < tamanho - 1; x++) {
            if (numerosOrdenados[x] > numerosOrdenados[x + 1]) {
                int auxiliar = numerosOrdenados[x];

                numerosOrdenados[x] = numerosOrdenados[x + 1];
                numerosOrdenados[x + 1] = auxiliar;

            }
        }
    }


    printf("Ordenando os números de forma crescente: ");

    for (int i = 0; i < tamanho; i++) {
        printf("%i", numeros[i]);
    }

    putchar('\n');

    for (int i = 0; i < tamanho; i++) {
        printf("Numeros[%i] = %i  |  Ordenados[%i] = %i \n", i, numeros[i], i, numerosOrdenados[i]);
    }

}