#include <iostream>
#include <iomanip>
#include <limits>
#include "hash.h"
#include "validador.h"
#include "logger.h"
#include "benchmark.h"

using namespace std;

void limparTela() {
    system("cls");
}

void pausar() {
    cout << "\nPressione ENTER para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void exibirCabecalho() {
    cout << "\n";
    cout << "  " << string(70, '=') << endl;
    cout << "  ||" << string(66, ' ') << "||" << endl;
    cout << "  ||" << string(15, ' ') << "SISTEMA DE GERENCIAMENTO DE ALUNOS" << string(15, ' ') << "||" << endl;
    cout << "  ||" << string(20, ' ') << "Tabela Hash com Colisoes" << string(22, ' ') << "||" << endl;
    cout << "  ||" << string(66, ' ') << "||" << endl;
    cout << "  " << string(70, '=') << endl;
}

void exibirMenu() {
    cout << "\n  +" << string(50, '-') << "+" << endl;
    cout << "  |" << string(20, ' ') << "MENU PRINCIPAL" << string(16, ' ') << "|" << endl;
    cout << "  +" << string(50, '-') << "+" << endl;
    cout << "  | 1. Inserir Aluno" << string(33, ' ') << "|" << endl;
    cout << "  | 2. Buscar Aluno" << string(34, ' ') << "|" << endl;
    cout << "  | 3. Remover Aluno" << string(33, ' ') << "|" << endl;
    cout << "  | 4. Listar Todos os Alunos" << string(23, ' ') << "|" << endl;
    cout << "  | 5. Exibir Estatisticas" << string(26, ' ') << "|" << endl;
    cout << "  | 6. Limpar Tabela" << string(33, ' ') << "|" << endl;
    cout << "  | 7. Executar Benchmark" << string(28, ' ') << "|" << endl;
    cout << "  | 0. Sair do Sistema" << string(31, ' ') << "|" << endl;
    cout << "  +" << string(50, '-') << "+" << endl;
    cout << "\n  Escolha uma opcao: ";
}

int main() {
    Logger::inicializar();
    Logger::registrar("Sistema iniciado pelo usuario");
    
    Hash hash(20);
    int opcao, ra;
    string nome;
    int idade;
    
    do {
        limparTela();
        exibirCabecalho();
        exibirMenu();
        
        cin >> opcao;
        
        switch(opcao) {
            case 1: {
                limparTela();
                exibirCabecalho();
                cout << "\n  >>> INSERIR NOVO ALUNO <<<\n" << endl;
                
                if (hash.estacheio()) {
                    cout << "  [ERRO] Tabela cheia! Nao e possivel inserir mais alunos." << endl;
                    Logger::registrar("Tentativa de insercao em tabela cheia");
                } else {
                    cout << "  Digite o RA: ";
                    cin >> ra;
                    
                    if (!Validador::validarRA(ra)) {
                        cout << "  [ERRO] " << Validador::obterMensagemErro() << endl;
                        Logger::registrar("Validacao falhou: RA invalido - " + to_string(ra));
                    } else {
                        cin.ignore();
                        cout << "  Digite o Nome: ";
                        getline(cin, nome);
                        
                        if (!Validador::validarNome(nome)) {
                            cout << "  [ERRO] " << Validador::obterMensagemErro() << endl;
                            Logger::registrar("Validacao falhou: Nome invalido");
                        } else {
                            cout << "  Digite a Idade: ";
                            cin >> idade;
                            
                            if (!Validador::validarIdade(idade)) {
                                cout << "  [ERRO] " << Validador::obterMensagemErro() << endl;
                                Logger::registrar("Validacao falhou: Idade invalida - " + to_string(idade));
                                else {
                                    cout << "  Digite a Moradia: ";
                                    cin.ignore();
                                    string moradia;
                                    getline(cin, moradia);
                                    if (!Validador::validarMoradia(moradia)) {
                                        cout << "  [ERRO] " << Validador::obterMensagemErro() << endl;
                                        Logger::registrar("Validacao falhou: Moradia invalida");
                                    } else {
                            } else {
                            Aluno temp;
                            if (hash.buscar(ra, temp)) {
                                cout << "\n  [AVISO] Aluno com RA " << ra << " ja existe!" << endl;
                                Logger::registrar("Tentativa de inserir RA duplicado: " + to_string(ra));
                            } else {
                                Aluno a(ra, nome, idade);
                                hash.inserir(a);
                                cout << "\n  [SUCESSO] Aluno inserido com sucesso!" << endl;
                                Logger::registrar("Aluno inserido: RA=" + to_string(ra) + ", Nome=" + nome + ", Idade=" + to_string(idade));
                            }
                        }
                    }
                }
                pausar();
                break;
            }
            
            case 2: {
                limparTela();
                exibirCabecalho();
                cout << "\n  >>> BUSCAR ALUNO <<<\n" << endl;
                cout << "  Digite o RA: ";
                cin >> ra;
                
                Aluno resultado;
                if (hash.buscar(ra, resultado)) {
                    cout << "\n  [ENCONTRADO]" << endl;
                    cout << "  RA: " << resultado.obterRa() << endl;
                    cout << "  Nome: " << resultado.obterNome() << endl;
                    Logger::registrar("Busca bem-sucedida: RA=" + to_string(ra));
                } else {
                    cout << "\n  [NAO ENCONTRADO] Aluno com RA " << ra << " nao existe." << endl;
                    Logger::registrar("Busca falhou: RA=" + to_string(ra));
                }
                pausar();
                break;
            }
            
            case 3: {
                limparTela();
                exibirCabecalho();
                cout << "\n  >>> REMOVER ALUNO <<<\n" << endl;
                cout << "  Digite o RA: ";
                cin >> ra;
                
                if (hash.remover(ra)) {
                    cout << "\n  [SUCESSO] Aluno removido com sucesso!" << endl;
                    Logger::registrar("Aluno removido: RA=" + to_string(ra));
                } else {
                    cout << "\n  [ERRO] Aluno com RA " << ra << " nao encontrado." << endl;
                    Logger::registrar("Remocao falhou: RA=" + to_string(ra));
                }
                pausar();
                break;
            }
            
            case 4: {
                limparTela();
                exibirCabecalho();
                hash.imprimir();
                Logger::registrar("Listagem de alunos visualizada");
                pausar();
                break;
            }
            
            case 5: {
                limparTela();
                exibirCabecalho();
                hash.imprimirEstatisticas();
                Logger::registrar("Estatisticas visualizadas");
                pausar();
                break;
            }
            
            case 6: {
                limparTela();
                exibirCabecalho();
                cout << "\n  >>> LIMPAR TABELA <<<\n" << endl;
                cout << "  Tem certeza? (1-Sim / 0-Nao): ";
                int confirma;
                cin >> confirma;
                
                if (confirma == 1) {
                    hash.limpar();
                    cout << "\n  [SUCESSO] Tabela limpa com sucesso!" << endl;
                    Logger::registrar("Tabela limpa pelo usuario");
                } else {
                    cout << "\n  [CANCELADO] Operacao cancelada." << endl;
                }
                pausar();
                break;
            }
            
            case 7: {
                limparTela();
                exibirCabecalho();
                cout << "\n  >>> BENCHMARK DE PERFORMANCE <<<\n" << endl;
                Hash hashTeste(1000);
                Benchmark::relatorioCompleto(hashTeste);
                Logger::registrar("Benchmark executado");
                pausar();
                break;
            }
            
            case 0: {
                limparTela();
                exibirCabecalho();
                cout << "\n  Encerrando o sistema..." << endl;
                cout << "  Obrigado por usar o Sistema de Gerenciamento de Alunos!\n" << endl;
                Logger::registrar("Sistema encerrado pelo usuario");
                Logger::fechar();
                break;
            }
            
            default:
                cout << "\n  [ERRO] Opcao invalida! Tente novamente." << endl;
                pausar();
        }
    } while(opcao != 0);
    
    return 0;
}
