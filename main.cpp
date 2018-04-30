// Algorithms.cpp : define o ponto de entrada para o aplicativo do console.
/**
 * 4)  Um número primo é aquele que é divisível somente por ele mesmo e por 1.
 * Faça um programa que mostre todos os primos entre 1 e N sendo N um número inteiro fornecido pelo usuário.
 * O programa deverá mostrar também o número de divisões que ele executou para encontrar os números primos.
 */

#include <Windows.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <mutex>

// Algoritmo para pegar o tempo decorrido em milisegundos para fazer uma medição de desempenho
long long milliseconds_now() {
    auto TimeNow = std::chrono::high_resolution_clock::now().time_since_epoch();

    return std::chrono::duration_cast<std::chrono::milliseconds>(TimeNow).count();
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

bool isPrime(unsigned long long n, unsigned long long &count)
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

    for (unsigned long long i = 5; i * i <= n; i = i + 6) {
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
    std::vector<unsigned long long> NumerosPrimos;
    std::cout << "Olá, digite um numero que deseja encontrar os primos de 1 até este número: ";

    unsigned long long number;

    //SCANF(number);
    number = Teclado::GetNumero<unsigned long long>();

    std::cout << std::endl;

    std::chrono::time_point<std::chrono::system_clock> ClockStart = std::chrono::high_resolution_clock::now();

    std::string TimeDate;

    toString(ClockStart, TimeDate);

    std::cout << "Iniciando computação em: " << TimeDate << std::endl;

    std::cout << std::endl;

    unsigned long long count = 0;
    unsigned long long TempCount = 0;

    for (unsigned long long i = 1; i < number; i += 2) {
        if (isPrime(i, TempCount)) {
            NumerosPrimos.push_back(i);
            count += TempCount;
        }
    }

    bool prime = isPrime(number, TempCount);

    count += TempCount;

    std::chrono::time_point<std::chrono::system_clock> ClockEnd = std::chrono::high_resolution_clock::now();

    long long elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(ClockEnd - ClockStart).count();

    toString(ClockEnd, TimeDate);

    std::cout << "Calculando o numero: " << number << std::endl
              << "Numeros primos entre 1 e " << number << ": ";

    std::for_each(NumerosPrimos.begin(), NumerosPrimos.end(), [](int Numero){
        std::cout << Numero << " ";
    });

    std::cout << std::endl;

    std::cout << "Esse numero é primo: " << (prime ? "sim" : "nao") << std::endl
              << "Divisoes Realizadas: " << count << std::endl
              << "Tempo Gasto: " << elapsed << "ms" << std::endl
              << "Tempo agora: " << TimeDate << std::endl;

    std::cout << std::endl;

    std::cout << "Aluno: Davi Ficanha Henrique "<< std::endl
              << "Nota: 1.5 realizada todas as atividades pedidas." << std::endl;


    system("pause");
    return 0;
}

