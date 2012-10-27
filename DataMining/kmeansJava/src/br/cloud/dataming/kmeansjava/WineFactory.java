/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package br.cloud.dataming.kmeansjava;

import br.cloud.dataming.kmeansjava.Wine;
import br.cloud.dataming.kmeansjava.KmeansJava;

/**
 *
 * @author cloud
 */
public class WineFactory 
{
    public static Wine criarWine(String linha)
    {
        Wine wine = new Wine();
        String[] atributos = linha.split("\t");
        for(int i = 0; i < atributos.length; i++){
            double valor = Double.parseDouble(atributos[i]);
            wine.set(i,valor);
        }
        
        return wine;
    }        
    
    
}
