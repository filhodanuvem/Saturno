<?php
require_once 'Amostra.php';
require_once 'No.php';

// amostras instanciadas e num array
define('NUM_INSTANCIAS',14);
$amostras = array();

//  1
$amostra = new Amostra('manha',false,'quente','alta','nao'); $amostras[] = $amostra; 
$amostra = new Amostra('manha',true,'quente','alta','nao'); $amostras[] = $amostra;
$amostra = new Amostra('tarde',false,'quente','alta','sim'); $amostras[] = $amostra;
$amostra = new Amostra('noite',false,'moderado','alta','sim'); $amostras[] = $amostra;
$amostra = new Amostra('noite',false,'frio','normal','sim'); $amostras[] = $amostra;
$amostra = new Amostra('noite',false,'frio','normal','nao'); $amostras[] = $amostra;
$amostra = new Amostra('tarde',true,'frio','normal','sim'); $amostras[] = $amostra;
$amostra = new Amostra('manha',true,'moderado','alta','nao'); $amostras[] = $amostra;
$amostra = new Amostra('manha',false,'frio','normal','sim'); $amostras[] = $amostra;
$amostra = new Amostra('noite',false,'moderado','normal','sim'); $amostras[] = $amostra;
$amostra = new Amostra('manha',false,'moderado','normal','sim'); $amostras[] = $amostra;
$amostra = new Amostra('tarde',true,'moderado','alta','sim'); $amostras[] = $amostra;
$amostra = new Amostra('tarde',false,'quente','normal','sim'); $amostras[] = $amostra;
$amostra = new Amostra('noite',true,'moderado','alta','nao'); $amostras[] = $amostra;

$atributos = array();
foreach($amostra as $atributo => $valor){
    $atributos[$atributo] = $atributo;
}
unset($atributos['classe']);
