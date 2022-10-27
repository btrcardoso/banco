#include <stdio.h>
#include <stdlib.h>

typedef struct ContaCorrente{
    int cod;
    int cod_agencia;
    double saldo;
} ContaCorrente;

// Imprime o conteúdo de conta corrente
void imprime_conta_corrente(ContaCorrente *cc);

// Cria a conta_corrente
ContaCorrente * conta_corrente(int cod, int cod_agencia, double saldo);

// salva dados da conta corrente no arquivo out
void salva_conta_corrente(ContaCorrente *cc, FILE *out);

// Le uma ContaCorrente do arquivo in na posicao atual do cursor
// Retorna um ponteiro para ContaCorrente lido do arquivo
ContaCorrente * le_conta_corrente(FILE *in);

// Retorna tamanho do funcionario em bytes
int tamanho_conta_corrente();

// Lê todos as contas correntes do arquivo in
void le_contas_correntes(FILE *in);