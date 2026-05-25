# Projeto Tabela Hash

## Integrantes

- João Vitor
- João Gabriel
- Renato Hideki

## Descrição

Sistema de autenticação simples desenvolvido em C utilizando tabela hash.

O projeto realiza cadastro, login e remoção de usuários utilizando estruturas de dados como tabela hash e lista encadeada.

As senhas não são armazenadas diretamente. O sistema salva apenas o valor hash da senha para validação durante o login.

---

## Funcionalidades

- Cadastro de usuários
- Login de usuários
- Remoção de usuários
- Impressão da tabela hash
- Tratamento de colisões com lista encadeada
- Liberação de memória dinâmica

---

## Tecnologias Utilizadas

- Linguagem C
- Structs
- Ponteiros
- Alocação dinâmica (`malloc` e `free`)
- Tabela Hash
- Lista Encadeada

---

## Estrutura do Projeto

- `main.c` → menu principal e interação com o usuário
- `hash.c` → implementação das funções da tabela hash
- `hash.h` → structs e protótipos das funções

---

## Estratégia de Colisão

O projeto utiliza encadeamento separado com lista encadeada para tratar colisões na tabela hash.

---

## Funções Implementadas

- `criaHash()`
- `gerarHashSenha()`
- `funcaoHash()`
- `inserirHash()`
- `buscaHash()`
- `removerHash()`
- `imprimirHash()`
- `liberarHash()`

---

## Como Compilar

```bash
gcc main.c hash.c -o programa
