#include <cstdio>
#include "TabelaDeAcessoDireto.hpp"

int main(void)
{
  TabelaDeAcessoDireto tabela = TabelaDeAcessoDireto(10);

  tabela.inserir(1, 4);
  tabela.inserir(1, 2);
  tabela.inserir(4, 3);
  tabela.inserir(4, 30);
  tabela.inserir(7, 6);
  tabela.inserir(7, 1);
  tabela.inserir(7, 5);

  tabela.escrever();

  printf("\nMaior Chave: %d\n", tabela.maior());

  return 0;
}
