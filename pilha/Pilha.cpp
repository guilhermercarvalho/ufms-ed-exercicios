#include <cstdio>
#include <bits/stdc++.h>
#include "Pilha.hpp"

Pilha::Pilha()
{
  topo = new Celula();
}

// Pilha::~Pilha()
// {
//   while (!vazia())
//     desempilhar();
//   delete topo;
// }

void Pilha::empilhar(int chave)
{
  Celula *celula = new Celula(chave);

  celula->proximo = topo->proximo;
  topo->proximo = celula;
}

int Pilha::desempilhar(void)
{
  int chave;
  Celula *ponteiro;

  ponteiro = topo->proximo;

  topo->proximo = ponteiro->proximo;

  chave = ponteiro->chave;
  delete ponteiro;

  return chave;
}

void Pilha::escrever(void)
{
  Celula *ponteiro;

  for (ponteiro = topo->proximo; ponteiro != NULL; ponteiro = ponteiro->proximo)
    if (ponteiro->proximo == NULL)
      ponteiro->escrever("\n");
    else
      ponteiro->escrever();
}

int Pilha::maior(void)
{
  Celula *ponteiro;     // 1
  int maior = INT_MIN;  // 1

  for (ponteiro = topo->proximo; ponteiro != NULL; ponteiro = ponteiro->proximo) // 1; n+1; n = n
    if (ponteiro->chave > maior)  // 1
      maior = ponteiro->chave;    // 1
    
    // 2n = n

  return maior; // 1

  // n + n + 3 = n = O(n)
}

bool Pilha::vazia(void)
{
  return topo->proximo == NULL;
}
