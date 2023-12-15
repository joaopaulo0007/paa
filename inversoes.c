#include <stdio.h>

void swap(int lista[],int pos1,int pos2){
   int* temp= lista[pos1];
   lista[pos1]=lista[pos2];
   lista[pos2]=temp;
}
int buble_sort(int lista[],int array_size){
    int num_inversoes=0;
    for (int i = 0; i < array_size-1; i++)
    {
        for (int j = 0; j< array_size-1-i; j++)
        {
            if (lista[j]>lista[j+1])
            {
                swap(lista,j,j+1);
                num_inversoes++;
            }
        }
    }
    return num_inversoes;
    
}
int main()
{
    int tam;
    scanf("%d",&tam);
    int lista[tam];
    for (int i = 0; i < tam; i++)
    {
        scanf("%d",&lista[i]);
    }
    printf("%d",buble_sort(lista,tam));
    return 0;
}
