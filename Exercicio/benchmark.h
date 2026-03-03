#ifndef BENCHMARK_H
#define BENCHMARK_H

#include "hash.h"
#include <chrono>

class Benchmark {
public:
    static void testarInsercao(Hash& hash, int quantidade);
    static void testarBusca(Hash& hash, int quantidade);
    static void relatorioCompleto(Hash& hash);
private:
    static double medirTempo(void (*funcao)(Hash&, int), Hash& hash, int param);
};

#endif
