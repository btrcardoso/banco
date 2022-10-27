#include "agencia.h"
#include <stdio.h>
#include <stdlib.h>

// Imprime o conteúdo de agência
void imprime_agencia(Agencia *ag){
    printf("Código: %d\n", ag->cod);
    printf("Nome: %s\n", ag->nome);
    printf("Gerente: %s\n", ag->gerente);
}

// Cria a agencia
Agencia * agencia(int cod, char *nome, char *gerente){
    // alocar memória para agência
    Agencia *ag = (Agencia *) malloc(sizeof(Agencia));
    
    // inicializa o espaço de memória com zeros
    if(ag) memset(ag, 0, sizeof(Agencia));

    // copia os valores para os campos de ag
    ag->cod = cod;
    strcpy(ag->nome, nome);
    strcpy(ag->gerente, gerente);

    return ag;
}

// salva dados da agência no arquivo out
void salva_agencia(Agencia *ag, FILE *out){

    /*
    fwrite(const void *_Buffer, size_t _ElementSize, size_t _ElementCount, FILE *_Stream)
    fwrite(
        ponteiro para dados a serem gravados, 
        tamanho do item em bytes,
        máximo de itens a serem gravados,
        ponteiro para a estrutura file
    );
    */

    fwrite(&ag->cod, sizeof(int), 1, out);
    fwrite(ag->nome, sizeof(char), sizeof(ag->nome), out);
    fwrite(ag->gerente, sizeof(char), sizeof(ag->gerente), out);
}

// Le uma agencia do arquivo in na posicao atual do cursor
// Retorna um ponteiro para agencia lido do arquivo
Agencia * le_agencia(FILE *in){

    // aloca espaço para um bloco que caiba a Agencia
    Agencia *ag = (Agencia *) malloc(sizeof(Agencia));

    /*
    fread(void *_Buffer, size_t _ElementSize, size_t _ElementCount, FILE *_Stream)
    fread(
        local de armazenamento, 
        tamanho do item em bytes,
        numero maximo de itens a serem lidos, 
        ponteiro para estrutura file
    );
    */

    if(0 >= fread(&ag->cod, sizeof(int), 1, in)){
        free(ag);
        return NULL;
    }

    fread(ag->nome, sizeof(char), sizeof(ag->nome), in);
    fread(ag->gerente, sizeof(char), sizeof(ag->gerente), in);
    
    return ag;
}

// Retorna tamanho do funcionario em bytes
int tamanho_agencia(){
    return sizeof(int)       //cod
        + sizeof(char) * 50  //nome
        + sizeof(char) * 50; //gerente
}

// Lê todas as agencias do arquivo in
void le_agencias(FILE *in){

    printf("------- Agências: -------\n\n");

    // Traz o ponteiro para o inicio do arquivo
    rewind(in);

    Agencia *ag;

    while((ag = le_agencia(in)) != NULL){
        imprime_agencia(ag);
        free(ag);
    }

}