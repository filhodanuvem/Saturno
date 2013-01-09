<?php
/**
 *
 * @author Claudson Oliveira <claudsonweb@gmail.com> 1/3/13
 */

namespace Saturno\DataTablesBundle\Manager;

class TableFactory
{
    protected  $templateEngine;

    protected $kernel;

    public function __construct(\Twig_Environment $template,\Symfony\Component\HttpKernel\Kernel $kernel)
    {
        $this->templateEngine = $template;
        $this->kernel = $kernel;
    }

    public function getTable($table)
    {
        $tableClass = $this->getTableClassName($table);

        return new $tableClass($this->templateEngine);
    }


    private function getTableClassName($identifier)
    {
        if (strstr($identifier, ':') === false) {
            throw new \UnexpectedValueException('Identifiers needs to be the form PathToBundle:NameWithoutTable');
        }

        list($bundle,$table) = explode(':',$identifier);
        $table .= 'Table';

        $bundles = $this->kernel->getBundles();
        if (!array_key_exists($bundle, $bundles)) {
            throw new \UnexpectedValueException("Bundle {$bundle} does not exist");
        }

        $selectedBundle =  $bundles[$bundle];
        $selectedBundle =  mb_substr(get_class($selectedBundle),0, strrpos(get_class($selectedBundle), '\\'));

        return $selectedBundle.'\\Table\\'.$table;

    }
}
