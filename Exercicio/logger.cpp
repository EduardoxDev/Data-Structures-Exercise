#include "logger.h"
#include <ctime>
#include <iostream>

std::ofstream Logger::arquivo;
bool Logger::inicializado = false;

void Logger::inicializar(const std::string& nomeArquivo) {
    if (!inicializado) {
        arquivo.open(nomeArquivo, std::ios::app);
        inicializado = true;
        registrar("=== Sistema Iniciado ===");
    }
}

void Logger::registrar(const std::string& mensagem) {
    if (!inicializado) return;
    
    time_t agora = time(0);
    char* dt = ctime(&agora);
    std::string timestamp(dt);
    timestamp.pop_back();
    
    arquivo << "[" << timestamp << "] " << mensagem << std::endl;
    arquivo.flush();
}

void Logger::fechar() {
    if (inicializado) {
        registrar("=== Sistema Encerrado ===");
        arquivo.close();
        inicializado = false;
    }
}
