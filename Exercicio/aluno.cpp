#include "aluno.h"

Aluno::Aluno() : ra(0), nome(""), ativo(false) {}

Aluno::Aluno(int r, std::string n) : ra(r), nome(n), ativo(true) {}

int Aluno::obterRa() const {
    return ra;
}

std::string Aluno::obterNome() const {
    return nome;
}

bool Aluno::estaAtivo() const {
    return ativo;
}

void Aluno::desativar() {
    ativo = false;
}
