#include "funcionario.c"
#include "agencia.c"
#include "conta_corrente.c"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void ler_comando(FILE *in);

void cadastrar_funcionario(FILE *f);
void cadastrar_agencia(FILE *f);
void cadastrar_conta_corrente(FILE *f);


void ler_comando(FILE *in){

    int comando = -1;
    
    do{
        printf("---- Escolha o comando que você deseja realizar: ----\n");
        printf("1- ler funcionario\n2- ler agencia\n3- ler conta_corrente\n4- cadastrar funcionario\n5- cadastrar agencia\n6- cadastrar conta_corrente\n7- sair\n> ");
        scanf("%d", &comando);

        switch(comando){
            case 1:
                le_funcionarios(in);
            break;
            case 2:
                le_agencias(in);
            break;
            case 3:
                le_contas_correntes(in);
            break;
            case 4:
                cadastrar_funcionario(in);
            break;
            case 5:
                cadastrar_agencia(in);
            break;
            case 6:
                cadastrar_conta_corrente(in);
            break;
            case 7:
                printf("\nEncerrando...\n");
                exit(1);
            break;
            default:
                printf("Digite um valor válido.\n");
        }

        comando = -1;

    } while(1);

}

int procurar(char *item, char *lista[], int tam_lista){

    for(int i=0; i<tam_lista; i++){

        if(strcmp(item, lista[i]) == 0){

            return i;

        }
         
    }

    return -1;

}

// criação de novo Funcionário a partir de dados do teclado
void cadastrar_funcionario(FILE *f){
    printf("--- Cadastro de funcionário ---\n");
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
    salva_funcionario(func, f);
    printf("Funcionário cadastrado com sucesso!\n");
    free(func);
}

void cadastrar_agencia(FILE *f){
    
}

void cadastrar_conta_corrente(FILE *f){
    
}


int main (void){

    // ponteiro para arquivo
    FILE *out;

    // cria ou abre o arquivo funcionarios.dat, sem apagar seu conteúdo, apontando para o fim do arquivo
    if((out = fopen("funcionarios.dat", "a+b")) == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
    }

    ler_comando(out);

    /*

    cadastrar_funcionario(out);
    
    le_funcionarios(out);
    
    // fecha o arquivo
    fclose(out);
    
    */

    return 0;
}