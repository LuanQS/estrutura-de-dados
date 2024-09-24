#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Agenda {
    char nome[30];
    int idade;
    char telefone[10];
};

// Função para ler dados
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

// Função para imprimir dados
void imprimirRegistro(struct Agenda *contato) {
    printf("Nome: %s\n", contato->nome);
    printf("Idade: %d\n", contato->idade);
    printf("Telefone: %s\n", contato->telefone);
}

// Função para calcular a média de idade
float calcularMedia(struct Agenda *contatos[], int n) {
    int soma = 0;
    for (int i = 0; i < n; i++) {
        soma += contatos[i]->idade;
    }
    return (float)soma / n;
}

int main() {
    struct Agenda *contatos[5];
    int i;

    // Alocação e leitura dos dados
    for (i = 0; i < 5; i++) {
        contatos[i] = (struct Agenda *)malloc(sizeof(struct Agenda));
        if (contatos[i] == NULL) {
            printf("Erro de alocação de memória!\n");
            return 1;
        }
        printf("\nPessoa %d\n", i + 1);
        lerRegistro(contatos[i]);
    }

    // Cálculo da média de idade
    float media = calcularMedia(contatos, 5);
    printf("\nMédia de idade: %.2f\n", media);

    // Impressão dos dados
    printf("\nDados Lidos:\n");
    for (i = 0; i < 5; i++) {
        printf("\nPessoa %d\n", i + 1);
        imprimirRegistro(contatos[i]);
    }

    // Liberação da memória
    for (i = 0; i < 5; i++) {
        free(contatos[i]);
    }

    return 0;
}
