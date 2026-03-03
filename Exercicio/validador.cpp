#include "validador.h"

std::string Validador::mensagemErro = "";

bool Validador::validarRA(int ra) {
    if (ra <= 0) {
        mensagemErro = "RA deve ser um numero positivo";
        return false;
    }
    if (ra > 999999) {
        mensagemErro = "RA deve ter no maximo 6 digitos";
        return false;
    }
    return true;
}

bool Validador::validarNome(const std::string& nome) {
    if (nome.empty()) {
        mensagemErro = "Nome nao pode estar vazio";
        return false;
    }
    if (nome.length() < 3) {
        mensagemErro = "Nome deve ter pelo menos 3 caracteres";
        return false;
    }
    if (nome.length() > 50) {
        mensagemErro = "Nome deve ter no maximo 50 caracteres";
        return false;
    }
    return true;
}

std::string Validador::obterMensagemErro() {
    return mensagemErro;
}
