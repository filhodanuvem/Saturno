/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package kmeansjava;

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
        
    public static int descobreCentro(Wine wine,Wine[] centros)
    {
        int i = 0, centro = 0;
        double distancia = 0,menorDistancia = Double.MAX_VALUE; 
        while(i < KmeansJava.K){
            distancia = wine.distance_euclidian(centros[i]);
            if(distancia < menorDistancia){
                centro = i;
                menorDistancia = distancia;
            }
        }
        
        return centro;
    }
    
}
