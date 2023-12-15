#include <stdio.h>
typedef struct{
    int nota;
    int cpf;
}Aluno;
void busca_binaria(int comeco, int fim, Aluno lista[], int cpf){
    int meio=(comeco+fim)/2;
    if (comeco>fim)
    {
        printf("NAO SE APRESENTOU\n");
        return;
    }
    else if(lista[meio].cpf== cpf){
        printf("%d\n", lista[meio].nota);
        return;
    }
    else if(lista[meio].cpf>cpf){
        return busca_binaria(comeco,meio-1,lista,cpf);
    }
    else{
        return busca_binaria(meio+1,fim,lista,cpf);
    }
    
}
void adicionar(Aluno lista[],Aluno aluno,int pos){
    lista[pos] = aluno;
}
int main(int argc, char const *argv[])
{
    int num_pessoas;
    scanf("%d",&num_pessoas);
    Aluno lista[num_pessoas];
    for (int i = 0; i < num_pessoas; i++)
    {
        scanf("%d",&lista[i].cpf);
    }
    for (int i = 0; i < num_pessoas; i++)
    {
        scanf("%d",&lista[i].nota);
    }
    int num_tentativas;
    scanf("%d",&num_tentativas);
    for (int i = 0; i < num_tentativas; i++)
    {
        int cpf;
        scanf("%d",&cpf);
        busca_binaria(0,num_pessoas-1,lista,cpf);
    }
    
    
    return 0;
}
