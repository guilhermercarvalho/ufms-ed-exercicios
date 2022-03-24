from funcoes_dispersao import FuncoesDeDispersao


class EnderecoAberto:
    chaves = []
    tabela = []
    posicoes_ocupadas = []
    fd = None

    def __init__(self, tamanho_tabela, chaves) -> None:
        self.fd = FuncoesDeDispersao(tamanho_tabela)
        self.chaves = chaves

    def prRed(self, skk): return "\033[91m{}\033[00m" .format(skk)

    def imprime_tabela(self):
        print("\nInalocados: \t{}".format(self.prRed(self.chaves_inalocadas())))
        print("Tabela: \t{}\nPosições \t{}\n".format(
            self.tabela, self.posicoes_ocupadas))
        self.tabela = []
        self.posicoes_ocupadas = []

    def imprime_tabela_not_none(self):
        for posicao in self.tabela:
            if (posicao != None):
                print(posicao, self.tabela.index(posicao))

    def chaves_inalocadas(self):
        return list(set(self.chaves) - set(self.tabela))

    def tantativa_linear(self, chave, tentativa):
        return self.fd.tentativa_linear_exercicio(chave, tentativa)

    def tantativa_quadratica(self, chave, tentativa):
        return self.fd.tentativa_quadratica_exercicio(chave, 1, 3, tentativa)

    def dispersao_dupla(self, chave, tentativa):
        h2 = 1 + (chave % (self.fd.tamanho_tabela - 1))
        return self.fd.tentativa_dispercao_dupla_exercicio(chave, h2, tentativa)

    def funcao_calcular(self, funcao, chave, tentativa):
        if (funcao == "TL"):
            return self.tantativa_linear(chave, tentativa)
        elif (funcao == "TQ"):
            return self.tantativa_quadratica(chave, tentativa)
        elif (funcao == "DD"):
            return self.dispersao_dupla(chave, tentativa)
        else:
            return self.fd.h_exercicio_2_4(chave)

    def calcula_endereco(self, funcao):
        colisoes = 0
        for chave in self.chaves:
            tentativa = 0
            is_alocado = False

            while (is_alocado == False and tentativa < self.fd.tamanho_tabela):
                posicao = self.funcao_calcular(funcao, chave, tentativa)

                if (self.posicoes_ocupadas.__contains__(posicao) == False):
                    self.posicoes_ocupadas.append(posicao)
                    self.tabela.append(chave)
                    is_alocado = True
                    self.fd.imprime_chave_alocada(chave, tentativa, posicao)
                else:
                    colisoes = colisoes + 1
                    self.fd.imprime_chave_nao_alocada(
                        chave, tentativa, posicao)
                    tentativa = tentativa + 1

        print("\nColisões: {}".format(colisoes))

    def calcula_endereco_lista_encadeada(self, tabela_encadeada):
        for chave in self.chaves:
            posicao = self.fd.h1(chave, self.tabela)
            print("c: \t{}\tposx: \t{}".format(chave, posicao))

    def get_tabela(self):
        return self.tabela
