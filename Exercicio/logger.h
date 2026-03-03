#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>

class Logger {
private:
    static std::ofstream arquivo;
    static bool inicializado;
public:
    static void inicializar(const std::string& nomeArquivo = "sistema.log");
    static void registrar(const std::string& mensagem);
    static void fechar();
};

#endif
