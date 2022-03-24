#!/usr/bin/env python3
import json
from tokenize import tabsize
from endereco_aberto import EnderecoAberto

chaves = [5, 28, 19, 15, 20, 33, 12, 17, 10]

tabela_5 = [-1] * 11

tabela = {
    0: [],
    1: [],
    2: [],
    3: [],
    4: [],
    5: [],
    6: [],
    7: [],
    8: [],
}

ea = EnderecoAberto(tamanho_tabela=1000, chaves=chaves)

print("Linear")
ea.calcula_endereco("X")
ea.imprime_tabela()
