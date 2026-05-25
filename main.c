#include <stdio.h>
#include <string.h>
#include "hash.h"

int main() {

    Hash hash;

    criaHash(&hash);

    int opcao;

    char username[50];
    char senha[50];

    do {

        printf("\n===== MENU =====\n");
        printf("1 - Cadastrar usuario\n");
        printf("2 - Login\n");
        printf("3 - Remover usuario\n");
        printf("4 - Imprimir tabela\n");
        printf("0 - Sair\n");

        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:

                printf("Username: ");
                scanf("%s", username);

                printf("Senha: ");
                scanf("%s", senha);

                inserirHash(&hash, username, senha);

                break;

            case 2: {

                printf("Username: ");
                scanf("%s", username);

                printf("Senha: ");
                scanf("%s", senha);

                Usuario *user = buscaHash(&hash, username);

                if (user != NULL &&
                    user->hashSenha == gerarHashSenha(senha)) {

                    printf("Login realizado com sucesso!\n");

                } else {

                    printf("Username ou senha incorretos!\n");
                }

                break;
            }

            case 3:

                printf("Username para remover: ");
                scanf("%s", username);

                removerHash(&hash, username);

                break;

            case 4:

                imprimirHash(&hash);

                break;

            case 0:

                liberarHash(&hash);

                printf("Encerrando programa...\n");

                break;

            default:

                printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}