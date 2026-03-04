#include <iostream>
#include "hash.h"

using namespace std;

int funcaoHash(int chave, int max_posicoes) {
    return chave % max_posicoes;
}

Hash::Hash(int t) {
    max_itens = 0;
    max_posicoes = t;
    estrutura = new Aluno[max_posicoes];
}

Hash::~Hash() {
    delete[] estrutura;
}

bool Hash::estacheio() {
    return max_itens == max_posicoes;
}

int Hash::obterTamanhoAtual() {
    return max_itens;
}

void Hash::inserir(Aluno a) {
    if (estacheio()) {
        
    }
}

void Hash::imprimir() {
    for (int i = 0; i < max_posicoes; i++) {
        if (estrutura[i].obterRa() != 0) {
            cout << "RA: " << estrutura[i].obterRa() << ", Nome: " << estrutura[i].obterNome() << endl;
        }
    }
}
