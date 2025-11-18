#include "pilha.hpp"
#include <iostream>
#include <fstream>
using namespace std;


int analisadorDelimitadores(char c, Pilha* p){
    if (c == '{' || c == '(' || c == '['){      //delimitador de abertura
        p->push_inserir(c);    //empilha o abridor
        return 0;      //tudo certo
    }
    
    else if (c == '}' || c == ')' || c == ']'){     //delimitador de fechamento
        if (p->qtde == 0){
            return 1;   //erro 1: fechamento sem abertura
        }

        else{       //erro 2: fechamento diferente de abertura
            char topo = p->topo->dado;

            if ((c == '}' && topo != '{') ||
            (c == ')' && topo != '(') ||
            (c == ']' && topo != '[')){
                return 2;
            } 

            else{
                p->pop_remover();
                return 0;      //tudo certo
            }
        
        }
        }

    else{
        return 3;      //caractere não importa
    }
}


void lerArquivo(const string& nomeArquivo) {
    ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << nomeArquivo << endl;
        return;
    }

    Pilha p;
    char c;
    int linha = 1;
    int coluna = 0;

    while (arquivo.get(c)) {   
        coluna++;
        
        if (c == '\n'){
            linha++;
            coluna = 0;
        }

        int codigo = analisadorDelimitadores(c, &p);

        if (codigo == 1){
            cout << "Erro: Fechamento sem abertura em linha " 
                 << linha << ", coluna " << coluna << endl;
            return;
        }

        if (codigo == 2) {
            cout << "Erro: Fechamento incompatível na linha " 
                 << linha << ", coluna " << coluna << endl;
            return;
        }   
    }

    //término do arquivo
    if ((p.qtde) != 0){
        cout << "Erro: Delimitadores sem fechamento." << endl;
    } else {
        cout << "Arquivo balanceado." << endl;
    }

    arquivo.close();
}