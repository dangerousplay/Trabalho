// Algorithms.cpp : define o ponto de entrada para o aplicativo do console.
/*
 * 1) Faça um programa que leia do teclado 20 números inteiros (deve usar laço) e depois imprima:
 *    1º soma de todos os elementos;
 *    2º os dois maiores valores e os dois menores valores e;
 *    3º a Média dos elementos positivos.
 */

#include <Windows.h>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

template<typename T>
inline T SCANF(T &Value) {
    std::cin >> Value;
    return Value;
}

//Uma maneira mais simples para facilitar a entrada de informações do usuário
template<typename T>
inline T SCANF() {
    T Value;
    std::cin >> Value;
    return Value;
}

int main()
{
    //Vector dos números inteiros
    std::vector<int> NumerosInteiros;

    //Vector dos números positivos.
    std::vector<unsigned int> NumerosPositivos;

    long long SomaNumeros = 0;

    std::cout << "Ola, digite os 20 numeros inteiros: " << std::endl;


    //Pegando os 20 números do usuário
    for (int i = 0; i < 20; i++) {
        NumerosInteiros.push_back(SCANF<int>());
    }

    //Soma utilizando biblioteca std no Vector de números, seria equivalente a um loop com soma.
    SomaNumeros = std::accumulate(NumerosInteiros.begin(), NumerosInteiros.end(), 0);

    //Sort no vector para pegar os valores maiores e menores posteriormente, os primeiros valores serão os maiores
    std::sort(NumerosInteiros.begin(), NumerosInteiros.end(), [](int first, int seconds) {
        return first > seconds;
    });

    std::cout << "Soma dos numeros digitados e: " << SomaNumeros << std::endl;

    std::cout << std::endl;

    std::cout << "Os dois maiores valores: " << NumerosInteiros[0] << " " << NumerosInteiros[1] << std::endl;

    std::cout << "Os dois menores valores: " << NumerosInteiros[NumerosInteiros.size() - 1] << " " << NumerosInteiros[NumerosInteiros.size() - 2] << std::endl;

    std::cout << std::endl;

    //Na programação funcional seria equivalente a um filter, copia os elementos de um vector se satifazer o condição para que o elemento seja copiado.
    //Copia apenas os valores positivos com zero, pois o mesmo irá influenciar na questão da média.
    std::copy_if(NumerosInteiros.begin(), NumerosInteiros.end(), std::back_inserter(NumerosPositivos), [](int number) {
        return number >= 0;
    });

    //Soma utilizando std::accumulate e divide pelo números de elementos = média dos valores;
    double Media = std::accumulate(NumerosPositivos.begin(), NumerosPositivos.end(), 0.0) / NumerosPositivos.size();

    std::cout << "Media dos valores positivos: " << Media << std::endl << std::endl;

    std::cout << "Aluno: Davi Ficanha Henrique "<< std::endl
              << " Nota: 1.5 realizada todas as atividades pedidas." << std::endl;


    system("pause");
    return 0;
}

