<?php

class No
{
    public $filhos = array();
    public $classe;
    public $ganho = 0;
    public static $ident = 0;
    /*public function __toString()
    {
        self::$ident++;
        $this->identar();
        $string  = "\nNo\n ";
        $string .= "-> Classe: {$this->classe} \n ";
        $string .= "-> Ganho: {$this->ganho}   \n";
        $string .= "-> Filhos: [ ";
        foreach($this->filhos as $f){
            $string .= (string)$f;
        }
        $string .= "]\n";
        self::$ident--;
        return $string;
    }*/
    
    private function identar(){
        $tab = '';
        for($i=0;$i<=self::$ident;$i++);
            $tab .= " ";
        return $tab;
    }

}
