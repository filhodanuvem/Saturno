<?php

class Wine 
{
    public $alcohol;
    public $malic_acid;
    public $ash;
    public $alcalinity_ash;  
    public $magnesium;
    public $total_phenols;
    public $flavanoids;
    public $nonflavanoid_phenols;
    public $proanthocyanins;
    public $color_intensity;
    public $hue;
    public $diluted_wines;
    public $proline;            
    
    /**
     * @param $center 
     * @return int representando a distancia de $this ate $center
     */
    public function distance_euclidian(Wine $center)
    {
        return rand(0,1000);
    }
}
