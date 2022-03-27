#include <cstdio>
#include "Celula.hpp"

class Pilha
{
public:
  Pilha();
  ~Pilha();
  void empilhar(int chave);
  int desempilhar(void);
  void escrever(void);
  bool vazia(void);
  int maior(void);

private:
  Celula *topo;
};