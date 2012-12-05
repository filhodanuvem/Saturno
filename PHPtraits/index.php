<?php

    include 'UserRepository.php';
    
    $repo = new UserRepository;
    echo $repo->getSql();
