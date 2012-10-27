
package br.cloud.dataming.kmeansjava;

import java.util.ArrayList;

/**
 * @author Claudson Oliveira
 */
public class Grupo 
{
    protected Wine centro; 
    protected ArrayList<Wine> instancias;

    public Grupo() {
        this.instancias = new ArrayList<Wine>();
    }
    
    
    public void add(Wine instancia){
        this.instancias.add(instancia);
    }
    
    public boolean contains(Wine instancia){
        return this.instancias.contains(instancia);
    }
    
    public void remove(Wine instancia){
        this.instancias.remove(instancia);
    }

    @Override
    public String toString() {
        String texto = " Grupo ("+this.instancias.size()+") ";
        return texto;
    }

    public Wine getCentro() {
        return centro;
    }

    public void setCentro(Wine centro) {
        this.centro = centro;
    }
    
    public int size(){
        return this.instancias.size();
    }
    
    public Wine get(int i){
        return this.instancias.get(i);
    }
    
}
