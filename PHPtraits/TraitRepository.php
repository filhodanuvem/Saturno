<?php

namespace Cloudson\Traits\Repository;

trait TraitRepository
{
    protected function createOrderBy(&$sql)
    {
        $sql .= ' ORDER BY id ASC ';
    }
    
    protected function createLike(&$sql)
    {
        if (stripos($sql, 'where') === false) {
            $sql .= ' WHERE 1 = 1 ';
        }
        $sql .= ' AND nome = "Cloudson" ';
    }
    
}
