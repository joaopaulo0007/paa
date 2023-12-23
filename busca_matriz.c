#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))

// int busca(int k, int n, int** matriz) {...} -- Complete o código
// k é o valor a ser buscado na matriz
// matriz tem dimensão n x n
// Insira o código aqui

int busca(int k, int n, int **matriz)
{
    int linha = 0, coluna = n - 1;

    while (linha < n && coluna >= 0)
    {
        if (matriz[linha][coluna] == k)
        {
            return 1;  
        }
        else if (matriz[linha][coluna] > k)
        {
            coluna--;  
        }
        else
        {
            linha++;   
        }
    }

    return 0;  
}

int **criaMatriz(int n)
{
    int **mat = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        mat[i] = (int *)malloc(n * sizeof(int));
    return mat;
}

void preencheTrivial(int n, int **matriz)
{
    for (int i = 0; i < n; i++)
    {
        int b = n * i;
        for (int j = 0; j < n; j++)
            matriz[i][j] = b + j;
    }
}

void preencheRandomico(int n, int **matriz)
{
    matriz[0][0] = rand() % 4;
    for (int i = 1; i < n; i++)
        matriz[0][i] = matriz[0][i - 1] + rand() % 4;
    for (int i = 1; i < n; i++)
        matriz[i][0] = matriz[0][i - 1] + rand() % 4;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
            matriz[i][j] = MAX(matriz[i - 1][j], matriz[i][j - 1]) + rand() % 4;
    }
}

int main(char *argv)
{
    srand(time(NULL));
    int n = 5000;
    int **matriz = criaMatriz(n);

    preencheTrivial(n, matriz);
    if (!busca(n * n / 2, n, matriz))
    {
        printf("NAO");
        exit(0);
    }
    if (busca(n * n, n, matriz))
    {
        printf("NAO");
        exit(0);
    }

    preencheRandomico(n, matriz);
    for (int k = 0; k < 50; k++)
    {
        if (busca(25000000, n, matriz))
        {
            printf("NAO");
            exit(0);
        }
    }
    for (int k = 0; k < 10; k++)
    {
        int i = rand() % n;
        int j = rand() % n;
        if (!busca(matriz[i][j], n, matriz))
        {
            printf("NAO");
            exit(0);
        }
    }

    printf("SIM");
}