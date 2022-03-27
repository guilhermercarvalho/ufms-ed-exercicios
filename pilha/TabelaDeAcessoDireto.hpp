#include <cstdio>
#include "Pilha.hpp"

class TabelaDeAcessoDireto
{
  public:
  TabelaDeAcessoDireto(int m);
  ~TabelaDeAcessoDireto();
  void inserir(int indice, int chave);
  void escrever(void);
  int maior(void);

  private:
    Pilha *tabela;
    int tamanho;
};
