#include "funcionario.h"
#include <string.h>
#include <stdlib.h>

void imprime_funcionario(Funcionario *func){
    // printf("------- Dados do funcionário -------\n");
    printf("Código: %d\n", func->cod);
    printf("Nome: %s\n", func->nome);
    printf("CPF: %s\n", func->cpf);
    printf("Data de nascimento: %s\n", func->data_nascimento);
    printf("Salário: %4.2f\n\n", func->salario);
}

//Cria funcionario. Lembrar de usar free(func)
Funcionario *funcionario(int cod, char *nome, char *cpf, char *data_nascimento, double salario){
    // aloca espaço para um bloco que caiba o Funcionario
    Funcionario *func = (Funcionario *) malloc(sizeof(Funcionario));
    
    // inicializa o espaço de memória com zeros
    if(func) memset(func, 0, sizeof(Funcionario));

    // copia os valores para os campos de func
    func->cod = cod;
    strcpy(func->nome, nome);
    strcpy(func->cpf, cpf);
    strcpy(func->data_nascimento, data_nascimento);
    func->salario = salario;

    return func;
}

// Salva funcionario no arquivo out, na posicao atual do cursor
void salva_funcionario(Funcionario *func, FILE *out){

    /*
    fwrite(const void *_Buffer, size_t _ElementSize, size_t _ElementCount, FILE *_Stream)
    fwrite(
        ponteiro para dados a serem gravados, 
        tamanho do item em bytes,
        máximo de itens a serem gravados,
        ponteiro para a estrutura file
    );
    */

    fwrite(&func->cod, sizeof(int), 1, out);
    fwrite(func->nome, sizeof(char), sizeof(func->nome), out);
    fwrite(func->cpf, sizeof(char), sizeof(func->cpf), out);
    fwrite(func->data_nascimento, sizeof(char), sizeof(func->data_nascimento), out);
    fwrite(&func->salario, sizeof(double), 1, out);

}

// Le um funcionario do arquivo in na posicao atual do cursor
// Retorna um ponteiro para funcionario lido do arquivo
Funcionario *le_funcionario(FILE *in) {

    // aloca espaço para um bloco que caiba o Funcionario
    Funcionario *func = (Funcionario*) malloc(sizeof(Funcionario));

    /*
    fread(void *_Buffer, size_t _ElementSize, size_t _ElementCount, FILE *_Stream)
    fread(
        local de armazenamento, 
        tamanho do item em bytes,
        numero maximo de itens a serem lidos, 
        ponteiro para estrutura file
    );
    */
    
    if(0 >= fread(&func->cod, sizeof(int), 1, in)){
        free(func);
        return NULL;
    }

    fread(func->nome, sizeof(char), sizeof(func->nome), in);
    fread(func->cpf, sizeof(char), sizeof(func->cpf), in);
    fread(func->data_nascimento, sizeof(char), sizeof(func->data_nascimento), in);
    fread(&func->salario, sizeof(double), 1, in);

    return func;
}

// retorna o tamanho da struct Funcionario em bytes
int tamanho_funcionario(){
    return sizeof(int)  //cod
        + sizeof(char) * 50 //nome
        + sizeof(char) * 15 //cpf
        + sizeof(char) * 11 //data_nascimento
        + sizeof(double); //salario
}

void le_funcionarios(FILE *in){

    printf("------- Funcionários: -------\n\n");

    // Traz o ponteiro para o início do arquivo 
    rewind(in);

    Funcionario *f;

    while( (f = le_funcionario(in)) != NULL  ){
        imprime_funcionario(f);
        free(f);
    }

    printf("-------------- \n");

}