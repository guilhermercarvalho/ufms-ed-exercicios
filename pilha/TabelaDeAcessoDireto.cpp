#include <cstdio>
#include <bits/stdc++.h>
#include "TabelaDeAcessoDireto.hpp"

TabelaDeAcessoDireto::TabelaDeAcessoDireto(int m)
{
  tamanho = m;
  tabela = new Pilha[tamanho]();
}

TabelaDeAcessoDireto::~TabelaDeAcessoDireto()
{
  for (int i = 0; i < tamanho; i++)
    if (!tabela[i].vazia())
      tabela[i].~Pilha();
}

void TabelaDeAcessoDireto::inserir(int indice, int chave)
{
  if (indice < tamanho)
    tabela[indice].empilhar(chave);
  else
    printf("Índice inválido");
}

void TabelaDeAcessoDireto::escrever(void)
{
  for (int i = 0; i < tamanho; i++)
  {
    printf("Índice: %d", i);
    if (!tabela[i].vazia())
    {
      printf("; Chaves: { ");
      tabela[i].escrever();
      printf(" }");
    }
    else
      printf("; Chaves: { }");

    if (i != tamanho - 1)
      printf("\n\n");
    else
      printf("\n");
  }
}

int TabelaDeAcessoDireto::maior(void)
{
  int maior = INT_MIN;

  for (int i = 0; i < tamanho; i++)
    if (!tabela[i].vazia())
    {
      int maior_celula = tabela[i].maior();
      if (maior_celula != NULL && maior_celula > maior)
        maior = maior_celula;
    }

  return maior;
}