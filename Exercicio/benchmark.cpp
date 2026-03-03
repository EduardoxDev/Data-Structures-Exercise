#include "benchmark.h"
#include <iostream>
#include <random>

using namespace std;

void Benchmark::testarInsercao(Hash& hash, int quantidade) {
    auto inicio = chrono::high_resolution_clock::now();
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(100000, 999999);
    
    for (int i = 0; i < quantidade; i++) {
        int ra = dis(gen);
        Aluno a(ra, "Teste" + to_string(i));
        hash.inserir(a);
    }
    
    auto fim = chrono::high_resolution_clock::now();
    auto duracao = chrono::duration_cast<chrono::microseconds>(fim - inicio);
    
    cout << "  Insercoes: " << quantidade << endl;
    cout << "  Tempo: " << duracao.count() / 1000.0 << " ms" << endl;
    cout << "  Media: " << duracao.count() / (double)quantidade << " us/operacao" << endl;
}

void Benchmark::testarBusca(Hash& hash, int quantidade) {
    auto inicio = chrono::high_resolution_clock::now();
    
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(100000, 999999);
    
    int encontrados = 0;
    for (int i = 0; i < quantidade; i++) {
        int ra = dis(gen);
        Aluno temp;
        if (hash.buscar(ra, temp)) encontrados++;
    }
    
    auto fim = chrono::high_resolution_clock::now();
    auto duracao = chrono::duration_cast<chrono::microseconds>(fim - inicio);
    
    cout << "  Buscas: " << quantidade << endl;
    cout << "  Encontrados: " << encontrados << endl;
    cout << "  Tempo: " << duracao.count() / 1000.0 << " ms" << endl;
    cout << "  Media: " << duracao.count() / (double)quantidade << " us/operacao" << endl;
}

void Benchmark::relatorioCompleto(Hash& hash) {
    cout << "\n  +========================================+" << endl;
    cout << "  |     RELATORIO DE PERFORMANCE           |" << endl;
    cout << "  +========================================+" << endl;
    
    cout << "\n  >>> Teste de Insercao <<<" << endl;
    testarInsercao(hash, 100);
    
    cout << "\n  >>> Teste de Busca <<<" << endl;
    testarBusca(hash, 100);
}
