//
// Created by 201810357 on 12/05/2018.
//
#include <iostream>
#include <limits>

/**
 *  A equipe Ferrari deseja calcular o número mínimo de litros que deverá colocar
 *  no tanque de seu carro para que ele possa percorrer um determinado número de voltas
 *  até o primeiro reabastecimento. Escreva um programa que leia o comprimento da pista (em metros),
 *  o número total de voltas a serem percorridas no grande prêmio, o número de reabastecimentos desejados,
 *  e o consumo de combustível do carro (em Km/L). Calcular e escrever o número mínimo de litros
 *  necessários para percorrer até o primeiro reabastecimento.
 *
 *  OBS: Considere que o número de voltas entre os reabastecimentos é o mesmo.
 *
 * */

template<typename T>
inline T SCANF() {
    T Value;
    std::cin >> Value;
    return Value;
}

template<typename T>
inline bool SCANF(T &Value) {
    return !(std::cin >> Value);
}


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

    template <typename T>
    static inline T GetNumero(T &Value){
        while (SCANF(Value)) {
            std::cout << "Digite um número válido" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        return Value;
    }
};



int main(){

    double Comprimento = 0;

    int NumeroVoltas = 0;
    int Abastecimentos = 0;

    double Consumo = 0;

    std::cout << "Olá, Seja bem-vindo ao cáculo de litros para o reabastecimento" << std::endl;

    std::cout << "Digite o comprimento da pista em metros: ";

    Teclado::GetNumero(Comprimento);

    std::cout << "Digite o número de voltas a serem percorridas: ";

    Teclado::GetNumero(NumeroVoltas);

    std::cout << "Digite o número de reabastecimentos: ";

    Teclado::GetNumero(Abastecimentos);

    std::cout << "Digite o consumo do veículo em Km/L: ";

    Teclado::GetNumero(Consumo);

    const double ConsumoTotal = ((Comprimento/1000) / Consumo)*NumeroVoltas;
    const double ConsumoPorAbastecimento = ConsumoTotal/Abastecimentos;


    std::cout << "Consumo total em litros: " << ConsumoTotal << std::endl;

    std::cout << "Consumo por volta em litros: " << ((Comprimento/1000) / Consumo) << std::endl;

    std::cout << "Número de litros para cada abastecimento: " << ConsumoPorAbastecimento << std::endl;



}
