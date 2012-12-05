
package br.cloud.linearPrograming.simplex;

/**
 *
 * @author Claudson Oliveira
 */
public class ProblemaPL {
    protected int h;
    protected int w;
    protected int[][] tabela;
    
    public ProblemaPL(int h, int w) {
        this.h = h;
        this.w = w;
    }
    
    public void setTabela(int[][] tabela){
        this.tabela = tabela;
    }
    
    
    
}
