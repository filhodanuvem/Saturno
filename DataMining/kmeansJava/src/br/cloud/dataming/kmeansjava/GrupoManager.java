
package br.cloud.dataming.kmeansjava;

/**
 *
 * @author Claudson Oliveira
 */
public class GrupoManager {
    
    protected Grupo[] grupos;
    protected int k;
    protected int mudancas = 0;
    protected Wine[] centros;
    
    
    public GrupoManager(int k, Wine[] centros){
        this.grupos = new Grupo[k];
        for(int i = 0; i < k; i++){
            this.grupos[i] = new Grupo();
        }
        this.k = k;
        this.centros = centros;
    }
    
    public void addInstancia(Wine instancia, int grupo){
        if(this.k <= grupo){
            throw new IllegalArgumentException("Grupo inexistente");
        }
        
        if(!this.grupos[grupo].contains(instancia)){
            this.grupos[grupo].add(instancia);
            
            for(int i=0; i < this.k; i++){
                if(this.grupos[i].contains(instancia) && i != grupo){
                    this.grupos[i].remove(instancia);
                    break;
                }
            }
            this.mudancas++;
        }
        
    }
    
    public void rmInstancia(Wine instancia){
        for(int i=0; i < this.k; i++){
            if(this.grupos[i].contains(instancia)){
                this.grupos[i].remove(instancia);
                break;
            }
        }
    }
    
    public int seleciona(Wine wine)
    {
        int i = 0, centro = 0;
        double distancia = 0,menorDistancia = Double.MAX_VALUE; 
        while(i < this.centros.length){
            distancia = wine.distance_euclidian(this.centros[i]);
            if(distancia < menorDistancia){
                centro = i;
                menorDistancia = distancia;
            }
            i++;
        }
        if(centro == this.centros.length) {
            centro -= 1;
        }
        return centro;
    }
    
    public Wine instanciaMaisProxima(Wine pivo, Grupo grupo)
    {
        Wine instancia = null;
        int i = 0, centro = 0;
        double distancia = 0,menorDistancia = Double.MAX_VALUE; 
        while(i < this.centros.length){
            instancia = grupo.instancias.get(i);
            distancia = pivo.distance_euclidian(instancia);
            if(distancia < menorDistancia){
                centro = i;
                menorDistancia = distancia;
            }
            i++;
        }
       
        return instancia;
    }
    
    public Wine[] getCentros()
    {
        Wine[] centros = new Wine[this.k];
        Wine[] pseudoInstanciasMedias = new Wine[this.k];
        
        for(int i =0; i < this.k; i++){
            pseudoInstanciasMedias[i] = this.geraPseudoInstanciaMedia(this.grupos[i]);
        }
        
        this.centros = centros;
        return centros;
    }

    @Override
    public String toString() {
        String texto = "";
        for (int i = 0; i < this.grupos.length; i++) {
            texto += this.grupos[i];
        }
        
        return texto;
    }
    
    public boolean temMudancas(){
        return (this.mudancas > 0);
    }
    
    public void zerarMudancas(){
        this.mudancas = 0;
    }

    public Wine geraPseudoInstanciaMedia(Grupo grupo) {
        Wine instancia = new Wine();
        int tamanhoGrupo = grupo.size();
        for(int i= 0; i< tamanhoGrupo; i++) {
            Wine atual = grupo.get(i);
            for(int a=0; a< 12; a++){
               double valor = atual.get(a);
               instancia.set(a, instancia.get(a) + valor);
            }   
        }
        return instancia;
    }
}
