
require 'grafo'
require 'roteador_a_s_path'
require 'graphviz'
require 'gtk_grafo'

# ---------------------------------------- Exemplo de roteamento usando AS_path 

grafo = Grafo.cria_grafo
v1 = RoteadorASPath.new(1)
v2 = RoteadorASPath.new(1)
v3 = RoteadorASPath.new(1)
v4 = RoteadorASPath.new(1)
v5 = RoteadorASPath.new(2)
v6 = RoteadorASPath.new(2)

v1.insere_vertice_adjacente(v2, 4)
v1.insere_vertice_adjacente(v3, 5)
v2.insere_vertice_adjacente(v3, 0)
v3.insere_vertice_adjacente(v4, 3)


grafo.insere_vertice(v1)
grafo.insere_vertice(v2)
grafo.insere_vertice(v3)
grafo.insere_vertice(v4)

puts "Next-hop partindo de v1 para v3"
grafo.next_hop(v1,v3)

nome_arquivo = "imagem0a"

grafo.cria_tabela
grafo.plotar(nome_arquivo)

Gtk_grafo::gera_janela(nome_arquivo) # Caso não seja encontrado o gtk, comente essa linha
