//
// Created by 201810357 on 12/05/2018.
//

/**
 *  A partir da fórmula do Comprimento da Circunferência “C=2*pi*r”
 *  podemos extrair uma fórmula para  calcular o raio “r=C/(2*pi)”.
 *  Escreva um programa que pergunte ao pizzaiolo se ele quer calcular
 *  C ou r de uma pizza, receba as entradas necessárias, calcule e mostre C ou r da pizza
 *  (considere pi = 3.14).
 * */

#include <ios>
#include <iostream>
#include <limits>

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

    static inline std::string GetString(){
        std::string value;
        while(SCANF(value)){
            std::cout << "Digite uma string válida!" << std::endl;
            std::cin.clear();
        }
        return value;
    }
};

int main(){
    const double PI = 3.14;

    std::cout << "Olá, seja bem-vindo ao cálculo da pizza." << std::endl;

    std::cout << "Digite C se deseja calcular o comprimento da pizza dado seu raio." << std::endl;

    std::cout << "Digite R se deseja calcular o raio da pizza dado o seu comprimento. " << std::endl;

    std::string Opcao;



        while (true){
            std::cin >> Opcao;

            if(Opcao == "C"){
                break;
            } else if(Opcao == "R"){
                break;
            } else{
                std::cout << "Opção inválida, digite novamente";
                Opcao.clear();
            }
        }

        std::cout << std::endl;

    if(Opcao == "C"){
        std::cout << "Digite o raio da pizza: ";

        auto raio = Teclado::GetNumero<double>();

        std::cout << "Comprimento da pizza = " << (2*PI*raio) << std::endl;
    }else if(Opcao == "R"){
        std::cout << "Digite o comprimento da pizza: ";

        auto comprimento = Teclado::GetNumero<double>();

        std::cout << "Raio da pizza = " << (comprimento/(2*PI)) << std::endl;
    }

}



