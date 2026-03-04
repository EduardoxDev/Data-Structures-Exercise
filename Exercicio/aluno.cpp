#include "aluno.h"

  Aluno::Aluno() {
    ra = 0;
    nome = "";
    idade = 0;
    moradia = "";
  }
  Aluno::Aluno(int r, string n, int i) {
    ra = r;
    nome = n;
    idade = i;
    moradia = m;
  }
  int Aluno::obterRa() {
    return ra;
  }
  string Aluno::obterNome() {
    return nome;
  }
  int Aluno::obterIdade() {
    return idade;
  }
  string Aluno::obterMoradia() {
    return moradia;
  }
