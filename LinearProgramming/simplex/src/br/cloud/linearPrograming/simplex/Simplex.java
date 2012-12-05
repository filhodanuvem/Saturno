/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package br.cloud.linearPrograming.simplex;

/**
 *
 * @author Claudson Oliveira
 */
public class Simplex {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        String arquivo = "in1";
        try{
            Leitor leitor = new Leitor(arquivo);
            String linha = leitor.getLinha();
            String[] dimensao = linha.split(",");
            int h = Integer.getInteger(dimensao[0]);
            int w = Integer.getInteger(dimensao[1]);
            
            int[][] tabela = leitor.getTabela();
            ProblemaPL problema = new ProblemaPL(h, w);
            problema.setTabela(tabela);
            
            
        }catch(Exception e){
            System.out.println(e.getMessage());
        }
        
        
    }
}
