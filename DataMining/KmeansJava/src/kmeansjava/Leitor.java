/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package kmeansjava;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

/**
 *
 * @author cloud
 */
public class Leitor 
{
    protected FileReader reader;
    protected BufferedReader buffer;

    public Leitor(String baseDeDados) {
        try{
            this.reader = new FileReader(baseDeDados);
            this.buffer = new BufferedReader(reader);
        }catch(Exception e){
            
        }
    }
    
    public String getLinha() throws IOException
    {
        String linha = null;
        linha = this.buffer.readLine();
        return linha;
    }
    
    public void fechar()throws IOException
    {
        this.buffer.close();
        this.reader.close();
    }
    
}
