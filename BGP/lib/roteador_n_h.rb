# To change this template, choose Tools | Templates
# and open the template in the editor.

class RoteadorNH < RoteadorASPath

  private :as_path

  def initialize(asn)
    @next_hop
    # Tabela de hash do tipo { id_destino =>  { id_via  => custo  }    }
    @tabela = {}
    super(asn)
  end

  
  
end
