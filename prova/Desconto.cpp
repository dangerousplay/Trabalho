//
// Created by 201810357 on 12/05/2018.
//
#include <iostream>
#include <limits>
#include <string>
#include <cstring>

/**
 *  Levando em conta a alíquota do imposto de renda, abaixo descrita,
 *  faça um programa para calcular o desconto mensal de acordo com um
 *  salário mensal informado pelo usuário. Após a entrada do valor do
 *  salário mostre o valor mensal descontado e o valor anual como no
 *  exemplo abaixo:
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
};



int main() {

    double Salario = 0;
    double Desconto = 0;

    std::cout << "Olá, vamos calcular a aliquota de seu salário. " << std::endl;
    std::cout << "Digite o seu salário: ";

    Salario = Teclado::GetNumero<double>();

    if(Salario > 1787.78 && Salario < 2679.29){
        Desconto = 0.075;
    } else if(Salario > 2679.29 && Salario < 3572.43){
        Desconto = 0.15;
    } else if(Salario > 3572.43 && Salario < 4463.81){
        Desconto = 0.225;
    } else if(Salario > 4463.81){
        Desconto = 0.275;
    }

    std::cout << std::endl;


    const double SalarioAnual = Salario*12;
    const double DescontoMensal = (Salario*Desconto);
    const double DescontoAnual = (Salario*Desconto*12);


    std::cout << "Desconto de " << "R$" << (DescontoMensal) << " mensal, desconto de " << (Desconto*100) << "%" << std::endl;

    std::cout << "Seu salário bruto anual: " << SalarioAnual << std::endl;

    std::cout << "Seu salário líquido mensal: " << (Salario - DescontoMensal);

    if(Desconto != 0 ){
        std::cout << " incluído desconto de " << "R$" << (DescontoMensal);
    }

    std::cout << std::endl;



    std::cout << "Seu salário líquido anual: " << (SalarioAnual - DescontoAnual);

    if(Desconto != 0){
        std::cout << " incluído desconto de " << "R$" << (DescontoAnual);
    }

    std::cout << std::endl;

    std::cout << std::endl;

    std::cout << "Valor pago de imposto anual: " << DescontoAnual << std::endl;
}