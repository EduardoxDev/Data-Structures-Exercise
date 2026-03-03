#include "arquivo.h"
#include <fstream>
#include <iostream>

bool GerenciadorArquivo::salvar(const Hash& hash, const std::string& nomeArquivo) {
    std::ofstream arquivo(nomeArquivo, std::ios::binary);
    if (!arquivo) return false;
    
    int tamanho = hash.obterTamanhoAtual();
    arquivo.write(reinterpret_cast<const char*>(&tamanho), sizeof(tamanho));
    
    arquivo.close();
    return true;
}

bool GerenciadorArquivo::carregar(Hash& hash, const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo, std::ios::binary);
    if (!arquivo) return false;
    
    int tamanho;
    arquivo.read(reinterpret_cast<char*>(&tamanho), sizeof(tamanho));
    
    arquivo.close();
    return true;
}

bool GerenciadorArquivo::exportarCSV(const Hash& hash, const std::string& nomeArquivo) {
    std::ofstream arquivo(nomeArquivo);
    if (!arquivo) return false;
    
    arquivo << "RA,Nome\n";
    arquivo.close();
    return true;
}
