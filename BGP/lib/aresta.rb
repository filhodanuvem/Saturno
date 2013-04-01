# To change this template, choose Tools | Templates
# and open the template in the editor.

class Aresta

  attr_reader :peso, :vertices
  attr_writer :peso

  def initialize(peso,vertice1,vertice2)
    @ip
    @peso = peso
    @vertices = [vertice1,vertice2];
    @marcada = false

  end

  def marcada?
    @marcada
  end

  def marcada=(valor)
    marcada = (valor == 0 || valor == false)?false : true
  end

  def to_s
    vizinho = @vertices[1]
    "peso #{@peso}-> roteador #{vizinho.ip}"
  end
end
