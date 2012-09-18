<?php
require_once 'Amostra.php';
require_once 'No.php';

// amostras instanciadas e num array
define('NUM_INSTANCIAS',14);
$amostras = array();

//  1
$amostra = new Amostra('noite',false,'bom','alta','ruim'); $amostras[] = $amostra; 
$amostra = new Amostra('manha',true,'chuvoso','baixa','boa'); $amostras[] = $amostra;
$amostra = new Amostra('tarde',true,'chuvoso','baixa','media'); $amostras[] = $amostra;
$amostra = new Amostra('manha',true,'nublado','baixa','boa'); $amostras[] = $amostra;
$amostra = new Amostra('noite',false,'nublado','baixa','media'); $amostras[] = $amostra;
$amostra = new Amostra('noite',false,'chuvoso','baixa','ruim'); $amostras[] = $amostra;
$amostra = new Amostra('tarde',false,'chuvoso','baixa','ruim'); $amostras[] = $amostra;
$amostra = new Amostra('manha',true,'bom','baixa','boa'); $amostras[] = $amostra;
$amostra = new Amostra('noite',false,'nublado','alta','media'); $amostras[] = $amostra;
$amostra = new Amostra('tarde',false,'nublado','alta','media'); $amostras[] = $amostra;
$amostra = new Amostra('tarde',false,'chuvoso','alta','ruim'); $amostras[] = $amostra;
$amostra = new Amostra('noite',false,'chuvoso','alta','ruim'); $amostras[] = $amostra;
$amostra = new Amostra('tarde',false,'nublado','baixa','media'); $amostras[] = $amostra;
$amostra = new Amostra('tarde',true,'nublado','baixa','media'); $amostras[] = $amostra;

$atributos = array();
foreach($amostra as $atributo => $valor){
    $atributos[$atributo] = $atributo;
}

unset($atributos['classe']);
