# To change this template, choose Tools | Templates
# and open the template in the editor.
require 'roteador'

class RoteadorASPath < Roteador

  attr_reader :tabela , :as_path
  attr_writer :tabela , :as_path

  # RoteadorASPath  extend Roteador
  # é o único que utiliza 
  def initialize(asn)
    @as_path = []
    @tabela  = {}     # Tabela de hash do tipo { id_destino =>  { id_via  => custo  }    }
    super(asn)
  end

  def mostra_as_path
    retorno  = "AS_PATH \n"
    i = 0
    @as_path.each do |id|
      retorno += "#{i+=1}º) #{id}\n"
    end
    puts retorno
  end

  def mostra_tabela
    retorno = "Tabela de #{@ip} \n"
    @tabela.each_key do |to|
      @tabela[to].each do |from,value|
        retorno += "Para #{to} via #{from} custo #{value} \n"
      end
    end
    retorno
  end

  def menor_da_tabela to
    menor = 100000
    @tabela[to].values.each do |from|
      unless(from == {})
        if(menor > from)
          menor = from
        end
      end
    end
    menor
  end

  def anuncia(destino,origem)
    if(!destino.kind_of? Roteador)
      raise Exception.new("Esperado um roteador")
    end

      origem.as_path[origem.as_path.length] = destino.ip
     

      destino.enlaces.each do |enlace|
        vizinho = enlace.vertices[1]
        #atual = (destino == self)?vizinho : destino
         if(origem.tabela[vizinho.ip].nil?)
              origem.tabela[vizinho.ip] = Hash.new
        end

        novaDistancia = enlace.peso  + origem.menor_da_tabela(destino.ip)
        if(origem.tabela[vizinho.ip][destino.ip] == nil && (vizinho != origem))
          origem.tabela[vizinho.ip][destino.ip] = novaDistancia
        else
        if(vizinho != origem)
          origem.tabela[vizinho.ip][destino.ip] = (novaDistancia < origem.tabela[vizinho.ip][destino.ip])?novaDistancia : origem.tabela[vizinho.ip][destino.ip]
        end
        
          if(!vizinho.marcado?)
            vizinho.marcado = true
            destino.anuncia(vizinho,origem)
          end
        end
      end
    
  end

end

  

