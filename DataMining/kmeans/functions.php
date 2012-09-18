<?php

function doGroup($instances,$centers){
    $groups = array();
    foreach($instances as $instance){
        $min_distance = PHP_INT_MAX;
        $group_near = null; 
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
    
