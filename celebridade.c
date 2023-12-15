#include <stdio.h>
#include <stdbool.h>

bool busca_linha(int array_size, int matriz[array_size][array_size], int linha)
{
    for (int i = 0; i < array_size; i++)
    {
        if (i != linha && matriz[linha][i] == 1)
        {
            return false;
        }
    }
    return true;
}
bool busca_coluna(int array_size, int matriz[array_size][array_size], int coluna)
{
    for (int i = 0; i < array_size; i++)
    {
        if (i != coluna && matriz[i][coluna] == 0)
        {
            return false;
        }
    }
    return true;
}
void busca_celebridade(int array_size, int matriz[array_size][array_size])
{
    for (int i = 0; i < array_size; i++)
    {
        if (busca_linha(array_size, matriz, i) && busca_coluna(array_size, matriz, i))
        {
            printf("%d", i);
            return;
        }
    }
    printf("NAO HA CELEBRIDADE");

    return false;
}

int main(int argc, char const *argv[])
{
    int tam;
    scanf("%d", &tam);
    int matriz[tam][tam];

    for (int i = 0; i < tam; i++)
    {
        for (int j = 0; j < tam; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }

    busca_celebridade(tam,matriz);

    return 0;
}
