#ifndef HASH_H
#define HASH_H

#include "aluno.h"

class Hash {
private:
    int max_itens;
    int max_posicoes;
    int colisoes;
    Aluno* estrutura;
    int sondagemLinear(int ra);
public:
    Hash(int t);
    ~Hash();
    bool estacheio() const;
    int obterTamanhoAtual() const;
    int obterColisoes() const;
    void inserir(Aluno a);
    bool buscar(int ra, Aluno& resultado);
    bool remover(int ra);
    void imprimir() const;
    void imprimirEstatisticas() const;
    void limpar();
};

int funcaoHash(int chave, int max_posicoes);

#endif
