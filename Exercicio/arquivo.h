#ifndef ARQUIVO_H
#define ARQUIVO_H

#include <string>
#include "hash.h"

class GerenciadorArquivo {
public:
    static bool salvar(const Hash& hash, const std::string& nomeArquivo);
    static bool carregar(Hash& hash, const std::string& nomeArquivo);
    static bool exportarCSV(const Hash& hash, const std::string& nomeArquivo);
};

#endif
