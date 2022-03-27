#include <cstdio>
#include <bits/stdc++.h>
#include "Pilha.hpp"

Pilha::Pilha()
{
  topo = new Celula();
}

Pilha::~Pilha()
{
  while (!vazia())
    desempilhar();
  delete topo;
}

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
      ponteiro->escrever("");
    else
      ponteiro->escrever();
}

int Pilha::maior(void)
{
  Celula *ponteiro;
  int maior = INT_MIN;

  for (ponteiro = topo->proximo; ponteiro != NULL; ponteiro = ponteiro->proximo)
    if (ponteiro->chave > maior)
      maior = ponteiro->chave;

  return maior;
}

bool Pilha::vazia(void)
{
  return topo->proximo == NULL;
}
