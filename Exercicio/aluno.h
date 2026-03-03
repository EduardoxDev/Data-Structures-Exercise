#ifndef ALUNO_H
#define ALUNO_H

#include <string>

class Aluno {
private:
    int ra;
    std::string nome;
    bool ativo;
public:
    Aluno();
    Aluno(int r, std::string n);
    int obterRa() const;
    std::string obterNome() const;
    bool estaAtivo() const;
    void desativar();
};

#endif
