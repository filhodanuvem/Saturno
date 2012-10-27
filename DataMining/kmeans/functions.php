<?php

function doGroup(Array $instances,$centers){
    
    $groups = array();
    foreach($instances as $instance){
        $min_distance = PHP_INT_MAX;
        $group_near = null; 
        if(!$instance){
            var_dump($instances);
        }
        foreach($centers as $key_group => $center){
            $distance = $instance->distance_euclidian($center);
            if( $distance < $min_distance ){
                 $min_distance = $distance;
                 $group_near   = $key_group; 
             }
        }
        $groups[$group_near][] = $instance;
    }
    return $groups;
}
    
function mediaGroup(Array $group){
    $instanceMedia = new Wine; // instancia que contem todos os valores medios
    $attrs = get_object_vars($instanceMedia);
    $numberAttrs = count($attrs);
    foreach($group as $instance){
        foreach($attrs as $attr => $v){
            $instanceMedia->$attr += $instance->$attr;
        }
    }
    
    // agora buscamos qual instancia real, em group
    // que mais se assemelha a $instanceMedia
    $instanceBetters = array();
    foreach($attrs as $attr => $v){
        $near = PHP_INT_MAX;
        foreach($group as $index => $instance){
            if(abs($instanceMedia->$attr/$numberAttrs - $near) > abs($instance->$attr - $near)){
                $instanceBetters[$attr] = $instance; 
            }
        }
    }
    
    $countNears = array();
    foreach($instanceBetters as $attr => $instance){
        if(!array_key_exists(spl_object_hash($instance),$countNears)){
            $countNears[spl_object_hash($instance)] = array();
            $countNears[spl_object_hash($instance)]['counter'] = 0;
        }
        $countNears[spl_object_hash($instance)]['counter']++;
        $countNears[spl_object_hash($instance)]['object'] = $instance;
    }
    
    $stronger = 0;
    $return   = null;
    foreach($countNears as $data){
        if( $stronger < $data['counter'] ){
            
            $stronger = $data['counter'];
            $return   = $data['object'];
        }
    }
    return $return;
}

function printGroups(Array $groups,$centers = null){
    if($centers){
        foreach($centers as $index => $center){
            echo sprintf("Center %d => %s \n",$index,$center);
        }
        echo "\n\n";
    }
    foreach($groups as $index => $group){
        echo sprintf("Grupo %d (%d) \n",$index,count($group));
    }
}
