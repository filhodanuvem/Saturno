<?php

namespace Acme\Example\DataTablesBundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\Controller;
use Sensio\Bundle\FrameworkExtraBundle\Configuration\Route;
use Sensio\Bundle\FrameworkExtraBundle\Configuration\Template;

use Acme\Example\DataTablesBundle\Entity\User;

class DefaultController extends Controller
{
    /**
     * @Route("/")
     * @Template()
     */
    public function indexAction()
    {
        // Use factory service to get your DataTable
        $factory = $this->get('saturno_datatables_factory');
        $table = $factory->getTable('AcmeExampleDataTablesBundle:User');
        // create, get or search your entities
        $user1 = new User(1,'Joseph','2013-05-23');
        $user2 = new User(2,'Hellena','1988-06-27');
        // insert the entities into datatable
        $table->setBody(array(
            $user1,
            $user2
        ));

        // pass to table to the view, normally
        $vars = array(
            'table' => $table,
        );
        $html = $this->renderView('SaturnoDataTablesBundle:examples:simple.html.twig', $vars);

        $response = new \Symfony\Component\HttpFoundation\Response();
        $response->setContent($html);

        return $response;
    }
}
