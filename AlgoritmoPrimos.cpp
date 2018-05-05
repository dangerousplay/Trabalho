//
// Created by 201810357 on 05/05/2018.
//

#include <cstdio>
#include <iostream>

int main(){
    int Numero = 0;
    int Divisoes = 0;

    printf("Digite até o número que deseja saber se é primo: ");

    scanf("%i", &Numero);

    if(Numero >= 2)
        printf("2 ");

    if(Numero >= 3)
        printf("3 ");

    for(int i = 4; i < Numero; i++){
        bool Primo = false;

        if(i % 2 == 0){
            Divisoes++;
        }else if(i % 3 == 0) {
            Divisoes++;
        }else{
            for(int x = 2; x < i; x++){
                if(i % x == 0){
                    Divisoes++;
                    Primo = false;
                    break;
                }else{
                    if(x == (i-1)){
                        Primo = true;
                        break;
                    }
                }
            }
        }

        if(Primo){
            printf("%i ", i);
        }

    }

    printf("\n");
    printf("Divisões realizadas: %i", Divisoes);

}

