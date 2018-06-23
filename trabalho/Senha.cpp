//
// Created by 201810357 on 23/06/2018.
//


/*1. Senha e confirmação de senha. Faça um programa em C que solicite ao usuário que digite uma senha, coloque-a em uma string,
 * solicite que digite novamente a senha para confirmar, coloque-a em outra string. Compare as duas e indique se estão exatamente
 * iguais ou diferentes.*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <windef.h>
#include <afxres.h>


typedef struct String {

private:
    char *characters = nullptr;
    int index = 0;
    size_t size;

public:
    explicit String(size_t capacity) {
        size = capacity;
        allocate(capacity);
    }

    explicit String() {
        size = 10;
        allocate(size);
    }

    ~String() {
        delete[] characters;
    }

    template<typename T>
    void append(T character) {
        if (index + 1 >= size) {
            size += 5;
            auto *newString = (char *) calloc(sizeof(char), size);
            memcpy(newString, characters, size);

            delete[] characters;

            characters = newString;
        }

        characters[index++] = character;
    }

    void allocate(size_t size) {
        characters = (char *) calloc(sizeof(char), size);
    }

    bool operator==(String &other) {
        return strcmp(characters, other.characters) == 0;
    }

    bool equalsIgnoreCase(String &other) {
        return strcasecmp(other.characters, characters) == 0;
    }

    size_t getSize() {
        return size;
    }

    void clear() {
        index = 0;
        size = 10;
        delete[] characters;

        characters = (char *) calloc(sizeof(char), 10);
    }
};

#define limitSize true

int main() {
    size_t tamanho = 36;


    String senha = limitSize ? String(tamanho) : String();
    String confirmacao = limitSize ? String(tamanho) : String();

    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hStdin, &mode);

    mode &= ~ENABLE_ECHO_INPUT;

    SetConsoleMode(hStdin, mode);

    printf("Olá, digite a sua senha");

    if (limitSize) {
        printf(" (Máximo %i carácteres): ", tamanho);
    } else {
        printf(": ");
    }


    for (int ch = getchar(); ch != '\n'; ch = getchar()) {
        putchar('*');
        senha.append(ch);
    }


    putchar('\n');

    printf("Confirme sua senha: ");

    for (int ch = getchar(); ch != '\n'; ch = getchar()) {
        putchar('*');
        confirmacao.append(ch);
    }

    putchar('\n');
    putchar('\n');

    if (senha == confirmacao) {
        printf("Senhas corretas.");
    } else {
        printf("Senhas não correspondem!");
    }


}
