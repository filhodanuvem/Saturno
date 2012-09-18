<?php

require 'silex.phar';
require './vendor/twig/twig/lib/Twig/Autoloader.php';
Twig_Autoloader::register();
$t_loader = new Twig_Loader_Filesystem(__DIR__.'/tpl');
$twig = new Twig_Environment($t_loader);

$app = new Silex\Application();
$app['debug'] = true;
$app->get('/',function() use($twig){
    return $twig->render('home.html');
});

$app->get('/criar-modulo',function() use($twig){
    return $twig->render('criar_modulo.html');
});

$app->run();
