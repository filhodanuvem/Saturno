package br.cloud.linearPrograming.simplex;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;

/**
 *
 * @author Claudson Oliveira
 */
public class Leitor {
    
    protected FileReader fileReader;
    protected BufferedReader buffer;
    public Leitor(String arquivo) throws FileNotFoundException {
        this.fileReader = new FileReader(arquivo);
        this.buffer = new BufferedReader(this.fileReader);   
    }
    
    public String getLinha() throws IOException{
        String linha = null;
        linha = this.buffer.readLine();
        return linha;
    }
    
    public void fechar()throws IOException
    {
        this.buffer.close();
        this.fileReader.close();
    }
    
    public int[][] getTabela(){
        int[][] tabela = null;
        
        return tabela;
    }
    
}
