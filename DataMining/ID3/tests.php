<?php

require 'index.php';
global $a;
$a = $amostras;

class Tests extends PHPUnit_Framework_TestCase
{
   /**
   * @dataProvider providerInformacao
   */ 
   public function test_informacao($input)
   {
       $this->assertEquals(1,informacao($input,'horario'));
   } 


   public function providerInformacao()
   {
      global $a;
      return array(
        array(subconjunto($a,'horario','manha'))
      );
   } 

}
