#include <stdio.h>
#include <locale.h>

#define NUM_CLIENTES 5

// Definição da struct dados
struct dados {
    int codigo;
    char nome[50];
    int idade;
    char sexo;
    float salario;
};

// Declaração da variável global do tipo struct
struct dados cliente[NUM_CLIENTES];

// Função para imprimir os dados dos clientes
void imprimir_dados(struct dados cliente[], int num_clientes) {
    printf("\nDados dos clientes:\n");
    for (int i = 0; i < num_clientes; i++) {
        printf("Cliente %d:\n", i + 1);
        printf("Código: %d\n", cliente[i].codigo);
        printf("Nome: %s\n", cliente[i].nome);
        printf("Idade: %d\n", cliente[i].idade);
        printf("Sexo: %c\n", cliente[i].sexo);
        printf("Salário: %.2f\n\n", cliente[i].salario);
    }
}

// Função para calcular a somatória das idades dos clientes
int somar_idades(struct dados cliente[], int num_clientes) {
    int soma_idades = 0;
    for (int i = 0; i < num_clientes; i++) {
        soma_idades += cliente[i].idade;
    }
    return soma_idades;
}

int main() {
    // Define a localidade para UTF-8
    setlocale(LC_ALL, "");

    // Entrada de dados para os 5 clientes
    for (int i = 0; i < NUM_CLIENTES; i++) {
        printf("Insira os dados do cliente %d:\n", i + 1);
        printf("Código: ");
        scanf("%d", &cliente[i].codigo);
        printf("Nome: ");
        scanf(" %[^\n]", cliente[i].nome); // Lê até encontrar uma nova linha
        printf("Idade: ");
        scanf("%d", &cliente[i].idade);
        printf("Sexo (M/F): ");
        scanf(" %c", &cliente[i].sexo);
        printf("Salário: ");
        scanf("%f", &cliente[i].salario);
        printf("\n");
    }

    // Chamada para a função de impressão dos dados
    imprimir_dados(cliente, NUM_CLIENTES);

    // Chamada para a função de somar as idades e cálculo da média de idade
    int soma_idades = somar_idades(cliente, NUM_CLIENTES);
    float media_idade = (float)soma_idades / NUM_CLIENTES;
    printf("Média de idade dos clientes: %.2f\n", media_idade);

    return 0;
}

