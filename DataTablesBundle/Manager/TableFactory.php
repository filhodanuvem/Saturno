<?php
/**
 *
 * @author Claudson Oliveira <claudsonweb@gmail.com> 1/3/13
 */

namespace Saturno\DataTablesBundle\Manager;

class TableFactory
{
    protected  $templateEngine;

    protected $em;

    public function __construct(\Twig_Environment $template, \Doctrine\ORM\EntityManager $em)
    {
        $this->templateEngine = $template;

        $this->em = $em;
    }

    public function getTable($table)
    {

    }


    private function convertToClassName($identifier)
    {
        if (strstr($identifier, ':') === false) {
            throw new \UnexpectedValueException('Identifiers needs to be the form PathToBundle:NameWithoutTable');
        }

        list($bundle,$table) = explode(':',$identifier);
        $table .= 'Table';

    }
}
