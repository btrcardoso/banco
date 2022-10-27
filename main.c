#include "funcionario.c"
#include "agencia.c"
#include "conta_corrente.c"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void ler_comando(void);

void cadastrar_funcionario(FILE *f);
void cadastrar_agencia(FILE *f);
void cadastrar_conta_corrente(FILE *f);

FILE * abrirArquivo(char * nome, FILE *f){

    if((f = fopen(nome, "a+b")) == NULL){
        printf("Erro ao abrir o arquivo");
        exit(1);
    } else {
        return f;
    }

}

void ler_comando(void){

    int comando = -1;

    // ponteiro para arquivo
    FILE *f;
    
    do{
        printf("---- Escolha o comando que você deseja realizar: ----\n");
        printf("1- ler funcionarios\n2- ler agencias\n3- ler conta_correntes\n4- cadastrar funcionario\n5- cadastrar agencia\n6- cadastrar conta_corrente\n7- sair\n> ");
        scanf("%d", &comando);

        switch(comando){
            case 1:
                f = abrirArquivo("funcionarios.dat", f);
                le_funcionarios(f);
            break;
            case 2:
                f = abrirArquivo("agencias.dat", f);
                le_agencias(f);
            break;
            case 3:
                f = abrirArquivo("contas_correntes.dat", f);
                le_contas_correntes(f);
            break;
            case 4:
                f = abrirArquivo("funcionarios.dat", f);
                cadastrar_funcionario(f);
            break;
            case 5:
                f = abrirArquivo("agencias.dat", f);
                cadastrar_agencia(f);
            break;
            case 6:
                f = abrirArquivo("contas_correntes.dat", f);
                cadastrar_conta_corrente(f);
            break;
            case 7:
                printf("\nEncerrando...\n");
                exit(1);
            break;
            default:
                printf("Digite um valor válido.\n");
        }

        fclose(f);

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

    int cod = 0;
    char nome[50];
    char gerente[50];

    printf("--- Cadastro de Agência ---\n");

    printf("Nome: ");
    scanf("%s", nome);

    printf("Gerente: ");
    scanf("%s", gerente);

    Agencia *ag = agencia(cod, nome, gerente);

    imprime_agencia(ag);

    salva_agencia(ag, f);
    printf("Agência cadastrada com sucesso!\n");
    free(ag);
    
}

void cadastrar_conta_corrente(FILE *f){
    
}


int main (void){

    ler_comando();

    /*

    cadastrar_funcionario(out);
    
    le_funcionarios(out);
    
    // fecha o arquivo
    fclose(out);
    
    */

    return 0;
}