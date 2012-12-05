# To change this template, choose Tools | Templates
# and open the template in the editor.

require 'aresta'

# Classe que repesenta um roteador numa rede
class Roteador


  attr_reader :enlaces, :ip , :distancia , :tabela
  attr_writer :enlaces, :distancia , :tabela

  private_methods :vizinho_fuga

  @@count = 1 # Atributo de classe 

  #Construtor da classe
  # ip seria o identificador do roteador
  # asn seria o número identificador de AS
  # marcado é um atributo para perceber se esse roteador ja foi atingido
  
  def initialize( asn )
    #atributos de instancia 
    @asn     = asn     # ASN seria um identificador de qual subrede eu me encontro
    @enlaces = []      # Array de objetos Arestas que se ligam ao vertice
    @marcado = false   # Muito usado em operacoes onde não podemos visitar um vertice mais de uma vez
    @ip = @@count      # ip é por padrão um inteiro que é incrimentado a media que os vértices vão sendo criados
    @@count += 1      
    @distancia = 10000 #trocar por numero grande/
  end

  #método set do atributo marcado 
  def marcado=(marcado)
    @marcado = (marcado==false|| marcado == 0 )?false:true
  end

  #método predicativo que testa se o atributo marcado é true, como um is_marcado
  def marcado?
    (@marcado==0 || @marcado == false)?false:true
  end

  #método predicativo que testa se o vertice passado por parametro é adjacente do corrente, como um is_adjacente
  def adjacente?(vertice)
    if(!vertice.class == Roteador)
      raise Exception.new("Esperado um vertice")
    end

    adjacente = false
    @enlaces.each_index do |index|
      if(@enlaces[index].vertices.include?(vertice))
        adjacente = true
        break
      end
    end
    adjacente
  end

  # Adiciona um vertice adjacente ao corrente, passando o peso da aresta
  # Obs: Os protocolos funcionam full-duplex, ou seja, a aresta não tem direção e o método faz com o
  # esse vertice inseredo também tenha como vizinho o corrente (Relação reflexiva) 
  def insere_vertice_adjacente(vertice,peso_aresta)
    novo_enlace = Aresta.new(peso_aresta, self, vertice)
    if(!@enlaces.include?(novo_enlace))
      @enlaces.push(novo_enlace)
      novo_enlace = Aresta.new(peso_aresta,vertice,self) #mesma aresta só com vertices "opostos"
      vertice.enlaces.push(novo_enlace)
    end
  end

  # Remove uma ligação a um vertice
  def remove_vertice_adjacente(vertice)
    if @enlaces.include?(vertice)
      @enlaces.each do |index|
        if (@enlaces[index] == vertice)
          @enlaces[index] = nil;
        end
      end
    end
  end

  # Método que imprime o roteador, como um to_string em java
  def to_s
    "id #{@ip} - ASN #{@asn} - distancia #{@distancia}"

  end

  # Método que imprime os vizinhos
  def mostra_vizinhos 
    @marcado = 1
    retorno = "#{self}"
    @enlaces.each do |enlace|
        retorno += "\n\t  #{enlace}"
    end
    retorno
  end

  # Retorna o vizinho mais proximo (que não estava marcado) de um roteador baseado no atributo distancia
  # caso esse roteador não exista, ele vai buscar um vizinho de algum dos seus adjacentes (nível 3 no grafo) que satisfaça
  # essa relação
  def vizinho_mais_proximo
    proximo = nil
    @enlaces.each do |enlace|
      if(proximo == nil || proximo.distancia > enlace.vertices[1].distancia)
        if(!enlace.vertices[1].marcado?)
          proximo = enlace.vertices[1]
        end
      end
    end

    if(proximo.nil?)
      proximo = vizinho_fuga
    end
    proximo
  end

  # Usado estritamente como um caso particular de vizinho_mais_proximo.
  # Esse método busca o vertice adjacente a um vizinho, com menor distancia
  def vizinho_fuga
    fuga = nil
    menor = 10000
    @enlaces.each do |enlace|
      vizinho = enlace.vertices[1]
      vizinho.enlaces.each do |enlace_interno|
        vizinho_do_vizinho = enlace_interno.vertices[1]
        if(!vizinho_do_vizinho.marcado?)
          if(enlace_interno.peso + vizinho.distancia < menor)
            menor = enlace_interno.peso + vizinho.distancia
            fuga = vizinho_do_vizinho
          end
        end
      end
    end
    fuga
  end

  # Retorna o grau 
  def grau
    @enlaces.length
  end
end