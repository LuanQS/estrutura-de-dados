#include <stdio.h>
#include <string.h>

struct Agenda {
    char nome[30];
    int idade;
    char telefone[10];
};

// Função para ler um registro
void lerRegistro(struct Agenda *contato) {
    getchar(); // Limpar buffer
    printf("Digite o nome: ");
    fgets(contato->nome, 30, stdin);
    contato->nome[strcspn(contato->nome, "\n")] = '\0';

    printf("Digite a idade: ");
    scanf("%d", &contato->idade);

    printf("Digite o telefone: ");
    scanf("%s", contato->telefone);
}

// Função para imprimir um registro
void imprimirRegistro(struct Agenda contato) {
    printf("Nome: %s\n", contato.nome);
    printf("Idade: %d\n", contato.idade);
    printf("Telefone: %s\n", contato.telefone);
}

int main() {
    struct Agenda contatos[10];
    int i;

    // Leitura dos registros
    for (i = 0; i < 10; i++) {
        printf("\nPessoa %d\n", i + 1);
        lerRegistro(&contatos[i]);
    }

    // Impressão dos registros
    printf("\nDados Lidos:\n");
    for (i = 0; i < 10; i++) {
        printf("\nPessoa %d\n", i + 1);
        imprimirRegistro(contatos[i]);
    }

    return 0;
}
