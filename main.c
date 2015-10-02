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

struct campo {
    char*nome;
    int tipo;
};

struct tabela {
    char* nome;
    Campo** campo;
};

void inicializarArq(char* nome) {
    FILE *fp = fopen(nome, "wr");
    int t = 0; 
    int i = 0;
    
     if (!fp) {// Se não conseguiu criar
        printf("Problemas na CRIACAO do arquivo\n");
   	return;
    }
    
    while (i < 500) {
    printf("aqui %d", i);
        fwrite(&t, sizeof(int), 1, fp);
        i++;
    }
    fclose(fp);
    
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

int inserirRegistros(char *arquivo) {
    FILE* p = fopen(arquivo, "rw");
    TokenReader *t;
    char *token;
    char *nome;
    char values[1000];
    
   

    fgets(values, sizeof (values), p);
    t = newTokenReader(values);
    while (!(strcasecmp(token, "INTO"))) {
        token = nextToken(t);

    }
    nome = nextToken(t);

    //    getTable(nome);


    while ((fgets(values, sizeof (values), p)) != NULL) {
        t = newTokenReader(values);
        while (hasMoreTokens(t)) {


            if (!(strcasecmp(token, "values"))) {

            }

        }
    }
}

struct Tabela* getTabela(char *arquivo) {
    char *arq = arquivo;
    strcat(arq, ".dat");
    printf("Nome arquivo: %s", arq);
    FILE* p = fopen(arq, "rb");

    if (!p) {
        printf("Erro na abertura do arquivo");
        return -1;
    }
    Tabela *t = (Tabela*) malloc(sizeof (Tabela));
    t->nome = arq;
    Campo *c = (Campo*) malloc(sizeof (Campo));
    //criar laço para ler ate o fim do cabeçalho
}

int gravaArquivoCreate(Tabela *t) {
    char *arq = t->nome;
    strcat(arq, ".dat");
    FILE *f = fopen(arq, "wb"); // Cria um arquivo binário para gravação 

    if (!f) // Se não conseguiu criar
    {
        printf("Problemas na CRIACAO do arquivo\n");
        return -1;
    }

    fwrite(0, sizeof (int), 0, f);
    fwrite(0, sizeof (int), 4, f);
    fwrite(0, sizeof (int), 2000, f);
    fwrite(0, sizeof (int), 2000, f);

    fclose(f);

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
                printf("Informe o nome do arquivo: ");
                char *nomea;
                scanf("%s", nomea);
                inserirRegistros(nomea);
                break;
            case 3:
                //listarRegistros();
                inicializarArq("teste.dat");
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

