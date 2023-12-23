#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int celebridade(int n, int **conhece)
{
  if (n < 2)
  {
    return -1;
  }
  int candidato = 0;
  for (int i = 1; i < n; i++)
  {
    if (conhece[candidato][i])
    {
      candidato = i;
    }
  }
  for (int i = 0; i < n; i++)
  {
    if (candidato != i && (conhece[candidato][i] || !conhece[i][candidato]))
    {
      return -1;
    }
  }
  return candidato;
}

int **randomMatrix(int n)
{
  int **mat = (int **)malloc(n * sizeof(int *));
  for (int i = 0; i < n; i++)
    mat[i] = (int *)malloc(n * sizeof(int));

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      mat[i][j] = rand() % 2;
  return mat;
}

void libera(int n, int **m)
{
  for (int i = 0; i < n; i++)
    free(m[i]);
  free(m);
}

void defineCelebridade(int c, int n, int **conhece)
{
  for (int i = 0; i < n; i++)
    conhece[c][i] = 0;
  for (int i = 0; i < n; i++)
    conhece[i][c] = 1;
}

void main(int *argv)
{
  const int size = 5000; // size x size == dimensão das matrizes de teste
  srand(time(NULL));
  int **conh = randomMatrix(size);

  // Três testes aleatorios em que há celebridade
  for (int i = 0; i < 3; i++)
  {
    int cel = rand() % size;
    defineCelebridade(cel, size, conh);
    if (celebridade(size, conh) != cel)
    {
      printf("NAO");
      exit(0);
    }
  }

  // Teste em que não há celebridade
  for (int i = 0; i < size; i++)
    conh[i][(i + 1) % size] = 1;
  if (celebridade(size, conh) != -1)
  {
    printf("NAO");
    exit(0);
  }

  // Teste em que não há celebridade
  for (int i = 0; i < size; i++)
    conh[i][(i + 1) % size] = 0;
  if (celebridade(size, conh) != -1)
  {
    printf("NAO");
    exit(0);
  }

  // testes pior caso para força bruta
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      conh[i][j] = 1;
  for (int i = 0; i < 50; i++)
  {
    int cel = size - 4 + rand() % 4; // escolhe celebridade com número perto do último
    defineCelebridade(cel, size, conh);
    if (celebridade(size, conh) != cel)
    {
      printf("NAO");
      exit(0);
    }
  }

  libera(size, conh);
  printf("SIM");
}
