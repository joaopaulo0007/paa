#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int nroTimes = 1000;

int venceu();
void swap(int *lista, int pos1, int pos2)
{
    int temp = lista[pos1];
    lista[pos1] = lista[pos2];
    lista[pos2] = temp;
}

void geraLista(int *lista)
{
    for (int i = 1; i < nroTimes; i++)
    {
        int j = i;
        while (j > 0 && venceu(lista[j], lista[j - 1]) == 1)
        {
            swap(lista, j, j - 1);
            j--;
        }
    }
}

int **resultados;
// retorna: 1 se i venceu j
//          0 se empate
//         -1 se i perdeu de j
int venceu(int i, int j)
{
    if (i > j)
        return resultados[i - 1][j];
    else
        return -resultados[j - 1][i];
}

// retorna true sse lista satisfaz o problema
int verificaLista(int *lista)
{
    for (int i = 0; i < nroTimes - 1; i++)
        if (venceu(lista[i], lista[i + 1]) == -1) // lista[i] perdeu de lista[i+1]
            return 0;
    return 1;
}

// Cria matriz triangular que conterá os resultados
//      resultados[i][j] == 0 <=> i+1 empatou com j
//      resultados[i][j] == 1 <=> i+1 venceu j
//      resultados[i][j] == -1 <=> i+1 perdeu de j
void criaMatrizResultados()
{
    resultados = (int **)malloc((nroTimes - 1) * sizeof(int *));
    for (int i = 0; i < nroTimes - 1; i++)
    {
        resultados[i] = (int *)malloc((i + 1) * sizeof(int));
    }
}

void geraResultadosRandomicos()
{
    for (int i = 0; i < nroTimes - 1; i++)
        for (int j = 0; j <= i; j++)
        {
            resultados[i][j] = rand() % 3 - 1;
        }
}

// inicializa a lista com todos os times ordenados pelo seu número
void inicializaLista(int *lista)
{
    for (int i = 0; i < nroTimes; i++)
    {
        lista[i] = i;
    }
}

void main()
{
    criaMatrizResultados();
    int *lista = (int *)malloc(nroTimes * sizeof(int));
    inicializaLista(lista);
    // 10 casos de teste aleatórios
    for (int i = 0; i < 10; i++)
    {
        geraResultadosRandomicos();
        geraLista(lista);
        if (!verificaLista(lista))
        {
            printf("NAO");
            exit(0);
        }
    }
    printf("SIM");
}