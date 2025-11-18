#ifndef PILHA_HPP
#define PILHA_HPP

#include <iostream>
using namespace std;

class No {
public:
    char dado;
    No* prox;
    No* ant;

    No();
    No(char caracter);
};

class Pilha {
public:
    No* topo;
    int qtde;

    Pilha();
    ~Pilha();

    bool push_inserir(char caracter);
    bool pop_remover();
    void print();
};

#endif
