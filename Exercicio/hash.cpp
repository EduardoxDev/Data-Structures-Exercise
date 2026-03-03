#include <iostream>
#include "hash.h"

using namespace std;

int funcaoHash(int chave, int max_posicoes) {
    return chave % max_posicoes;
}

Hash::Hash(int t) {
    max_itens = 0;
    max_posicoes = t;
    colisoes = 0;
    estrutura = new Aluno[max_posicoes];
}

Hash::~Hash() {
    delete[] estrutura;
}

bool Hash::estacheio() const {
    return max_itens == max_posicoes;
}

int Hash::obterTamanhoAtual() const {
    return max_itens;
}

int Hash::obterColisoes() const {
    return colisoes;
}

int Hash::sondagemLinear(int ra) {
    int posicao = funcaoHash(ra, max_posicoes);
    int inicio = posicao;
    
    while (estrutura[posicao].obterRa() != 0 && estrutura[posicao].obterRa() != ra) {
        posicao = (posicao + 1) % max_posicoes;
        if (posicao == inicio) return -1;
        colisoes++;
    }
    return posicao;
}

void Hash::inserir(Aluno a) {
    if (estacheio()) {
        return;
    }
    
    int posicao = sondagemLinear(a.obterRa());
    if (posicao != -1 && estrutura[posicao].obterRa() == 0) {
        estrutura[posicao] = a;
        max_itens++;
    }
}

bool Hash::buscar(int ra, Aluno& resultado) {
    int posicao = funcaoHash(ra, max_posicoes);
    int inicio = posicao;
    
    while (estrutura[posicao].obterRa() != 0) {
        if (estrutura[posicao].obterRa() == ra && estrutura[posicao].estaAtivo()) {
            resultado = estrutura[posicao];
            return true;
        }
        posicao = (posicao + 1) % max_posicoes;
        if (posicao == inicio) break;
    }
    return false;
}

bool Hash::remover(int ra) {
    int posicao = funcaoHash(ra, max_posicoes);
    int inicio = posicao;
    
    while (estrutura[posicao].obterRa() != 0) {
        if (estrutura[posicao].obterRa() == ra && estrutura[posicao].estaAtivo()) {
            estrutura[posicao].desativar();
            max_itens--;
            return true;
        }
        posicao = (posicao + 1) % max_posicoes;
        if (posicao == inicio) break;
    }
    return false;
}

void Hash::imprimir() const {
    cout << "\n+" << string(60, '-') << "+" << endl;
    cout << "| " << "TABELA HASH - ALUNOS CADASTRADOS" << string(27, ' ') << "|" << endl;
    cout << "+" << string(60, '-') << "+" << endl;
    
    bool encontrou = false;
    for (int i = 0; i < max_posicoes; i++) {
        if (estrutura[i].obterRa() != 0 && estrutura[i].estaAtivo()) {
            cout << "| Pos: " << i << " | RA: " << estrutura[i].obterRa() 
                 << " | Nome: " << estrutura[i].obterNome() << endl;
            encontrou = true;
        }
    }
    
    if (!encontrou) {
        cout << "| " << "Nenhum aluno cadastrado" << string(36, ' ') << "|" << endl;
    }
    cout << "+" << string(60, '-') << "+" << endl;
}

void Hash::imprimirEstatisticas() const {
    float fatorCarga = (float)max_itens / max_posicoes * 100;
    
    cout << "\n+" << string(50, '=') << "+" << endl;
    cout << "| " << "ESTATISTICAS DA TABELA HASH" << string(22, ' ') << "|" << endl;
    cout << "+" << string(50, '=') << "+" << endl;
    cout << "| Capacidade Total: " << max_posicoes << string(30 - to_string(max_posicoes).length(), ' ') << "|" << endl;
    cout << "| Itens Armazenados: " << max_itens << string(29 - to_string(max_itens).length(), ' ') << "|" << endl;
    cout << "| Espacos Livres: " << (max_posicoes - max_itens) << string(32 - to_string(max_posicoes - max_itens).length(), ' ') << "|" << endl;
    cout << "| Colisoes Totais: " << colisoes << string(31 - to_string(colisoes).length(), ' ') << "|" << endl;
    cout << "| Fator de Carga: " << fatorCarga << "%" << string(29 - to_string((int)fatorCarga).length(), ' ') << "|" << endl;
    cout << "+" << string(50, '=') << "+" << endl;
}

void Hash::limpar() {
    delete[] estrutura;
    estrutura = new Aluno[max_posicoes];
    max_itens = 0;
    colisoes = 0;
}