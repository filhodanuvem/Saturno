# To change this template, choose Tools | Templates
# and open the template in the editor.

require 'graphviz.rb'



class Grafo

  
  @@singleton = Grafo.new # única instancia de Grafo
                # Atributo pra fazer com que a operação de busca da ordem do grafo se torne O(1)

  private_class_method :new

  def initialize
   
  end
  
  # Grafo é um singleton, ou seja, esse metodo retorna a unica instancia da classe
  def self.cria_grafo
    @roteadores = {}        # Hash com apontadores para os roteadores do grafo, busca O(1)
    $marcados   = []
    @ordem = 0
    @@singleton
  end

#  Insere vertice na estrutura de hash 
  def insere_vertice(vertice)
    if(vertice.kind_of? Roteador)
      if(@roteadores.class == NilClass)
        @roteadores = {}
      end
      @roteadores[vertice.ip] = vertice
      if(@ordem.class == NilClass)
        @ordem = 1
      else
        @ordem += 1
      end
      
    else
      raise Exception.new("Esperado um vertice")
    end
    
  end
  
  #Remove um vertice do hash
  def remove_vertice(vertice)
    if(@roteadores.has_key?(vertice.ip))
      @roteadores.delete(vertice.ip)

      @roteadores.each_value do |roteador|
        roteador.enlaces.each do |enlace|
          if(enlace.vertices[1] == vertice)
            roteador.enlaces.delete(enlace)
            enlace.vertices.delete(vertice)
          end
       end
      
    end
  end
    @ordem -= 1 
  end

  # Retorna informacao se o grafo é completo
  def completo?(vertice)
    if(!vertice.kind_of? Roteador)
      raise Exception.new("Esperadao um vertice")
    end
    
    completo = true;
    @roteadores.each { |id,roteador|
      if(roteador.grau != @ordem)
        completo = false
        break
      end
    }
    completo
  end

  # Retorna o ordem do grafo
  def ordem_grafo
    @ordem
  end

  # Zera atributos marcados de todos os vertices
  def zerar_marcados
    @roteadores.each_value  do |roteador|
      roteador.marcado = false
    end
  end

  # Imprime todo o grafo
  def to_s
    @roteadores.each_value do |roteador|
      puts roteador.mostra_vizinhos
      end
    end

    # Cria a tabela de roteamento
    def cria_tabela
      @roteadores.each_value do |vertice|
        tabela = Hash.new()
        @roteadores.each_value do |interno|
          if(interno.ip != vertice.ip)
              tabela[interno.ip] = Hash.new()
          end
        end
        vertice.tabela = tabela
      end
    end

    # Algoritmo de Bellman-Ford 
    def vetor_distancia(emissor)      
      cria_tabela
      zerar_marcados
      emissor.marcado = true
      # atualiza a tabela de cada vertice alcançado pelo emissor
      emissor.enlaces.each do |enlace|
        vizinho = enlace.vertices[1]
        vizinho.as_path[vizinho.as_path.length] = emissor.ip
        emissor.tabela[vizinho.ip][vizinho.ip]  = enlace.peso
      end
      emissor.anuncia(emissor.enlaces[0].vertices[1],emissor)
    end

    # Algoritmo de dikstra sendo implementado junto com o atributo AS_PATH
    def dijkstra(origem,destino)
      if(!(origem.class ==  RoteadorASPath) || !(origem.class == RoteadorASPath))
        raise Exception.new("Esperado um roteadorASPath")
      end

      if(!@roteadores.include?(origem.ip) )
        raise Exception.new("Roteador #{origem.ip} não encontrado no grafo")
      end


      if(!@roteadores.include?(destino.ip) )
        raise Exception.new("Roteador #{destino.ip} não encontrado no grafo")
      end

      ordem = ordem_grafo
      atingidos =  0;
      vetor_distancia(origem)
      zerar_marcados
      vertice = origem
      vertice.as_path = Array.new 
      vertice.distancia = 0
      while(atingidos < ordem )
        if(vertice != nil && !vertice.marcado?)
          vertice.marcado = true
          vertice.enlaces.each do |enlace|
          vizinho = enlace.vertices[1];
          if(vizinho.distancia > vertice.distancia +  enlace.peso)
            vizinho.distancia = vertice.distancia + enlace.peso;
            vizinho.as_path = vertice.as_path.clone
            vizinho.as_path.push(vertice.ip)
          end
         end
         vertice  = vertice.vizinho_mais_proximo
         atingidos += 1 
        end
      end
      origem.as_path = destino.as_path.clone
      origem.as_path.push(destino.ip)
      
    end

    # Algortimo de roteamento de next-hop, utiliza apenas a informação de próximo salto para chegar no destino
    def next_hop(emissor,destino)
      unless(emissor.kind_of?(Roteador)|| destino.kind_of?(Roteador) )
        raise Excepetion.new("Esperado um roteador")
      end

      vetor_distancia(emissor)
      zerar_marcados
      if(emissor.menor_da_tabela(destino.ip) < 100000)
        while(emissor != destino && !emissor.nil?)
          menor = 100000
          vizinho = nil
          
          emissor.enlaces.each do |enlace|
            if(enlace.peso < menor && !enlace.vertices[1].marcado?)
              menor   = enlace.peso
              vizinho = enlace.vertices[1]
            end
          end
          unless(emissor.marcado?)
            puts "#{emissor.ip}"
            emissor.marcado = true
          end
          emissor = vizinho
        end
        
      else
        raise Exception.new("Imposível alcançar roteador #{destino.ip}")
      end
      puts "#{destino.ip}"
    end

    # Mostra tabelas de roteamento dos vertices, essas tabelas guardam a informação da distancia de um vertice até cada um dos outros
    def mostra_tabelas
      retorno = ""
      @roteadores.each_value do |vertice|
        retorno += vertice.mostra_tabela
      end
      retorno
    end

   # Gera uma imagem de nome fileName com o grafo represenado
    def plotar(fileName)
      marcados = Array.new
      graph =  GraphViz.new("grafo",{:type => "graph"}) #cria um grafo simples
      @roteadores.each_value do |roteador|
        node1 = graph.add_node("#{roteador.ip}")
        roteador.enlaces.each  do |enlace|
          if(!marcados.include?([enlace.vertices[0],enlace.vertices[1]]) && !marcados.include?([enlace.vertices[1],enlace.vertices[0]]) )
            vizinho = enlace.vertices[1]
            node2 = graph.add_node("#{vizinho.ip}")
            marcados[marcados.length] = [enlace.vertices[1],enlace.vertices[0]]
            aresta = graph.add_edge(node1,node2)
            aresta.set{ |e| e.color = "blue"
                 e.label =  "#{enlace.peso}"
            }
          end
        end
      end
      if(!fileName.nil? && fileName.class == String)
        graph.output( :png => "#{fileName}.png" )
      else
        raise Exception.new("Grafo não plotado, nome inválido!")
      end
    end
end
