#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    double x;
    double y;
    bool adicionado ;
} Ponto;
void swap(Ponto lista[], int pos1, int pos2)
{
    Ponto temp = lista[pos1];
    lista[pos1] = lista[pos2];
    lista[pos2] = temp;
}
void ordena(Ponto lista[], int arraysize)
{
    for (int i = 0; i < arraysize - 1; i++)
    {
        for (int j = 0; j < arraysize - i - 1; j++)
        {
            if (lista[j].x > lista[j + 1].x || (lista[j].x == lista[j + 1].x && lista[j].y > lista[j + 1].y))
            {
                swap(lista, j, j + 1);
            }
        }
    }
}

void calcula_reta(Ponto p1, Ponto p2, double lista[3])
{
    lista[0] = p2.y - p1.y;
    lista[1] = p1.x - p2.x;
    lista[2] = p1.x * p2.y - p1.y * p2.x;
}

bool compara_pontos(Ponto p1, Ponto p2)
{
    return (p1.x==p2.x && p1.y==p2.y);
}


bool mesmo_lado(Ponto p1, Ponto p2, Ponto lista[], int array_size)
{
    double listad[3];
    calcula_reta(p1, p2, listad);

    int sup = 0, inf = 0;

    for (int i = 0; i < array_size; i++)
    {
        if (!compara_pontos(lista[i], p1) && !compara_pontos(lista[i], p2))
        {
            double lado = listad[0] * lista[i].x + listad[1] * lista[i].y - listad[2];
            
            if (lado < 0)
                inf++;
            else if (lado > 0)
                sup++;
        }
    }

    return (inf == 0 || sup == 0);
}

bool busca_ponto(Ponto p1, Ponto lista[], int arraysize)
{
    for (int i = 0; i < arraysize; i++)
    {
        if (compara_pontos(p1, lista[i]))
        {
            return true;
        }
    }
    return false;
}

int envoltoria_convexa(Ponto lista[], int array_size, Ponto lista_pontos[])
{

    int tam_l_pontos = 0;

    for (int i = 0; i < array_size; i++)
    {
        for (int j = 1+i; j < array_size; j++)
        {
            if (j != i)
            {
                if (mesmo_lado(lista[i], lista[j], lista, array_size))
                {
                    if (tam_l_pontos == 0)
                    {
                        tam_l_pontos += 2;
                        lista_pontos[0] = lista[i];
                        lista_pontos[1] = lista[j];
                    }
                    else
                    {
                        if (!busca_ponto(lista[i], lista_pontos, tam_l_pontos))
                        {
                            lista_pontos[tam_l_pontos] = lista[i];
                            tam_l_pontos++;
                        }
                        if (!busca_ponto(lista[j], lista_pontos, tam_l_pontos))
                        {
                            lista_pontos[tam_l_pontos] = lista[j];
                            tam_l_pontos++;
                        }
                    }
                }
            }
        }
    }
    return tam_l_pontos;
}
void imprime_pontos(Ponto lista[], int arraysize)
{
    for (int i = 0; i < arraysize; i++)
    {
        printf("%.4lf %.4lf\n", lista[i].x, lista[i].y);
    }
}

int main(int argc, char const *argv[])
{
    int tamanho;
    scanf("%d", &tamanho);
    Ponto lista[tamanho];
    Ponto lista_pontos[tamanho];

    for (int i = 0; i < tamanho; i++)
    {
        scanf("%lf %lf", &lista[i].x, &lista[i].y);
    }

    int tam = envoltoria_convexa(lista, tamanho, lista_pontos);
    ordena(lista_pontos,tam);
    imprime_pontos(lista_pontos, tam);
    return 0;
}
