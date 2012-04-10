<?php

// rodando

require_once 'amostras.php';

// algoritmo principal 
/**
 * @param $amostras a serem usadas
 * @atributos $atributos de cada amostra 
 */

global $debug;
$debug = in_array('--debug',$argv);
function main($amostras, $atributos)
{
    global $i;
 //   echo $i++."\n";
   
   $no = new No();
   $classe = mesma_classe($amostras);
   if($classe !== false){
       $no->classe = $classe;
       return $no;
   }
   
   if(!$atributos){
       $no->classe = classe_mais_comum($amostras);
       return $no;
   }
   
   $atributo_teste = seleciona_atributo($amostras,$atributos,$no);
   $no->classe = $atributo_teste;
   $valores_possiveis = possiveis_valores($amostras,$atributo_teste);
   foreach($valores_possiveis as $valor){
       $no->filhos[$valor] = new No;
       $sub = subconjunto($amostras,$atributo_teste,$valor);
       if(!$sub){
           $no->filhos[$valor]->classe = classe_mais_comum($amostras);
       }else{
           unset($atributos[$atributo_teste]);
           $no->filhos[$valor] = main($amostras,$atributos);
           //break;
       }
   }
   return $no;
}

function seleciona_atributo(Array $amostras,Array $atributos,No $no)
{
    $ganho_maximo   = -3000;
    $atributo_teste = null;
    foreach($atributos as $atributo){        
        $ganho = ganho($atributo,$amostras); 
        if($ganho > $ganho_maximo){
            $ganho_maximo   = $ganho;
            $atributo_teste = $atributo; 
        }
    }
    $no->ganho = round($ganho_maximo,3);
    global $debug;
    if($debug)
        echo "Atributo de teste: {$atributo_teste}\n";
    return $atributo_teste;
}

function ganho($atributo,Array $amostras)
{
    return round(informacao($amostras) - entropia($amostras,$atributo),3);
}
 
function informacao(Array $amostras)
{
    $opcoes = array();
    foreach($amostras as $amostra){
        if(!isset($opcoes[$amostra->classe])){
            $opcoes[$amostra->classe] = 0 ;
        }
        $opcoes[$amostra->classe]++;
    }
    
    $total_amostras = count($amostras);
    $informacao = 0;
    foreach($opcoes as $atributo => $numero_amostras){
       $pi = $numero_amostras/$total_amostras;
       $informacao += ($pi * round(log($pi,2),3));
    }
    global $debug;
    if($debug)
        echo "informacao: {$informacao}\n";
    return (-1)*round($informacao,3);
}

function entropia(Array $amostras,$atributo)
{
    $possiveis_valores = possiveis_valores($amostras,$atributo);
    $entropia = 0;
    foreach($possiveis_valores as $valor){
        $sub = subconjunto($amostras,$atributo,$valor);
        $classes_possiveis = possiveis_valores($amostras,'classe');
        $sij = 0;
        foreach($classes_possiveis as $classe){
            $sij += count(subconjunto($sub,'classe',$classe));
        }
        $informacao = informacao($sub,$atributo);
        $entropia  += (round(($sij/NUM_INSTANCIAS),3)*$informacao);
    }
    global $debug;
    if($debug)
        echo "entropia: {$entropia} \n";
    return round($entropia,3);
}


function mesma_classe(Array $amostras)
{
    $classe = null;
    foreach($amostras as $amostra){
        if(!is_null($classe) && $amostra->classe != $classe )
           return false;
        
        $classe = $amostra->classe;
    }
    return $classe;
}

function classe_mais_comum($amostras){
    $opcoes = array();
    foreach($amostras as $amostra){
        if(!isset($opcoes[$amostra->classe])){
            $opcoes[$amostra->classe] = 0 ;
        }
        $opcoes[$amostra->classe]++;
    }
    
    $maior = 0 ;
    $classe_mais_comum = null;
    foreach($opcoes as $classe => $valor){
        if($valor > $maior){
            $maior  = $valor;
            $classe_mais_comum = $classe;
        }
    }
    return $classe_mais_comum;
}

function subconjunto(Array $amostras,$atributo,$valor)
{
    $sub = array();
    foreach($amostras as $amostra){
        if($amostra->$atributo == $valor){
            $sub[] = $amostra;
        }
    }
    return $sub;
    
}

function possiveis_valores(Array $amostras,$atributo)
{
    $possiveis_valores = array();
    foreach($amostras as $amostra){
        if(isset($possiveis_valores[$amostra->$atributo])){
           continue; 
        }
        $possiveis_valores[$amostra->$atributo] = $amostra->$atributo;
    }
    return $possiveis_valores;
}
if(!isset($test)){
//rodando
$arvoreid3 = main($amostras,$atributos);
$print = var_export($arvoreid3,true); 
$fp = fopen('debug.cloud','w+');
fwrite($fp,$print);
fclose($fp);
//echo $arvoreid3;
//print_r($arvoreid3);
//var_dump($arvoreid3);
}
