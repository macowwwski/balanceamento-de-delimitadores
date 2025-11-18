#include <iostream>
#include "pilha.hpp"

using namespace std;

No::No() {  //verificar para que serve essa func
    this->dado = ' ';
    this->prox = nullptr;
    this->ant = nullptr;
}

No::No(char caracter) {
    this->dado = caracter;
    this->prox = nullptr;
    this->ant = nullptr;
}


Pilha::Pilha() {
    this->topo = nullptr;
    this->qtde = 0;
}

Pilha::~Pilha() {
    No* aux;
    while (this->topo != nullptr) {
        aux = this->topo;
        this->topo = this->topo->ant;
        delete aux;
    }
}

bool Pilha::push_inserir(char caracter) {
    No* novo = new No(caracter);

    if (this->topo != nullptr) {
        novo->ant = this->topo;
        this->topo->prox = novo;
    }
    this->topo = novo;
    this->qtde++;
    return true;
}

bool Pilha::pop_remover() {
    if (this->qtde == 0) {
        return false;
    }

    No* aux = this->topo;

    if (this->topo->ant != nullptr) {
        this->topo = this->topo->ant;
        this->topo->prox = nullptr;
    } else {
        this->topo = nullptr;
    }

    delete aux;
    this->qtde--;
    return true;
}

void Pilha::print() {
    cout << "[";
    No* aux = this->topo;
    while (aux != nullptr) {
        cout << aux->dado << " ";
        aux = aux->ant;
    }
    cout << "]" << endl;
}
