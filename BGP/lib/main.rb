
require 'grafo'
require 'roteador_a_s_path'
require 'graphviz'
#require 'gtk_grafo'


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
#v5.insere_vertice_adjacente(v4, 1)
#v6.insere_vertice_adjacente(v1, 3)
#v6.insere_vertice_adjacente(v3, 7)
#v6.insere_vertice_adjacente(v4, 2)
#v6.insere_vertice_adjacente(v5, 0)



grafo.insere_vertice(v1)
grafo.insere_vertice(v2)
grafo.insere_vertice(v3)
grafo.insere_vertice(v4)
#grafo.insere_vertice(v5)
#grafo.insere_vertice(v6)

grafo.dijkstra(v1,v3)
puts "Algoritmo de djikstra partindo de id 1"
puts grafo


puts "O grafo será gerado, digite o nome do arquivo"
nome_arquivo = "imagem0"

grafo.cria_tabela
puts "#{v1.as_path}"
grafo.plotar(nome_arquivo)

#Gtk_grafo::gera_janela(nome_arquivo)
