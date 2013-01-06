<?php
/**
 *
 * @package Saturno::DataTables
 * @author Claudson Oliveira <claudsonweb@gmail.com>
 * @since 1.0
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
namespace Saturno\DataTablesBundle\Element;

use Symfony\Bundle\TwigBundle\Debug\TimedTwigEngine;

/**
 * Classes that extends this represents some dataTable and can print
 * a template with that entity
 */
abstract class Table
{
    private $_templateEngine;

    protected $_template;

    protected $_columns;

    public abstract function configure();

    public function __construct(\Twig_TemplateInterface $template)
    {
        $this->_templateEngine = $template;
        $this->_columns  = array();
        $this->configure();
    }

    /**
     * @param string $property access until some property
     * @param string $label title the column in template
     * @param Array $settings extras
     * @return Table
     */
    public function addColumn($property, $label, Array $settings = array())
    {
        $column = new Column($property, $label, $settings);
        $this->_columns[$property] = $column;

        return $this;
    }

    /**
     * @return array
     */
    public function getColumns()
    {
        return array_map(function($column){
            return $column->getLabel();
        }, $this->_columns);
    }

    /**
     * @param string $template
     */
    public function setTemplate($template)
    {
        if (!is_string($template)) {
            throw new \InvalidArgumentException('Expected a template string name');
        }
        $this->_template = $template;
    }

    /**
     * @param int $index
     * @return string
     * @throws \OutOfBoundsException
     * @throws \InvalidArgumentException
     */
    public function getColumnName($index)
    {
        if (!is_numeric($index)) {
            throw new \InvalidArgumentException('Expected a valid index');
        }

        if ($index >= count($this->_columns)) {
            $total = count($this->_columns);
            throw new \OutOfBoundsException("Trying access column {$index} of {$total} ");
        }
        $values = array_values($this->_columns);

        return $values[$index]->getName();
    }
}
