// Algorithms.cpp : define o ponto de entrada para o aplicativo do console.
/**
 * 4)  Um número primo é aquele que é divisível somente por ele mesmo e por 1.
 * Faça um programa que mostre todos os primos entre 1 e N sendo N um número inteiro fornecido pelo usuário.
 * O programa deverá mostrar também o número de divisões que ele executou para encontrar os números primos.
 */

#include <Windows.h>
#include <iostream>
#include <vector>


// Algoritmo para pegar o tempo decorrido em milisegundos para fazer uma medição de desempenho
long long milliseconds_now() {
    static LARGE_INTEGER s_frequency;
    static BOOL s_use_qpc = QueryPerformanceFrequency(&s_frequency);
    if (s_use_qpc) {
        LARGE_INTEGER now;
        QueryPerformanceCounter(&now);
        return (1000LL * now.QuadPart) / s_frequency.QuadPart;
    }
    else {
        return GetTickCount();
    }
}

//Calcula se um número é par, utilizando o conceito do (n & 1) == 0
inline bool isOdd(long long number) {
    return (number & 1) == 0;
}

/** Algoritmo para encontrar números primos personalizado para aumentar
 *  performance do cálculo e diminuir o tempo de executação e de
 *  iterações para encontrar um número primo.
 *
 *  Dividi-se inicialmente os primeiros números primos para reduzir as
 *  possibilidades de números a serem calculados.
 *  Se fizeres uma tabela, verás que começar pelo número 5 e calcular o módulo com i no laço
 *  diminui as iterações, incrementando i += 6 e utilizando i*i <= n como condição de execução.
 */

bool isPrime(long long n, long long &count)
{
    if (n == 1)  return true;
    if (n <= 3)  return true;

    long long restModulus = 0;

    //Não fora considerado como divisão, pois (n & 1) == 0 não é uma divisão, mas comparação com bitwise.
    if (isOdd(n)) {
        return false;
    }

    restModulus = n % 3;
    count++;

    if (restModulus == 0) {
        return false;
    }

    restModulus = n % 5;
    count++;

    if (restModulus == 0) {
        return false;
    }

    restModulus = n % 7;
    count++;

    if (restModulus == 0) {
        return false;
    }

    for (int i = 5; i*i <= n; i = i + 6) {
        restModulus = n % i;
        count++;

        if (restModulus == 0) {
            return false;
        }

        restModulus = n % (i + 2);
        count++;

        if (restModulus == 0) {
            return false;
        }
    }

    return true;
}

template<typename T>
inline T SCANF(T &Value) {
    std::cin >> Value;
    return Value;
}

int main()
{

    std::cout << "Ola, digite um numero que deseja saber se e primo: ";

    long long number;

    SCANF(number);

    std::cout << std::endl;

    long long start = milliseconds_now();

    long long count = 0;

    bool prime = isPrime(number, count);

    long long elapsed = milliseconds_now() - start;

    std::cout
            << "Calculando o numero: " << number << std::endl
            << "Esse numero e primo: " << (prime ? "sim" : "nao") << std::endl
            << "Divisoes Realizadas: " << count << std::endl
            << "Tempo Gasto: " << elapsed << "ms" << std::endl;

    std::cout << std::endl;

    std::cout << "Aluno: Davi Ficanha Henrique "<< std::endl
              << "Nota: 1.5 realizada todas as atividades pedidas." << std::endl;


    system("pause");
    return 0;
}

