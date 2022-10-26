#include "funcionario.c"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// criação de novo Funcionário a partir de dados do teclado
void cadastrar_funcionario(FILE *f){
    int cod = 0;
    char nome[50], cpf[15], data_nascimento[11];
    double salario;

    printf("Nome: ");
    scanf("%s", nome);

    printf("CPF: ");
    scanf("%s", cpf);

    printf("Data de nascimento: ");
    scanf("%s", data_nascimento);

    printf("Salário: ");
    scanf("%lf", &salario);

    Funcionario *func = funcionario(cod, nome, cpf, data_nascimento, salario);
    imprime_funcionario(func);
    salva_funcionario(func, f);
    free(func);
}

int main (void){

    // ponteiro para arquivo
    FILE *out;

    // cria ou abre o arquivo funcionarios.dat, sem apagar seu conteúdo, apontando para o fim do arquivo
    if((out = fopen("funcionarios.dat", "a+b")) == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    cadastrar_funcionario(out);
    
    le_funcionarios(out);
    
    // fecha o arquivo
    fclose(out);
    
    return 0;
}