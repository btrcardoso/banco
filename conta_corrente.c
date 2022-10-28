#include "conta_corrente.h"
#include <stdio.h>
#include <stdlib.h>

// Imprime o conteúdo de conta corrente
void imprime_conta_corrente(ContaCorrente *cc){
    printf("Código: %d\n", cc->cod);
    printf("Código Agência: %d\n", cc->cod_agencia);
    printf("Saldo: %.2lf\n\n", cc->saldo);
}

// Cria a conta_corrente
ContaCorrente * conta_corrente(int cod, int cod_agencia, double saldo){

    // alocar memória para conta corrente
    ContaCorrente *cc = (ContaCorrente *) malloc(sizeof(ContaCorrente));

    // inicializa o espaço de memória com zeros
    if(cc) memset(cc, 0, sizeof(cc));

    // copia os valores para os campos de cc
    cc->cod = cod;
    cc->cod_agencia = cod_agencia;
    cc->saldo = saldo;

    return cc;
    
}

// salva dados da conta corrente no arquivo out
void salva_conta_corrente(ContaCorrente *cc, FILE *out){

    /*
        fwrite(const void *_Buffer, size_t _ElementSize, size_t _ElementCount, FILE *_Stream)
        fwrite(
            ponteiro para dados a serem gravados, 
            tamanho do item em bytes,
            máximo de itens a serem gravados,
            ponteiro para a estrutura file
        );
    */

    fwrite(&cc->cod, sizeof(int), 1, out);
    fwrite(&cc->cod_agencia, sizeof(int), 1, out);
    fwrite(&cc->saldo, sizeof(double), 1, out);

}

// Le uma ContaCorrente do arquivo in na posicao atual do cursor
// Retorna um ponteiro para ContaCorrente lido do arquivo
ContaCorrente * le_conta_corrente(FILE *in){

    // alocar memória para conta corrente
    ContaCorrente *cc = (ContaCorrente*) malloc(sizeof(ContaCorrente));

    /*
    fread(void *_Buffer, size_t _ElementSize, size_t _ElementCount, FILE *_Stream)
    fread(
        local de armazenamento, 
        tamanho do item em bytes,
        numero maximo de itens a serem lidos, 
        ponteiro para estrutura file
    );
    */

    if (fread(&cc->cod, sizeof(int), 1, in) <= 0){
        free(cc);
        return NULL;
    }

    fread(&cc->cod_agencia, sizeof(int), 1, in);
    fread(&cc->saldo, sizeof(double), 1, in);

    return cc;

}

// Retorna tamanho do funcionario em bytes
int tamanho_conta_corrente(){
    return sizeof(int)    // cod
        + sizeof(int)     // cod_agencia
        + sizeof(double); // saldo
}

// Lê todos as contas correntes do arquivo in
void le_contas_correntes(FILE *in){

    printf("------- Contas correntes: -------\n");
    
    // coloca o ponteiro no inicio do arquivo
    rewind(in);

    ContaCorrente *cc;

    while( (cc = le_conta_corrente(in)) != NULL ){
        imprime_conta_corrente(cc);
        free(cc);
    }


}