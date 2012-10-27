
package br.cloud.dataming.kmeansjava;

import java.util.ListIterator;

/**
 *
 * @author Claudson Oliveira
 */
public class GrupoManager {
    
    protected Grupo[] grupos;
    protected int k;
    protected int mudancas = 0;
    
    
    public GrupoManager(int k, Wine[] centros){
        this.grupos = new Grupo[k];
        for(int i = 0; i < k; i++){
            this.grupos[i] = new Grupo();
            this.grupos[i].setCentro(centros[i]);
        }
        this.k = k;
        
    }
    
    public void addInstancia(Wine instancia, int id){
        if(this.k <= id){
            throw new IllegalArgumentException("Grupo inexistente");
        }
        
        if(!this.grupos[id].contains(instancia)){
            this.grupos[id].add(instancia);
            
            for(int i=0; i < this.k; i++){
                if(i != id && this.grupos[i].contains(instancia)){
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
        while(i < this.k){
            distancia = wine.distance_euclidian(this.grupos[i].centro);
            if(distancia < menorDistancia){
                menorDistancia = distancia;
                centro = i;
            }
            i++;
        }
        
        return centro;
    }
    
    public Wine instanciaMaisProxima(Wine pivo, Grupo grupo)
    {
        Wine instancia = null, maisProxima = null;
        int i = 0;
        double distancia = 0,menorDistancia = Double.MAX_VALUE; 
        ListIterator<Wine> list = grupo.instancias.listIterator();
        
        while(list.hasNext()){
            instancia = list.next();
            distancia = pivo.distance_euclidian(instancia);
            if(distancia < menorDistancia){
                menorDistancia = distancia;
                maisProxima = instancia;
            }
            i++;
        }
       
        return maisProxima;
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
    
    public void estatisticas(Wine[] instancias){
        int i=0;
        int[] contadores_classes = new int[this.k];
        while(i < this.k) {
            contadores_classes[i] =0;
            i++;
        }
        i=0;
        while(i < KmeansJava.NUMERO_INSTANCIAS) {
            Wine atual = instancias[i];
            contadores_classes[atual.real_class - 1]++;
            i++;
        }
        i=0;
        while(i < this.k) {
            System.out.println("Grupo "+(i+1)+" esperava"+contadores_classes[i++]);
        }
        
        
       
    }
}
