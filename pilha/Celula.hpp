#include <cstdio>

class Celula
{
  friend class Pilha;

public:
  Celula(int chave);
  Celula();
  void escrever(const char *separador = ", ");

private:
  int chave;
  Celula *proximo;
};