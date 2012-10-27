package br.cloud.dataming.kmeansjava;

/**
 *
 * @author Claudson Oliveira
 */
public class Wine 
{
    public double alcohol;
    public double malic_acid;
    public double ash;
    public double alcalinity_ash;  
    public double magnesium;
    public double total_phenols;
    public double flavanoids;
    public double nonflavanoid_phenols;
    public double proanthocyanins;
    public double color_intensity;
    public double hue;
    public double diluted_wines;
    public double proline;
    
    public int real_class;
    
    public double distance_euclidian(Wine center)
    {
        double distance = 0;
        
        distance =  Math.pow(center.alcalinity_ash - this.alcalinity_ash,2);
        distance += Math.pow(center.alcohol - this.alcohol,2);
        distance += Math.pow(center.ash - this.ash,2);
        distance += Math.pow(center.color_intensity - this.color_intensity,2);
        distance += Math.pow(center.diluted_wines - this.diluted_wines,2);
        distance += Math.pow(center.flavanoids - this.flavanoids,2);
        distance += Math.pow(center.hue - this.hue,2);
        distance += Math.pow(center.magnesium - this.magnesium,2);
        distance += Math.pow(center.malic_acid - this.malic_acid,2);
        distance += Math.pow(center.nonflavanoid_phenols - this.nonflavanoid_phenols,2);
        distance += Math.pow(center.proline - this.proline,2);
        distance += Math.pow(center.total_phenols - this.total_phenols,2);
        distance += Math.pow(center.proanthocyanins - this.proanthocyanins,2);
        
        return Math.sqrt(distance);
    }
    
    public void set(int i,double valor)
    {
        
        switch(i){
            case 0:
                this.alcalinity_ash = valor;
                break;
                
            case 1:
                this.alcohol = valor;
                break;
            
            case 2:
                this.ash = valor;
                break;

            case 3:
                this.color_intensity = valor;
                break;

            case 4:
                this.diluted_wines = valor;
                break;

            case 5:
                this.flavanoids = valor;
                break;

            case 6:
                this.hue = valor;
                break;

            case 7:
                this.magnesium = valor;
                break;

            case 8:
                this.malic_acid = valor;
                break;

            case 9:
                this.nonflavanoid_phenols = valor;
                break;

            case 10:
                this.proline = valor;
                break;

            case 11:
                this.total_phenols = valor;
                break;
                
            case 12:
                this.proanthocyanins = valor;
                break;
                
            case 13:
                this.real_class = (int)valor;
                break;
              
        }
    }
    
    public double get(int i)
    {
        
        switch(i){
            case 0:
                return this.alcalinity_ash;
                
            case 1:
                return this.alcohol;
                
            case 2:
                return this.ash;
                
            case 3:
                return this.color_intensity;
                
            case 4:
                return this.diluted_wines;
                
            case 5:
                return this.flavanoids;
                
            case 6:
                return this.hue;
                
            case 7:
                return this.magnesium;
                
            case 8:
                return this.malic_acid;

            case 9:
                return this.nonflavanoid_phenols;

            case 10:
                return this.proline;

            case 11:
                return this.total_phenols;
            
            case 12:
                return this.proanthocyanins;
                
            case 13:
                return this.real_class;
                
              
        }
        return 0;
    }

    @Override
    public String toString() {
        String texto = "[";
        for(int i=0; i<= 13; i++){
            texto += this.get(i)+", ";
        }
        texto += "]";
        return texto;
    }
    
    
}
