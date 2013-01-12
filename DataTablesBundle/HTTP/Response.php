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
namespace Saturno\DataTablesBundle\HTTP;

use Saturno\Bridge\DataTables\Table;

class Response extends \Saturno\Bridge\DataTables\GridResponse
{
    protected $dataGrid = array(
        'aaData' => array(),
        'iTotalDisplayRecords' => 0,
        'iTotalRecords' => PHP_INT_MAX,
        'sEcho' => 0,
    );

    public function __construct(Table $table, Array $data = array())
    {
        $this->dataGrid = array_merge($this->dataGrid, $data);
        parent::__construct($table, $this->dataGrid);
    }


    public function setEntities(Array $content)
    {
        $this->table->setBody($content);
        $this->updateDataGrid();
    }

    public function addEntity($entity)
    {
        $this->table->setBody(array($entity));
        $this->updateDataGrid();
    }

    public function getDataGrid()
    {
        return $this->dataGrid;
    }

    public function setTotal($total)
    {
        if (!is_numeric($total) || is_float($total)) {
            throw new \InvalidArgumentException("Trying set is not a valid value to total of entities on response");
        }

        if ($total < 0) {
            throw new \UnexpectedValueException(" total of entities on response can't be less then zero ");
        }

        $this->dataGrid['iTotalRecords'] = $total;
    }

    public function getTotal()
    {
        return $this->dataGrid['iTotalRecords'];
    }

    public function setShown($shown)
    {
        if (!is_numeric($shown) || is_float($shown)) {
            throw new \InvalidArgumentException("total shown is not a valid value to total of entities shown on response");
        }

        if ($shown > $this->getTotal() || $shown < 0) {
            throw new \UnexpectedValueException(" total of values shown  is greater then total");
        }

        $this->dataGrid['iTotalDisplayRecords'] = $shown;
    }

    public function getShown()
    {
        return $this->dataGrid['iTotalDisplayRecords'];
    }

    private function updateDataGrid()
    {
        $body = $this->table->getBody();
        $this->dataGrid['aaData'] = $body;
        $this->setData($this->dataGrid);
    }

}
