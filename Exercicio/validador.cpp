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

bool Validador::validarIdade(int idade) {
    if (idade < 0) {
        mensagemErro = "Idade nao pode ser negativa";
        return false;
    }
    if (idade > 100) {
        mensagemErro = "Idade deve ser menor que 100";
        return false;
    }
    return true;
}

std::string Validador::obterMensagemErro() {
    return mensagemErro;
}

bool Validador::validarMoradia(const std::string& moradia) {
    if (moradia.empty()) {
        mensagemErro = "Moradia nao pode estar vazia";
        return false;
    }
    if (moradia.length() < 3) {
        mensagemErro = "Moradia deve ter pelo menos 3 caracteres";
        return false;
    }
    if (moradia.length() > 100) {
        mensagemErro = "Moradia deve ter no maximo 100 caracteres";
        return false;
    }
    return true;
}
