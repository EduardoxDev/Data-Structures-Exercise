#ifndef VALIDADOR_H
#define VALIDADOR_H

#include <string>

class Validador {
public:
    static bool validarRA(int ra);
    static bool validarNome(const std::string& nome);
    static std::string obterMensagemErro();
private:
    static std::string mensagemErro;
};

#endif
