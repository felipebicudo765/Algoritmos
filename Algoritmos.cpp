#include <stdio.h>
#include <locale.h>

#define NUM_CLIENTES 5

// Defini��o da struct dados
struct dados {
    int codigo;
    char nome[50];
    int idade;
    char sexo;
    float salario;
};

// Declara��o da vari�vel global do tipo struct
struct dados cliente[NUM_CLIENTES];

// Fun��o para imprimir os dados dos clientes
void imprimir_dados(struct dados cliente[], int num_clientes) {
    printf("\nDados dos clientes:\n");
    for (int i = 0; i < num_clientes; i++) {
        printf("Cliente %d:\n", i + 1);
        printf("C�digo: %d\n", cliente[i].codigo);
        printf("Nome: %s\n", cliente[i].nome);
        printf("Idade: %d\n", cliente[i].idade);
        printf("Sexo: %c\n", cliente[i].sexo);
        printf("Sal�rio: %.2f\n\n", cliente[i].salario);
    }
}

// Fun��o para calcular a somat�ria das idades dos clientes
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
        printf("C�digo: ");
        scanf("%d", &cliente[i].codigo);
        printf("Nome: ");
        scanf(" %[^\n]", cliente[i].nome); // L� at� encontrar uma nova linha
        printf("Idade: ");
        scanf("%d", &cliente[i].idade);
        printf("Sexo (M/F): ");
        scanf(" %c", &cliente[i].sexo);
        printf("Sal�rio: ");
        scanf("%f", &cliente[i].salario);
        printf("\n");
    }

    // Chamada para a fun��o de impress�o dos dados
    imprimir_dados(cliente, NUM_CLIENTES);

    // Chamada para a fun��o de somar as idades e c�lculo da m�dia de idade
    int soma_idades = somar_idades(cliente, NUM_CLIENTES);
    float media_idade = (float)soma_idades / NUM_CLIENTES;
    printf("M�dia de idade dos clientes: %.2f\n", media_idade);

    return 0;
}

