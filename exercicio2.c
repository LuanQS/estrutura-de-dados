#include <stdio.h>
#include <string.h>

struct Agenda {
    char nome[30];
    int idade;
    char telefone[10];
};

int main() {
    struct Agenda contatos[10];
    int i;

    // Leitura de 10 registros
    for (i = 0; i < 10; i++) {
        printf("\nDigite o nome da pessoa %d: ", i + 1);
        getchar();  // Limpar buffer
        fgets(contatos[i].nome, 30, stdin);
        contatos[i].nome[strcspn(contatos[i].nome, "\n")] = '\0';

        printf("Digite a idade: ");
        scanf("%d", &contatos[i].idade);

        printf("Digite o telefone: ");
        scanf("%s", contatos[i].telefone);
    }

    // Exibir os dados lidos
    printf("\nDados Lidos:\n");
    for (i = 0; i < 10; i++) {
        printf("\nPessoa %d\n", i + 1);
        printf("Nome: %s\n", contatos[i].nome);
        printf("Idade: %d\n", contatos[i].idade);
        printf("Telefone: %s\n", contatos[i].telefone);
    }

    return 0;
}
