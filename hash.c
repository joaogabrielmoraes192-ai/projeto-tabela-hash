#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

void criaHash(Hash *hash) {

    for (int i = 0; i < TAMANHO; i++) {
        hash->tabela[i] = NULL;
    }
}

int gerarHashSenha(char senha[]) {

    int hash = 0;

    for (int i = 0; senha[i] != '\0'; i++) {
        hash = hash * 31 + senha[i];
    }

    return hash;
}

int funcaoHash(char username[]) {

    int soma = 0;

    for (int i = 0; username[i] != '\0'; i++) {
        soma += username[i];
    }

    return soma % TAMANHO;
}

void inserirHash(Hash *hash, char username[], char senha[]) {

    int indice = funcaoHash(username);

    Usuario *novo = (Usuario*) malloc(sizeof(Usuario));

    strcpy(novo->username, username);

    novo->hashSenha = gerarHashSenha(senha);

    novo->prox = hash->tabela[indice];

    hash->tabela[indice] = novo;

    printf("Usuario cadastrado com sucesso!\n");
}

Usuario* buscaHash(Hash *hash, char username[]) {

    int indice = funcaoHash(username);

    Usuario *atual = hash->tabela[indice];

    while (atual != NULL) {

        if (strcmp(atual->username, username) == 0) {
            return atual;
        }

        atual = atual->prox;
    }

    return NULL;
}

void removerHash(Hash *hash, char username[]) {

    int indice = funcaoHash(username);

    Usuario *atual = hash->tabela[indice];
    Usuario *anterior = NULL;

    while (atual != NULL) {

        if (strcmp(atual->username, username) == 0) {

            if (anterior == NULL) {
                hash->tabela[indice] = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }

            free(atual);

            printf("Usuario removido com sucesso!\n");

            return;
        }

        anterior = atual;
        atual = atual->prox;
    }

    printf("Usuario nao encontrado!\n");
}

void imprimirHash(Hash *hash) {

    for (int i = 0; i < TAMANHO; i++) {

        printf("[%d] -> ", i);

        Usuario *atual = hash->tabela[i];

        while (atual != NULL) {

            printf("(%s | %d) -> ",
                   atual->username,
                   atual->hashSenha);

            atual = atual->prox;
        }

        printf("NULL\n");
    }
}

void liberarHash(Hash *hash) {

    for (int i = 0; i < TAMANHO; i++) {

        Usuario *atual = hash->tabela[i];

        while (atual != NULL) {

            Usuario *temp = atual;

            atual = atual->prox;

            free(temp);
        }
    }
}