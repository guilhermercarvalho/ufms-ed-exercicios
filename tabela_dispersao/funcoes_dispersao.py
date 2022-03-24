from cmath import sqrt
from math import floor

class FuncoesDeDispersao:
    def __init__(self, tamanho_tabela):
        self.tamanho_tabela = tamanho_tabela

    def h_dispersao_aux(self, chave):
        res = chave % self.tamanho_tabela
        # print("{} % {} = {}".format(chave,self.tamanho_tabela, res))
        return res

    def tentativa_linear(self, tentativa, h_linha):
        res = (h_linha + tentativa) % self.tamanho_tabela
        # print("({} + {}) % {} = {}".format(h_linha, tentativa, self.tamanho_tabela, res))
        return res

    def tentativa_quadratica(self, c1, c2, tentativa, h_linha):
        res = (h_linha + c1 * tentativa + c2 * tentativa ** 2) % self.tamanho_tabela
        # print("{} + {} * {} + {} * {} ** 2) % {} = {}".format(h_linha, c1, tentativa, c2, tentativa,self.tamanho_tabela, res))
        return res

    def tentativa_dispercao_dupla(self, h1, h2, tentativa):
        res = (h1 + (tentativa * h2)) % self.tamanho_tabela
        # print("({} + {} * {}) % {} = {}".format(h1, tentativa, h2, self.tamanho_tabela, res))
        return res

    def h_exercicio_2_4(self, chave):
      A = ((sqrt(5)-1)/2).real
      return floor(self.tamanho_tabela * (A * chave - floor(A * chave)))

    def h1(self, chave, tabela):
        i = 0
        j = 0
        while True:
            j = self.h_dispersao_aux(chave, i)
            if(tabela[j] == -1):
                tabela[j] = chave
                return j
            else:
                i = i + 1
            if (i == self.tamanho_tabela):
                break
        return self.tamanho_tabela

    # Impressão
    def prCyan(self, skk): return "\033[96m{}\033[00m" .format(skk)
    def prRed(self, skk): return "\033[91m{}\033[00m" .format(skk)

    def imprime_chave_alocada(self, chave, tentativa, posicao):
        out = "h({x},{i}) = ({hx} + {i} ) mod {m} = {p}".format(x=chave, i=tentativa, hx=self.h_dispersao_aux(chave), m=self.tamanho_tabela, p=posicao)
        print(self.prCyan(out))
        # print("posx: {};\t chave: {};\t tentativa: {}".format(self.prCyan(posicao), self.prCyan(chave), self.prCyan(tentativa)))

    def imprime_chave_nao_alocada(self, chave, tentativa, posicao):
        out = "h({x},{i}) = ({hx} + {i} ) mod {m} = {p}".format(x=chave, i=tentativa, hx=self.h_dispersao_aux(chave), m=self.tamanho_tabela, p=posicao)
        print(self.prRed(out))
        # print("posx: {};\t chave: {};\t tentativa: {}".format(self.prRed(posicao), self.prRed(chave), self.prRed(tentativa)))

    # Exercícios
    def tentativa_linear_exercicio(self, chave, tentativa):
        return self.tentativa_linear(tentativa=tentativa, h_linha=self.h_dispersao_aux(chave))

    def tentativa_quadratica_exercicio(self, chave, c1, c2, tentativa):
        return self.tentativa_quadratica(c1, c2, tentativa, h_linha=self.h_dispersao_aux(chave))

    def tentativa_dispercao_dupla_exercicio(self, chave, h2, tentativa):
        return self.tentativa_dispercao_dupla(h1=self.h_dispersao_aux(chave), h2=h2, tentativa=tentativa)
