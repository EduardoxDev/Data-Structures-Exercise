#include "aluno.h"

class Hash {
    private:
    int FuncaoHash(Aluno aluno);
    int max_itens;
    int max_posicoes;
    int quant_itens;
    Aluno* estrutura;

    public:
    Hash(int t);
    ~Hash();
    bool estacheio();
    int obterTamanhoAtual();
    int funcaoHash(int chave);
    void inserir(Aluno a);
    Aluno* buscar(Aluno& aluno, bool& busca);
    void remover(int ra);
    void imprimir();
};
