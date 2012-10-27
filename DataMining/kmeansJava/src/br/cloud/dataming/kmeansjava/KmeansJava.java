package br.cloud.dataming.kmeansjava;

import java.util.HashMap;

/**
 *
 * @author Adriele 
 * @author Claudson 
 */
public class KmeansJava {
    
    static final int NUMERO_INSTANCIAS = 178;
    static final int K = 3;
    static final int LOOP_MAX = 100;
    
    
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        Leitor leitor = new Leitor("Wine.txt");
        Wine[] instancias = new Wine[NUMERO_INSTANCIAS];
        String linha = null;
        int i = 0;
        try{
            i =0;
            while ((linha = leitor.getLinha()) != null) {
                instancias[i++] = WineFactory.criarWine(linha);
            }
        }catch(Exception e){
            System.out.println("erro!");
        }
        
        // pegando k centros aleatórios
        i = 0;
        Wine[] centros = new Wine[K];
        while(i < K){
            int indice = (int) (Math.random() * NUMERO_INSTANCIAS - 1) ;
            centros[i++] = instancias[indice];
        }
        GrupoManager grupos = new GrupoManager(K, centros);
        i = 0;
        int centro;
        
        while(i < LOOP_MAX) {
            int j = 0;
            while(j < NUMERO_INSTANCIAS) {
                Wine instanciaAtual = instancias[j];
                centro = grupos.seleciona(instanciaAtual);
                grupos.addInstancia(instanciaAtual,centro);
                j++;
            }
            
            for(j=0; j < grupos.k; j++) {
                Grupo  grupo = grupos.grupos[j];
                Wine pseudo = grupos.geraPseudoInstanciaMedia(grupo);
                centros[j] = grupos.instanciaMaisProxima(pseudo, grupo);
                grupo.setCentro(centros[j]);
            }
            
            i++;
            break;
            
        }
        System.out.println(grupos);
    }
    
}   
