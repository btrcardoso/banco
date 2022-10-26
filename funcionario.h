#include <stdlib.h>
#include <stdio.h>

typedef struct Funcionario {
    int cod;
    char nome[50];
    char cpf[15];
    char data_nascimento[11];
    double salario;
} Funcionario;

// Imprime funcionario
void imprime_funcionario(Funcionario *func);

// Cria funcionario. Lembrar de usar free_funcionario(funcionario)
Funcionario *funcionario(int cod, char *nome, char *cpf, char *data_nascimento, double salario);

// Salva funcionario no arquivo out, na posicao atual do cursor
void salva_funcionario(Funcionario *func, FILE *out);

// Le um funcionario do arquivo in na posicao atual do cursor
// Retorna um ponteiro para funcionario lido do arquivo
Funcionario *le_funcionario(FILE *in);

// Retorna tamanho do funcionario em bytes
int tamanho_funcionario();

// Lê todos os funcionários do arquivo in
void le_funcionarios(FILE *in);