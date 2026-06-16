#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

struct Venda {
    char produto[50];
    int quantidade;
    float precoUnitario;
};

void exibirCabecalho() {
	SetConsoleOutputCP(CP_UTF8);
    printf("Relatório de Vendas\n");
    printf("%-15s %-10s %-15s %-15s\n",
           "Produto", "Quantidade", "Preco Unid.", "Total");
}

void processarArquivo(char nomeArquivo[]) {
    FILE *arquivo;
    struct Venda venda;
    float totalVenda;

    arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    char linha[100];
    fgets(linha, sizeof(linha), arquivo);

    exibirCabecalho();

    while (fscanf(arquivo, "%49[^,],%d,%f\n",
                  venda.produto,
                  &venda.quantidade,
                  &venda.precoUnitario) == 3) {

        totalVenda = venda.quantidade * venda.precoUnitario;

        printf("%-15s %-10d R$ %-11.2f R$ %-10.2f\n",
               venda.produto,
               venda.quantidade,
               venda.precoUnitario,
               totalVenda);
    }

    fclose(arquivo);
}

int main() {
    processarArquivo("vendas.csv");
    return 0;
}