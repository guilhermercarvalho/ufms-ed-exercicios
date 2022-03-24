#include <cstdio>
#include "Celula.hpp"

Celula::Celula(int chave)
{
  this->chave = chave;
  this->proximo = NULL;
}

Celula::Celula()
{
  this->proximo = NULL;
}

void Celula::escrever(const char *separador)
{
  printf("%d%s", this->chave, separador);
}