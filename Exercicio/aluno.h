#include <iostream>'
using namespace std;

class Aluno{
    private:
    int ra;
    string nome;
    int idade;
    string moradia;

    public:
    Aluno();
    Aluno(int r, string n, int i, string m);
    int obterRa();
    string obterNome();
    int obterIdade();
    string obterMoradia();
    };
