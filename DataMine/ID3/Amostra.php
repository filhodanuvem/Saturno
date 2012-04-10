<?php

Class Amostra
{
    public $horario;
    public $isca;
    public $tempo;
    public $profundidade;
    public $classe;

    public function __construct($horario,$isca,$tempo,$prof,$class)
    {
        $this->horario = $horario;
        $this->isca    = $isca;
        $this->tempo   = $tempo;
        $this->profundidade = $prof;
        $this->classe  = $class;     
    }
    
    
}    
