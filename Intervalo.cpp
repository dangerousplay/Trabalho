// Algorithms.cpp : define o ponto de entrada para o aplicativo do console.

/**
 *  2) Faça um programa que receba dois números inteiros e mostre os números que estão no intervalo compreendido por eles.
 *  Além disso, a soma de todos os valores.
 */

#include <Windows.h>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

#define MAX(a,b) a > b ? a:b
#define MIN(a,b) a < b ? a:b

template<typename T>
inline BOOL SCANF(T &Value) {
    return !(std::cin >> Value);
}

//Classe para facilitiar o recebimento das informações do usuário e para previnir de erros como input incorreto
class Teclado {
public:
    template<typename T>
    static inline T GetNumero() {
        T Value;
        while (SCANF(Value)) {
            std::cout << "Digite um número válido" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        return Value;
    }
};



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
    int PrimeiroNumero, SegundoNumero;

    long long SomaNumeros = 0;

    std::cout << "Ola, digite o intervalo entre dois numeros que sera mostrado: ";

    //SCANF(PrimeiroNumero);
    //SCANF(SegundoNumero);
    PrimeiroNumero = Teclado::GetNumero<int>();

    std::cout << " e ";

    SegundoNumero = Teclado::GetNumero<int>();

    std::cout << std::endl;

    //Pegando os números que estão no intervalo compreendido
    for (int i = (MIN(PrimeiroNumero, SegundoNumero))+1; i < (MAX(PrimeiroNumero, SegundoNumero)); i++) {
        NumerosInteiros.push_back(i);
    }

    std::cout << std::endl;

    std::cout << "Listando numeros entre " << PrimeiroNumero << " e " << SegundoNumero << ":" << std::endl;

    std::cout << std::endl;

    //Soma os elementos de uma lista utilizando std::accumulate
    SomaNumeros = std::accumulate(NumerosInteiros.begin(), NumerosInteiros.end(), 0);

    //Imprimindo os números inteiros da lista utilizando iterator do std
    std::for_each(NumerosInteiros.begin(), NumerosInteiros.end(), [](int Number) {
        std::cout << Number << std::endl;
    });

    std::cout << std::endl;

    std::cout << "Soma dos numeros: " << SomaNumeros << std::endl;

    std::cout << std::endl;

    std::cout << "Aluno: Davi Ficanha Henrique "<< std::endl
              << "Nota: 1.5 realizada todas as atividades pedidas." << std::endl;


    system("pause");
    return 0;
}

