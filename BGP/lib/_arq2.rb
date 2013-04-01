
require 'grafo'
require 'roteador_a_s_path'
require 'graphviz'
require 'gtk_grafo'

# --------------------------------------- Exemplo de Next-hop

grafo = Grafo.cria_grafo
v1 = RoteadorASPath.new(1)
v2 = RoteadorASPath.new(1)
v3 = RoteadorASPath.new(1)
v4 = RoteadorASPath.new(1)

v1.insere_vertice_adjacente(v2, 5)
v1.insere_vertice_adjacente(v3, 2)
v1.insere_vertice_adjacente(v4, 1)
v2.insere_vertice_adjacente(v3, 1)
v3.insere_vertice_adjacente(v4, 2)

grafo.insere_vertice(v1)
grafo.insere_vertice(v2)
grafo.insere_vertice(v3)
grafo.insere_vertice(v4)

puts "Next-hop"
grafo.next_hop(v1, v2)


nome_arquivo = "imagem1"
grafo.plotar(nome_arquivo)

Gtk_grafo::gera_janela(nome_arquivo) # Caso não seja encontrado o gtk, comente essa linha
