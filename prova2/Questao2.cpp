//
// Created by 201810357 on 07/07/2018.
//


#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>

/**
 *  2. Desenvolva um programa que solicite ao usuário que digite um texto. Colocar esse texto em uma string.
 *  Após a digitação apresente a estatística de quantas letras,
 *  quantos espaços e quantos caracteres diferentes de letra e espaço o texto possui.
 *
 * */

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

    char * getCharacters(){
        return characters;
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

    size_t getStringSize(){
        return static_cast<size_t>(index);
    }

    bool containsChar(char character){
        for(int i = 0; i < strlen(characters); i++){
            if(characters[i] == character)
                return true;
        }

        return false;
    }

    void clear() {
        index = 0;
        size = 10;
        delete[] characters;

        characters = (char *) calloc(sizeof(char), 10);
    }
};

bool isDigit(char c){
    switch (c){
        case '0':
            return true;
        case '1':
            return true;
        case '2':
            return true;
        case '3':
            return true;
        case '4':
            return true;
        case '5':
            return true;
        case '6':
            return true;
        case '7':
            return true;
        case '8':
            return true;
        case '9':
            return true;
        default:
            return false;
    }
}


int main(){
    printf("Digite um texto: ");
    String texto;

    int espacos = 0;
    int letrasDiferentes = 0;
    int letras = 0;
    size_t size = 0;

    for (int ch = getchar(); ch != '\n'; ch = getchar()) {
        texto.append(ch);
    }

    char* stringBuffer = texto.getCharacters();

    size = texto.getStringSize();

    String buffer;


    for(int i = 0; i < size; i++){
        char c = stringBuffer[i];

        if(c == ' '){
            espacos++;
        } else if(isalpha(c) && !isDigit(c)) {
            letras++;
        } else if(!isDigit(c)){
            letrasDiferentes++;
        }
    }

    printf("Caracteres digitados: %i \n",texto.getStringSize());
    printf("Letras digitadas: %i \n", letras);
    printf("Espaços: %i \n",espacos);
    printf("Caracteres diferentes de letras e espaços: %i \n", letrasDiferentes);



}
