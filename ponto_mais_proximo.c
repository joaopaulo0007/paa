#include <stdio.h>
#include <math.h>
typedef struct{
    int x;
    int y;
}Ponto;
int calcula_distancia(Ponto p1, Ponto p2 ){
   return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}
double calcula_menor_distancia(Ponto lista[],int tamanho){
    int menor =__INT_MAX__;
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 1; j < tamanho; j++)
        {
            if (i!=j)
            {
                menor=fmin(menor,calcula_distancia(lista[i],lista[j]));
            }
            
        }
        
    }
    return sqrt(menor);
    
}
int main()
{
    int tam;
    scanf("%d",& tam);
    Ponto lista[tam];
    for (int i = 0; i < tam; i++)
    {
        scanf("%d %d",&lista[i].x,&lista[i].y);
    }
    printf("%.4lf",calcula_menor_distancia(lista,tam));
    return 0;
}
