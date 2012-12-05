<?php

include 'TraitRepository.php';

class UserRepository
{
    use Cloudson\Traits\Repository\TraitRepository; 
    
    public function getSql()
    {
        $sql = 'SELET * FROM User Where sobrenome = "oliveira" ';
        $this->createLike($sql);
        $this->createOrderBy($sql);
        
        return $sql;
    }
}
