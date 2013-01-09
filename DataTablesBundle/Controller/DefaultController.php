<?php

namespace Saturno\DataTablesBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use Sensio\Bundle\FrameworkExtraBundle\Configuration\Route;
use Sensio\Bundle\FrameworkExtraBundle\Configuration\Template;

use Saturno\DataTablesBundle\Tests\Fixtures\Product;
use Saturno\DataTablesBundle\Tests\Fixtures\User;

class DefaultController extends Controller
{
    /**
     * @Route("/")
     * @Template()
     */
    public function indexAction()
    {
        var_dump(get_class($this->get('kernel')));
        $table = new \Saturno\DataTablesBundle\Tests\Fixtures\UserTable($this->get('twig'));
        $user1 = new \Saturno\DataTablesBundle\Tests\Fixtures\User(1,'Joseph','2013-05-23');
        $user2 = new \Saturno\DataTablesBundle\Tests\Fixtures\User(2,'Hellena','1988-06-27');

        $table->setBody(array(
            $user1,
            $user2
        ));


        $vars = array(
            'table' => $table,
        );
        $html = $this->renderView('SaturnoDataTablesBundle:examples:simple.html.twig', $vars);

        $response = new \Symfony\Component\HttpFoundation\Response();
        $response->setContent($html);

        return $response;
    }

    /**
     * @route("/compound")
     * @return \Symfony\Component\HttpFoundation\Response
     */
    public function compoundAction()
    {
        $table = new \Saturno\DataTablesBundle\Tests\Fixtures\ProductTable($this->get('twig'));

        $user1 = new \Saturno\DataTablesBundle\Tests\Fixtures\User(1,'Joseph','2013-05-23');
        $user2 = new \Saturno\DataTablesBundle\Tests\Fixtures\User(2,'Hellena','1988-06-27');
        $product1 = new Product(1, 'xbox', $user1);
        $product2 = new Product(2, 'barbie', $user2);
        $product3 = new Product(3, 'dell', $user1);
        $table->setBody(array(
            $product1, $product2, $product3
        ));


        $vars = array(
            'table' => $table,
        );
        $html = $this->renderView('SaturnoDataTablesBundle:examples:simple.html.twig', $vars);

        $response = new \Symfony\Component\HttpFoundation\Response();
        $response->setContent($html);

        return $response;
    }
}
