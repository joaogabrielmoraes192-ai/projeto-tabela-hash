#ifndef HASH_H
#define HASH_H

#define TAMANHO 10

typedef struct Usuario {
    char username[50];
    int hashSenha;
    struct Usuario *prox;
} Usuario;

typedef struct {
    Usuario *tabela[TAMANHO];
} Hash;

void criaHash(Hash *hash);

int gerarHashSenha(char senha[]);

int funcaoHash(char username[]);

void inserirHash(Hash *hash, char username[], char senha[]);

Usuario* buscaHash(Hash *hash, char username[]);

void removerHash(Hash *hash, char username[]);

void imprimirHash(Hash *hash);

void liberarHash(Hash *hash);

#endif