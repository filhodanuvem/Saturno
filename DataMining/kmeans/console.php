<?php
/**
 * @author Claudson Oliveira 17/09/2012
 * 
 * 
 */

require 'functions.php';
require 'Wine.class.php';

// lendo os parametros do console 
$method_distance = array_key_exists(1,$argv)?$argv[1]:'euclidian';
$k = array_key_exists(2,$argv)?$argv[2]:3;


// lendo o arquivo e criando as instâncias da classe Wine 
/* @var $instances Array contém todas as instâncas Wine */ 
$instances = array();
$fp = fopen(__DIR__.'/Wine.txt','r');
while($line = fgets($fp)){
    $instance = new Wine;
    $data     = explode("\t",$line);
    $i = 0;
    $instance_array = get_object_vars($instance);
    foreach($instance_array as $attr => $value){
        $instance->$attr = $data[$i++];
    }
    
    $instances[] = $instance;
}

// seleciono os centros (instancias aleatorias)
$i = 0;
$centers = array();
while($i < $k){
    $key_aleatory =  rand(0,count($instances)); 
    $centers[$i++]    =  $instances[$key_aleatory];
}

// agrupo cada instancia em seu centro mais proximo (meio kdd, isso, não?)
$groups = doGroup($instances,$centers);
printGroups($groups,$centers);

fclose($fp);

