#include <cstdio>
#include <cstdlib>


int main(){
    int PrimeiroMaior = 0;
    int SegundoMaior = 0;

    int PrimeiroMenor = 0;
    int SegundoMenor = 0;

    float SomaPositiva = 0;
    float SomaTotal = 0;
    int Media = 0;

    int NumerosPositivos = 0;



    int count = 0;
    while(count < 20){

        printf("Digite o numero %i: ", count);

        int numero;

        //strtol("%i", &numero,10);
        scanf("%i", &numero);

        if(count == 0){
            PrimeiroMaior = numero;
            PrimeiroMenor = numero;
        }

        if(count == 1){
            SegundoMaior = numero;
            SegundoMenor = numero;
        }

        // 5 9 10

        if(numero > PrimeiroMaior){
            SegundoMaior = PrimeiroMaior;
            PrimeiroMaior = numero;
        }else{
            if(numero > SegundoMaior){
                SegundoMaior = numero;
            }
        }

        if(numero < PrimeiroMenor){
            SegundoMenor = PrimeiroMenor;
            PrimeiroMenor = numero;
        }else {
            if (numero < SegundoMenor) {
                SegundoMenor = numero;
            }
        }

        if(numero > 0){
            SomaPositiva += numero;
            NumerosPositivos++;
        }

        SomaTotal += numero;

        count++;
    }

    printf("\n");

    double MediaPositiva = 0;
    if(NumerosPositivos > 0){
        MediaPositiva = (double)(SomaPositiva/NumerosPositivos);
    }

    double MediaTotal = (double)SomaTotal/20;

    printf("A media dos numeros positivos: %f \n", MediaPositiva);
    printf("A media total dos numeros: %f \n", MediaTotal);
    printf("O Maior numero e %i \n", PrimeiroMaior);
    printf("O Segundo Maior numero e %i \n", SegundoMaior);
    printf("O Menor numero e %i \n", PrimeiroMenor);
    printf("O Segundo menor numero e %i \n", SegundoMenor);

}

