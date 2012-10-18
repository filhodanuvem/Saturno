package kmeansjava;

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
                System.out.println(instancias[i - 1]);
            }
        }catch(Exception e){
            System.out.println("erro!");
        }
        
        // pegando k centros aleatórios
        i = 0;
        Wine[] centros = new Wine[K];
        while(i < K){
            int indice = (int) (Math.random() * NUMERO_INSTANCIAS - 1) ;
            centros[i] = instancias[indice];
        }
        
        // 
        i = 0;
        // @todo criar uma classe Grupo com vários hashmap
        // 
        Wine[][] grupos = new Wine[K][(int)NUMERO_INSTANCIAS / K];
        while(i < LOOP_MAX){
            int j = 0;
            while(j < NUMERO_INSTANCIAS) {
                int centro = WineFactory.descobreCentro(instancias[j], centros);
                // 
                //grupos[centro][] = instancias[j];
            }
            
        }
        
    }
    
}   
