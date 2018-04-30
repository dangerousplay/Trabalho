//
// Created by GMDAV on 29/04/2018.
//

/*
 *  2) Faça um programa que receba dois números inteiros e mostre os números que estão no intervalo compreendido por eles.
 *  Além disso, a soma de todos os valores.
 */

#include <Windows.h>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <chrono>
#include <iomanip>


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


constexpr size_t log10(size_t xx) { return xx == 1 ? 0 : 1 + log10(xx / 10); }

//Convertendo o tempo da std::chrono::Time_point para uma string para posteriormente ser imprimida
template<typename TimePoint>
inline bool toString(const TimePoint &timePoint, std::string &str) {
    uint64_t feconds = timePoint.time_since_epoch().count() * TimePoint::period::num;
    time_t tt = feconds / TimePoint::period::den;
    std::ostringstream oss;
    oss << std::put_time(std::localtime(&tt), "%Y-%m-%d %H:%M:%S.")
        << std::setw(log10((size_t) TimePoint::period::den)) << std::setfill('0') << feconds % TimePoint::period::den;
    return oss && (str = oss.str(), true);
}


//Convertendo de uma string para um objeto std::chrono::time_point
template<typename TimePoint>
bool fromString(TimePoint &timePoint, const std::string &str) {
    std::istringstream iss(str);
    std::tm tm{};
    if (!(iss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S")))
        return false;
    timePoint = {};
    timePoint += std::chrono::seconds(std::mktime(&tm));
    if (iss.eof())
        return true;
    if (iss.get() != '.')
        return false;
    std::string zz;
    if (!(iss >> zz))
        return false;
    static_assert(std::chrono::high_resolution_clock::period::den % 10 == 0);
    zz.resize(log10((size_t) std::chrono::high_resolution_clock::period::den), '0');
    size_t zeconds = 0;
    try { zeconds = std::stoul(zz); } catch (const std::exception &) { return false; }
    timePoint += std::chrono::high_resolution_clock::duration(zeconds);
    return true;
}

//Loop para melhorar a performance, utilizar recursão causa overhead, pode causar Stack Over Flow
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

int main() {
    unsigned long long NumeroFibonacci = 0;
    unsigned long long Argumento = 0;

    std::cout << "Ola, digite o enesimo numero que deseja calcular da serie de fibonacci: ";

    Argumento = Teclado::GetNumero<unsigned long long>();

    std::chrono::time_point<std::chrono::system_clock> ClockStart = std::chrono::high_resolution_clock::now();

    NumeroFibonacci = fibonacci(Argumento);

    std::chrono::time_point<std::chrono::system_clock> ClockEnd = std::chrono::high_resolution_clock::now();

    std::string DateTime;

    toString(ClockEnd, DateTime);

    std::cout << std::endl;

    long long TempoDecorrido = std::chrono::duration_cast<std::chrono::milliseconds>(ClockEnd - ClockStart).count();

    std::cout << "Calculando: " << Argumento << std::endl;
    std::cout << "Resultado: " << NumeroFibonacci << std::endl;
    std::cout << "Tempo Decorrido: " << TempoDecorrido << "ms" << std::endl;
    std::cout << "Tempo agora: " << DateTime << std::endl;

    std::cout << std::endl;

    std::cout << "Aluno: Davi Ficanha Henrique " << std::endl
              << "Nota: 1.5 realizada todas as atividades pedidas." << std::endl;


    system("pause");
    return 0;
}


