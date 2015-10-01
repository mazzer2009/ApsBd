/* 
 * File:   main.c
 * Author: emanuel
 *
 * Created on 23 de Setembro de 2015, 18:47
 */

#include <stdio.h>
#include <stdlib.h>
#include "token.h"
#include <string.h>
typedef struct campo Campo;
typedef struct tabela Tabela;

struct campo{
    char*nome;
    int tipo;
};

struct tabela{
    char* nome;
    Campo** campo;
};


void inicializarArq(char* nome){
    FILE *fp=fopen(nome,"wr");
    char t=0;
    fwrite(&t,2000,1,fp); 
} 



int lerArquivo(char *arquivo) {
    FILE* p = fopen(arquivo, "rw");
    TokenReader *t;
    char *token;
    char *nome;
    char dado[100];
    while ((fgets(dado, sizeof (dado), p)) != NULL) {
        t = newTokenReader(dado);
        while (hasMoreTokens(t)) {
            token = nextToken(t);
            if (!(strcasecmp(token, "TABLE"))) {
                nome = nextToken(t);
                //fgets()
                

                printf("%s\n", nome);
            }

        }
    }
    //  printf("%s ", nome);


}



int main(int argc, char** argv) {
    int op = -1;
    //    TokenReader *teste;
    //
    //    teste = newTokenReader("teste testando testado");
    //
    //
    //    while (hasMoreTokens(teste)) {
    //        printf("%s ", nextToken(teste));
    //
    //    }

    //inicializarArq("teste.bin");
    do {
        printf("|---------------------|\n"
                "|1 - Criar Arquivo    |\n"
                "|2 - Inserir Registro |\n"
                "|3 - Listar Registros |\n"
                "|4 - Excluir Registros|\n"
                "|0 - Sair             |\n"
                "|---------------------|\n\n");

        printf("Digite uma opção:");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("Informe o nome do arquivo: ");
                char *nome;
                scanf("%s", nome);
                lerArquivo(nome);
                break;
            case 2:
                //inserirRegistros();
                break;
            case 3:
                //listarRegistros();
                break;
            case 4:
                //excluirRegistros();
                break;
            case 0:
                exit(1);
                break;
            default:
                printf("\nNumero Invalido. Digite novamente.\n");
        }
    } while (op);
}

