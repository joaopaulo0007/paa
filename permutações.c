#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // Adicionado para usar malloc

typedef struct {
    int num;
    bool direcao;

} Item;

void swap(int a, int b, Item lista[]) {
    Item temp = lista[a];
    lista[a] = lista[b];
    lista[b] = temp;
}

bool verifica_maior(int pos, int array_size, Item lista[]) {
    if (pos == 0) {
        return lista[pos].direcao && lista[pos].num > lista[pos + 1].num;
    } else if (pos == array_size - 1) {
        return !lista[pos].direcao && lista[pos].num > lista[pos - 1].num;
    } else {
        return lista[pos].direcao ? lista[pos].num > lista[pos + 1].num && lista[pos].num > lista[pos - 1].num : lista[pos].num > lista[pos - 1].num && lista[pos].num > lista[pos + 1].num;
    }
}

int procura_maior(Item lista[], int array_size) {
    int maior = -1, pos = -1;

    for (int i = 0; i < array_size; i++) {
        int next_pos = (lista[i].direcao) ? i + 1 : i - 1;

        if (next_pos >= 0 && next_pos < array_size && verifica_maior(i, array_size, lista)) {
            if (lista[i].num >= maior) {
                pos = i;
                maior = lista[i].num;
            }
        }
    }
    return pos;
}

void troca_direcao(int array_size, Item lista[], int pos_maior) {
    for (int i = 0; i < array_size; i++) {
        if (lista[i].num > lista[pos_maior].num) {
            lista[i].direcao = !lista[i].direcao;
        }
    }
}

void imprime_permutacao(Item lista[], int array_size) {
    for (int i = 0; i < array_size; i++) {
        printf("%d ", lista[i].num);
    }
    printf("\n");
}

void johnson_trotter(int array_size, Item lista[]) {
    int iteracoes = 0;
    int max_iteracoes = 100000;

    imprime_permutacao(lista, array_size);

    while (iteracoes < max_iteracoes) {
        int pos_maior = procura_maior(lista, array_size);
        if (pos_maior == -1) {
            // Não há mais trocas possíveis
            break;
        }

        int next_pos = (lista[pos_maior].direcao) ? pos_maior + 1 : pos_maior - 1;

        if (next_pos >= 0 && next_pos < array_size) {
            swap(pos_maior, next_pos, lista);
            troca_direcao(array_size, lista, pos_maior);

            iteracoes++;
            imprime_permutacao(lista, array_size);
        } else {
            // Inverte a direção se não houver uma troca possível na direção atual
            lista[pos_maior].direcao = !lista[pos_maior].direcao;
            imprime_permutacao(lista, array_size);  // Adicionado para imprimir a permutação atual
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    // Usando alocação dinâmica de memória
    Item *lista = (Item *)malloc(n * sizeof(Item));

    for (int i = 0; i < n; i++) {
        lista[i].num = i + 1;
        lista[i].direcao = false;
    }
    johnson_trotter(n, lista);

    // Liberando a memória alocada dinamicamente
    free(lista);

    return 0;
}
