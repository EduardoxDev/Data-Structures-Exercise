<div align="center">

# 🎓 Sistema de Gerenciamento de Alunos
### Implementação Completa de Tabela Hash em C++

[![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![License](https://img.shields.io/badge/license-MIT-blue.svg?style=for-the-badge)](LICENSE)
[![Status](https://img.shields.io/badge/status-active-success.svg?style=for-the-badge)]()

**Um projeto educacional robusto para dominar Estruturas de Dados e Algoritmos**

[Características](#-características-principais) •
[Instalação](#-instalação) •
[Documentação](#-documentação-técnica) •
[Arquitetura](#-arquitetura-do-sistema) •
[Contribuir](#-como-contribuir)

</div>

---

## 📖 Sobre o Projeto

Este é um **sistema completo de gerenciamento acadêmico** desenvolvido do zero como parte de um estudo aprofundado em **Estruturas de Dados e Algoritmos**. O projeto implementa uma tabela hash profissional com tratamento de colisões, validação de dados, sistema de logs, benchmarking e muito mais.

### 🎯 Motivação

Criado com o objetivo de:
- Dominar a implementação de estruturas de dados fundamentais
- Compreender profundamente algoritmos de hashing e resolução de colisões
- Aplicar boas práticas de engenharia de software
- Desenvolver um sistema modular, escalável e bem documentado
- Praticar análise de complexidade algorítmica
- Implementar padrões de design e arquitetura limpa

### 🏆 Diferenciais

- ✨ **Código Limpo**: Seguindo princípios SOLID e Clean Code
- 🔧 **Modular**: Arquitetura bem estruturada e desacoplada
- 📊 **Observável**: Sistema completo de logging e métricas
- ⚡ **Performático**: Otimizado com análise de complexidade
- 🧪 **Testável**: Inclui benchmarks e testes de performance
- 📚 **Documentado**: Código comentado e documentação completa

---

## ✨ Características Principais

### 🎯 Funcionalidades Core

| Funcionalidade | Descrição | Status |
|----------------|-----------|--------|
| **Inserção** | Adiciona alunos com validação completa | ✅ |
| **Busca** | Localiza alunos por RA em O(1) médio | ✅ |
| **Remoção** | Soft delete mantendo integridade | ✅ |
| **Listagem** | Exibe todos os registros formatados | ✅ |
| **Estatísticas** | Métricas detalhadas da tabela | ✅ |
| **Limpeza** | Reset completo da estrutura | ✅ |

### 🚀 Funcionalidades Avançadas

- **🔄 Tratamento de Colisões**: Implementação de Linear Probing com sondagem circular
- **✔️ Validação Robusta**: Sistema completo de validação de entrada
  - RA: 1-999999
  - Nome: 3-50 caracteres
  - Idade: 0-150 anos
  - Moradia: 3-100 caracteres
- **📝 Sistema de Logs**: Registro automático de todas as operações com timestamps
- **⚡ Benchmarking**: Testes de performance para inserção e busca
- **🚫 Prevenção de Duplicatas**: Verificação automática antes da inserção
- **📈 Análise de Carga**: Cálculo dinâmico do fator de carga da tabela
- **💾 Persistência**: Framework para salvar/carregar dados (arquivo.h/cpp)
- **🎨 Interface Rica**: Menu interativo com feedback visual

---

## 🏗️ Arquitetura do Sistema

### 📁 Estrutura de Diretórios

```
Exercicio/
│
├── 📦 Core (Camada de Domínio)
│   ├── aluno.h              # Interface da entidade Aluno
│   ├── aluno.cpp            # Implementação da entidade
│   ├── hash.h               # Interface da Tabela Hash
│   └── hash.cpp             # Implementação com Linear Probing
│
├── 🛠️ Utilities (Camada de Serviços)
│   ├── validador.h          # Interface de validação
│   ├── validador.cpp        # Regras de negócio de validação
│   ├── logger.h             # Interface do sistema de logs
│   ├── logger.cpp           # Implementação com timestamps
│   ├── benchmark.h          # Interface de testes de performance
│   ├── benchmark.cpp        # Implementação de benchmarks
│   ├── arquivo.h            # Interface de persistência
│   └── arquivo.cpp          # Operações de I/O
│
├── 🖥️ Presentation (Camada de Apresentação)
│   └── main_hash.cpp        # Interface CLI com menu interativo
│
├── 📄 Documentação
│   └── README.md            # Este arquivo
│
└── 📊 Outputs (Gerados em runtime)
    └── sistema.log          # Logs de operações
```

### 🔄 Fluxo de Dados

```
┌─────────────┐
│   Usuario   │
└──────┬──────┘
       │
       ▼
┌─────────────────┐
│  main_hash.cpp  │ ◄── Camada de Apresentação
└────────┬────────┘
         │
         ├──► ┌──────────────┐
         │    │  validador   │ ◄── Validação de Entrada
         │    └──────────────┘
         │
         ├──► ┌──────────────┐
         │    │    logger    │ ◄── Registro de Operações
         │    └──────────────┘
         │
         ▼
    ┌─────────┐
    │  hash   │ ◄── Lógica de Negócio
    └────┬────┘
         │
         ▼
    ┌─────────┐
    │  aluno  │ ◄── Entidade de Domínio
    └─────────┘
```

---

## 🔬 Documentação Técnica

### 📊 Estrutura de Dados: Tabela Hash

#### Função Hash (Método da Divisão)
```cpp
int funcaoHash(int chave, int max_posicoes) {
    return chave % max_posicoes;
}
```

**Características:**
- Distribuição uniforme para chaves numéricas
- Complexidade: O(1)
- Ideal para RAs sequenciais ou aleatórios

#### Tratamento de Colisões: Linear Probing

```cpp
int sondagemLinear(int ra) {
    int posicao = funcaoHash(ra, max_posicoes);
    int inicio = posicao;
    
    while (estrutura[posicao].obterRa() != 0 && 
           estrutura[posicao].obterRa() != ra) {
        posicao = (posicao + 1) % max_posicoes;  // Circular
        if (posicao == inicio) return -1;         // Tabela cheia
        colisoes++;
    }
    return posicao;
}
```

**Vantagens:**
- Simplicidade de implementação
- Boa localidade de cache
- Eficiente para baixos fatores de carga

**Desvantagens:**
- Clustering primário
- Degradação com alto fator de carga

#### Soft Delete

```cpp
class Aluno {
    int ra;
    string nome;
    int idade;
    string moradia;
    bool ativo;  // Flag para soft delete
};
```

**Por que Soft Delete?**
- Mantém integridade da sondagem linear
- Evita quebra de cadeias de busca
- Permite recuperação de dados
- Performance consistente

### 📈 Análise de Complexidade

#### Complexidade Temporal

| Operação | Melhor Caso | Caso Médio | Pior Caso | Observações |
|----------|-------------|------------|-----------|-------------|
| **Inserção** | O(1) | O(1) | O(n) | Pior caso: tabela quase cheia |
| **Busca** | O(1) | O(1) | O(n) | Depende do fator de carga |
| **Remoção** | O(1) | O(1) | O(n) | Soft delete mantém O(1) |
| **Listagem** | O(n) | O(n) | O(n) | Percorre toda a tabela |

#### Complexidade Espacial

- **Tabela Hash**: O(n) onde n = capacidade máxima
- **Overhead por Aluno**: ~180 bytes (int + string + int + string + bool)
- **Total**: O(n × 180 bytes)

#### Fator de Carga

```
α = n / m

onde:
  n = número de elementos armazenados
  m = tamanho da tabela
```

**Recomendações:**
- α < 0.5: Performance ótima
- 0.5 ≤ α < 0.7: Performance aceitável
- α ≥ 0.7: Considerar redimensionamento

---

## 🛠️ Tecnologias e Ferramentas

### Linguagem e Padrões

- **C++11/14**: Recursos modernos (auto, range-based for, smart pointers)
- **STL**: Uso extensivo da Standard Template Library
- **OOP**: Programação Orientada a Objetos

### Bibliotecas Utilizadas

| Biblioteca | Propósito | Uso |
|------------|-----------|-----|
| `<iostream>` | I/O padrão | Interface com usuário |
| `<fstream>` | Manipulação de arquivos | Sistema de logs |
| `<string>` | Manipulação de strings | Nomes e mensagens |
| `<chrono>` | Medição de tempo | Benchmarking |
| `<random>` | Números aleatórios | Testes de performance |
| `<limits>` | Limites numéricos | Validação de entrada |

### Ferramentas de Desenvolvimento

- **Compilador**: GCC/G++ 7.0+
- **Build**: Compilação manual via linha de comando
- **Debug**: GDB (GNU Debugger)
- **Versionamento**: Git

---

## 📥 Instalação

### Pré-requisitos

```bash
# Verificar instalação do G++
g++ --version

# Deve retornar versão 7.0 ou superior
```

### Compilação

#### Opção 1: Compilação Simples
```bash
g++ -o hash_program main_hash.cpp hash.cpp aluno.cpp validador.cpp logger.cpp benchmark.cpp arquivo.cpp
```

#### Opção 2: Com Otimizações
```bash
g++ -O3 -std=c++14 -Wall -Wextra -o hash_program main_hash.cpp hash.cpp aluno.cpp validador.cpp logger.cpp benchmark.cpp arquivo.cpp
```

#### Opção 3: Debug Mode
```bash
g++ -g -std=c++14 -Wall -Wextra -o hash_program_debug main_hash.cpp hash.cpp aluno.cpp validador.cpp logger.cpp benchmark.cpp arquivo.cpp
```

### Execução

```bash
# Linux/Mac
./hash_program

# Windows
hash_program.exe
```

---

## 🎮 Guia de Uso

### Interface do Sistema

```
  ======================================================================
  ||                                                                  ||
  ||               SISTEMA DE GERENCIAMENTO DE ALUNOS                ||
  ||                    Tabela Hash com Colisões                     ||
  ||                                                                  ||
  ======================================================================

  +--------------------------------------------------+
  |                  MENU PRINCIPAL                  |
  +--------------------------------------------------+
  | 1. Inserir Aluno                                 |
  | 2. Buscar Aluno                                  |
  | 3. Remover Aluno                                 |
  | 4. Listar Todos os Alunos                        |
  | 5. Exibir Estatísticas                           |
  | 6. Limpar Tabela                                 |
  | 7. Executar Benchmark                            |
  | 0. Sair do Sistema                               |
  +--------------------------------------------------+
```

### Exemplos de Operações

#### 1️⃣ Inserir Aluno

```
>>> INSERIR NOVO ALUNO <<<

Digite o RA: 123456
Digite o Nome: João Silva
Digite a Idade: 20
Digite a Moradia: São Paulo

[SUCESSO] Aluno inserido com sucesso!
```

**Validações Aplicadas:**
- RA deve ser entre 1 e 999999
- Nome deve ter entre 3 e 50 caracteres
- Idade deve ser entre 0 e 150 anos
- Moradia deve ter entre 3 e 100 caracteres
- RA não pode estar duplicado

#### 2️⃣ Buscar Aluno

```
>>> BUSCAR ALUNO <<<

Digite o RA: 123456

[ENCONTRADO]
RA: 123456
Nome: João Silva
Idade: 20
Moradia: São Paulo
```

#### 3️⃣ Estatísticas Detalhadas

```
+==================================================+
|          ESTATÍSTICAS DA TABELA HASH             |
+==================================================+
| Capacidade Total: 20                             |
| Itens Armazenados: 8                             |
| Espaços Livres: 12                               |
| Colisões Totais: 3                               |
| Fator de Carga: 40.0%                            |
+==================================================+
```

#### 4️⃣ Benchmark de Performance

```
>>> BENCHMARK DE PERFORMANCE <<<

+========================================+
|     RELATÓRIO DE PERFORMANCE           |
+========================================+

>>> Teste de Inserção <<<
Inserções: 100
Tempo: 2.456 ms
Média: 24.56 us/operação

>>> Teste de Busca <<<
Buscas: 100
Encontrados: 87
Tempo: 1.234 ms
Média: 12.34 us/operação
```

---

## 📊 Sistema de Logs

### Formato do Log

```
[Mon Dec 16 14:23:45 2024] Sistema iniciado pelo usuario
[Mon Dec 16 14:24:12 2024] Aluno inserido: RA=123456, Nome=João Silva, Idade=20, Moradia=São Paulo
[Mon Dec 16 14:24:45 2024] Busca bem-sucedida: RA=123456
[Mon Dec 16 14:25:03 2024] Aluno removido: RA=123456
[Mon Dec 16 14:25:30 2024] Sistema encerrado pelo usuario
```

### Eventos Registrados

- ✅ Inicialização e encerramento do sistema
- ✅ Inserções (sucesso e falha)
- ✅ Buscas (encontrado e não encontrado)
- ✅ Remoções (sucesso e falha)
- ✅ Validações falhas
- ✅ Operações de limpeza
- ✅ Execução de benchmarks

---

## 🎯 Conceitos de Estrutura de Dados Aplicados

### 1. Hashing

**Definição**: Técnica de mapeamento de chaves para índices de array usando uma função hash.

**Implementação**:
```cpp
// Método da Divisão
h(k) = k mod m
```

**Propriedades Desejáveis**:
- Distribuição uniforme
- Determinística
- Rápida (O(1))
- Minimizar colisões

### 2. Resolução de Colisões

**Linear Probing (Endereçamento Aberto)**:
```
h(k, i) = (h(k) + i) mod m
```

**Características**:
- Busca sequencial por posição livre
- Implementação circular
- Clustering primário

**Alternativas Estudadas**:
- Quadratic Probing: h(k, i) = (h(k) + c₁i + c₂i²) mod m
- Double Hashing: h(k, i) = (h₁(k) + i × h₂(k)) mod m
- Chaining: Lista encadeada por posição

### 3. Gerenciamento de Memória

```cpp
// Alocação dinâmica
estrutura = new Aluno[max_posicoes];

// Liberação no destrutor
~Hash() {
    delete[] estrutura;
}
```

**Boas Práticas**:
- RAII (Resource Acquisition Is Initialization)
- Destrutor para liberar memória
- Evitar memory leaks

### 4. Análise de Performance

**Fator de Carga (Load Factor)**:
```
α = n / m

Performance esperada:
- α = 0.5 → ~1.5 probes por operação
- α = 0.75 → ~4 probes por operação
- α = 0.9 → ~10 probes por operação
```

---

## 🧪 Testes e Validação

### Casos de Teste Implementados

#### Teste de Inserção
- ✅ Inserção em tabela vazia
- ✅ Inserção com colisão
- ✅ Inserção em tabela cheia
- ✅ Prevenção de duplicatas
- ✅ Validação de RA inválido
- ✅ Validação de nome inválido
- ✅ Validação de idade inválida
- ✅ Validação de moradia inválida

#### Teste de Busca
- ✅ Busca em tabela vazia
- ✅ Busca de elemento existente
- ✅ Busca de elemento inexistente
- ✅ Busca após remoção (soft delete)

#### Teste de Remoção
- ✅ Remoção de elemento existente
- ✅ Remoção de elemento inexistente
- ✅ Integridade após remoção

### Benchmark de Performance

**Metodologia**:
1. Inserção de 100 elementos aleatórios
2. Busca de 100 elementos (mix de existentes/inexistentes)
3. Medição com `<chrono>` de alta precisão
4. Cálculo de média por operação

---

## 🚀 Roadmap e Melhorias Futuras

### 🔄 Em Desenvolvimento

- [ ] **Redimensionamento Dinâmico**: Auto-resize quando α > 0.7
- [ ] **Rehashing**: Reorganização da tabela ao redimensionar
- [ ] **Persistência Completa**: Save/Load de dados em arquivo binário

### 💡 Planejado

- [ ] **Quadratic Probing**: Implementação alternativa de resolução
- [ ] **Double Hashing**: Segunda função hash para melhor distribuição
- [ ] **Chaining**: Comparação de performance com endereçamento aberto
- [ ] **Exportação CSV/JSON**: Múltiplos formatos de exportação
- [ ] **Interface Gráfica**: GUI com Qt ou wxWidgets
- [ ] **Testes Unitários**: Framework de testes automatizados (Google Test)
- [ ] **CI/CD**: Pipeline de integração contínua
- [ ] **Documentação Doxygen**: Geração automática de docs

### 🎨 Ideias Futuras

- [ ] Suporte a múltiplos índices (busca por nome)
- [ ] Sistema de cache LRU
- [ ] Compressão de dados
- [ ] Criptografia de dados sensíveis
- [ ] API REST para acesso remoto
- [ ] Suporte a transações (ACID)

---

## 📚 Referências e Recursos

### Livros

- **Introduction to Algorithms** (CLRS) - Capítulo 11: Hash Tables
- **Data Structures and Algorithm Analysis in C++** - Mark Allen Weiss
- **The Art of Computer Programming, Vol. 3** - Donald Knuth

### Papers Acadêmicos

- "Linear Probing and Graphs" - Donald Knuth (1963)
- "Analysis of Linear Probing Hashing" - Flajolet et al.

### Recursos Online

- [GeeksforGeeks - Hashing](https://www.geeksforgeeks.org/hashing-data-structure/)
- [VisuAlgo - Hash Table Visualization](https://visualgo.net/en/hashtable)
- [Big-O Cheat Sheet](https://www.bigocheatsheet.com/)

### Cursos

- MIT 6.006 - Introduction to Algorithms
- Stanford CS106B - Programming Abstractions
- Coursera - Data Structures and Algorithms Specialization

---

## 🤝 Como Contribuir

Este é um projeto educacional, mas contribuições são bem-vindas!

### Processo de Contribuição

1. **Fork** o projeto
2. Crie uma **branch** para sua feature (`git checkout -b feature/AmazingFeature`)
3. **Commit** suas mudanças (`git commit -m 'Add some AmazingFeature'`)
4. **Push** para a branch (`git push origin feature/AmazingFeature`)
5. Abra um **Pull Request**

### Diretrizes

- Mantenha o código limpo e bem documentado
- Siga os padrões de código existentes
- Adicione testes para novas funcionalidades
- Atualize a documentação conforme necessário

---

## 📄 Licença

Este projeto está sob a licença MIT. Veja o arquivo [LICENSE](LICENSE) para mais detalhes.

---

## 👨‍💻 Autor

**Desenvolvedor em Formação**

Projeto criado como parte de um estudo aprofundado em Estruturas de Dados e Algoritmos, com foco em:
- Implementação prática de conceitos teóricos
- Desenvolvimento de código limpo e manutenível
- Análise de complexidade algorítmica
- Boas práticas de engenharia de software

---

## 🙏 Agradecimentos

- Professores e mentores que inspiraram este projeto
- Comunidade open-source por recursos e ferramentas
- Autores dos livros e papers referenciados
- Todos que contribuíram com feedback e sugestões

---

<div align="center">

### ⭐ Se este projeto foi útil para seus estudos, considere dar uma estrela!

### 📖 Sinta-se livre para explorar, modificar e aprender com o código!

**Feito com ❤️ e muito ☕ para aprender Estruturas de Dados**

</div>
