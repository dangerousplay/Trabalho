//
// Created by 201810357 on 07/07/2018.
//

#include <cstdio>

/**
 *  3. Sabendo que na matemática a sequência de Fibonacci é uma sucessão de números inteiros começando com 0 e1, na qual,
 *  cada termo subsequente corresponde a soma dos dois antecessores (exceto o 1º e 2º),
 *  desenvolva um programa que coloque os N primeiros valores dessa sequência em um vetor.
 *  Considere que N deve ser digitado pelo usuário e não pode ser menor que 2, nem maior que 100.
 *
 * */

unsigned long long fibonacci(unsigned long long n) {
    unsigned long long Resultado = 0;
    unsigned long long Anterior;

    for (int i = 1; i <= n; i++) {
        if (i == 1) {
            Resultado = 1;
            Anterior = 0;
        } else {
            Resultado += Anterior;
            Anterior = Resultado - Anterior;
        }
    }

    //return (n < 2 ? n : fibonacci(n - 1) + fibonacci(n -2));
    return Resultado;
}

//0,1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584
int main(){
    unsigned long long fibon[100];

    for(unsigned long long int i = 0; i < 100; i++){
        fibon[i] = fibonacci(i);
    }

    printf("Digite o Nº número da seqência de fibonacci entre 2 e 100: ");

    int n;
    do {
        scanf("%i", &n);
        if(n < 2 || n > 100){
            printf("Digite um valor entre 2 e 100: ");
        }
    }while(n < 2 || n > 100);

    printf("Nº termo de fibonacci: %llu", fibon[n-1]);

}