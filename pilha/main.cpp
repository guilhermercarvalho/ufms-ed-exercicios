#include <cstdio>
#include <bits/stdc++.h>
#include "Pilha.hpp"

int busca_maior_chave(int tamanho, Pilha tabela[])
{
  int maior = INT_MIN; // 1

  for (int i = 0; i < tamanho; i++) // 1; n + 1; n = n
    if (!tabela[i].vazia()) // 1
    {
      int maior_celula = tabela[i].maior(); // n
      if (maior_celula != NULL && maior_celula > maior) // 1
        maior = maior_celula; // 1
    }
    // (3n + n) * n = n² 

  return maior; // 1

  // n + n² + 2 = n² = O(n²)
}

int main(void)
{
  Pilha *tabela = new Pilha[10]();

  tabela[1].empilhar(4);
  tabela[1].empilhar(2);

  tabela[4].empilhar(3);
  tabela[4].empilhar(30);

  tabela[7].empilhar(6);
  tabela[7].empilhar(1);
  tabela[7].empilhar(5);

  printf("\nmaior: %d\n", busca_maior_chave(10, tabela));

  for (int i = 0; i < 10; i++)
  {
    if (!tabela[i].vazia())
      tabela[i].escrever();
  }

  // printf("A chave desempilhada foi: %d.\n", tabela[1].desempilhar());
  // tabela[1].escrever();

  return 0;
}
