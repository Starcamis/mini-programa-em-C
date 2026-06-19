#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIVROS 100

// Estrutura do livro
struct Livro {
    int id;
    char titulo[100];
    char autor[100];
};

// Vetor de livros
struct Livro livros[MAX_LIVROS];

// Controle de quantidade
int totalLivros = 0;

// Função para cadastrar livro
void cadastrarLivro() {

    if(totalLivros >= MAX_LIVROS) {
        printf("\nLimite de livros atingido.\n");
        return;
    }

    printf("\n=== CADASTRAR LIVRO ===\n");

    livros[totalLivros].id = totalLivros + 1;

    printf("Digite o titulo do livro: ");
    fgets(livros[totalLivros].titulo, sizeof(livros[totalLivros].titulo), stdin);

    printf("Digite o autor do livro: ");
    fgets(livros[totalLivros].autor, sizeof(livros[totalLivros].autor), stdin);

    // Remove quebra de linha
    livros[totalLivros].titulo[strcspn(livros[totalLivros].titulo, "\n")] = '\0';
    livros[totalLivros].autor[strcspn(livros[totalLivros].autor, "\n")] = '\0';

    totalLivros++;

    printf("\nLivro cadastrado com sucesso!\n");
}

// Função para listar livros
void listarLivros() {

    int i;

    printf("\n=== LISTA DE LIVROS ===\n");

    if(totalLivros == 0) {
        printf("Nenhum livro cadastrado.\n");
        return;
    }

    for(i = 0; i < totalLivros; i++) {

        printf("\n------------------------\n");
        printf("ID: %d\n", livros[i].id);
        printf("Titulo: %s\n", livros[i].titulo);
        printf("Autor: %s\n", livros[i].autor);
    }
}

// Função para buscar livro pelo título
void buscarLivro() {

    char tituloBusca[100];
    int i;
    int encontrado = 0;

    printf("\n=== BUSCAR LIVRO ===\n");

    printf("Digite o titulo do livro: ");
    fgets(tituloBusca, sizeof(tituloBusca), stdin);

    // Remove quebra de linha
    tituloBusca[strcspn(tituloBusca, "\n")] = '\0';

    for(i = 0; i < totalLivros; i++) {

        if(strcmp(livros[i].titulo, tituloBusca) == 0) {

            printf("\nLivro encontrado!\n");
            printf("ID: %d\n", livros[i].id);
            printf("Titulo: %s\n", livros[i].titulo);
            printf("Autor: %s\n", livros[i].autor);

            encontrado = 1;
            break;
        }
    }

    if(encontrado == 0) {
        printf("Livro nao encontrado.\n");
    }
}
// Função para remover livro pelo título
void removerLivro() {

    char tituloBusca[100];
    int i;
    int encontrado = 0;

    printf("\n=== REMOVER LIVRO ===\n");

    printf("Digite o titulo do livro: ");
    fgets(tituloBusca, sizeof(tituloBusca), stdin);
    // Remove quebra de linha
    tituloBusca[strcspn(tituloBusca, "\n")] = '\0';
    for(i = 0; i < totalLivros; i++) {

        if(strcmp(livros[i].titulo, tituloBusca) == 0) {
             int j;
            for(j = i; j < totalLivros - 1; j++) {
                livros[j] = livros[j + 1];
            }

            totalLivros--;

            printf("\nLivro removido com sucesso!\n");

            encontrado = 1;
            break;
        }
    }

    if(encontrado == 0) {
        printf("\nLivro nao encontrado.\n");
    }
}

// Função principal
int main() {

    char entrada[20];
    int opcao;

    do {

        printf("\n========== SISTEMA DE BIBLIOTECA ==========\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Listar livros\n");
        printf("3 - Buscar livro\n");
        printf("4 - Remover livro\n");
        printf("0 - Sair\n");

        printf("Escolha uma opcao: ");

        fgets(entrada, sizeof(entrada), stdin);

        opcao = atoi(entrada);

        switch(opcao) {

            case 1:
                cadastrarLivro();
                break;

            case 2:
                listarLivros();
                break;

            case 3:
                buscarLivro();
                break;

            case 4:
                removerLivro();
                break;

            case 0:
                printf("\nEncerrando sistema...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}