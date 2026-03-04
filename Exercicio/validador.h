#ifndef VALIDADOR_H
#define VALIDADOR_H

#include <string>

class Validador {
public:
    static bool validarRA(int ra);
    static bool validarNome(const std::string& nome);
    static bool validarIdade(int idade);
    static bool validarMoradia(const std::string& moradia);
    static std::string obterMensagemErro();
private:
    static std::string mensagemErro;
};

#endif
