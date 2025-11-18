#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "pilha.hpp"
#include <iostream>

using namespace std;

// declarações (as funções estão em outro arquivo .cpp seu)
void lerArquivo(const string& nomeArquivo);

int main() {
    string nome;

    cout << "Digite o nome do arquivo a ser analisado: ";
    cin >> nome;

    cout << "\nAnalisando arquivo...\n";
    lerArquivo(nome);

    return 0;
}
