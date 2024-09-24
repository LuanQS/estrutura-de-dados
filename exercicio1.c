#include <stdio.h>
#include <string.h>

// Definição da estrutura globalmente
struct Agenda {
    char nome[30];
    int idade;
    char telefone[10];
};

int main() {
    struct Agenda contato;

    // Leitura de um registro
    printf("Digite o nome: ");
    fgets(contato.nome, 30, stdin);
    contato.nome[strcspn(contato.nome, "\n")] = '\0'; // Remover o newline do fgets

    printf("Digite a idade: ");
    scanf("%d", &contato.idade);

    printf("Digite o telefone: ");
    scanf("%s", contato.telefone);

    // Exibir os dados lidos
    printf("\nDados Lidos:\n");
    printf("Nome: %s\n", contato.nome);
    printf("Idade: %d\n", contato.idade);
    printf("Telefone: %s\n", contato.telefone);

    return 0;
}
