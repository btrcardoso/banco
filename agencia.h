#include<stdio.h>
#include<stdlib.h>

typedef struct Agencia{
    int cod;
    char nome[50];
    char gerente[50];
} Agencia;

// Imprime o conteúdo de agência
void imprime_agencia(Agencia *ag);

// Cria a agencia
Agencia * agencia(int cod, char *nome, char *gerente);

// salva dados da agência no arquivo out
void salva_agencia(Agencia *ag, FILE *out);

// Le uma agencia do arquivo in na posicao atual do cursor
// Retorna um ponteiro para agencia lido do arquivo
Agencia * le_agencia(FILE *in);

// Retorna tamanho do funcionario em bytes
int tamanho_agencia();

// Lê todas as agencias do arquivo in
void le_agencias(FILE *in);
