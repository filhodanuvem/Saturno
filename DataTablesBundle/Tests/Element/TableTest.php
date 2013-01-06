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

namespace Saturno\DataTablesBundle\Tests\Element;



class TableTest extends \PHPUnit_Framework_testCase
{

    /**
     * @dataProvider providerCorrectAddColumns
     */
    public function testIfAddColumnInsertDataIntoColumnsArray($property, $label, $config, $expected)
    {
        $table = $this->getTable();
        $table->addColumn($property, $label, $config);
        $this->assertSame($expected, $table->getColumns(), 'GetColumns is failed');
    }

    /**
     * @dataProvider indexColumns
     * @param $index
     * @param $expected
     */
    public function testIndexesAsNamesInColumns($index, $expected)
    {
        $template  = $this->getMockForAbstractClass('\Twig_TemplateInterface');
        $table = new UserTable($template);

        $this->assertEquals($expected, $table->getColumnName($index));

    }


    public function providerCorrectAddColumns()
    {
        return array(
            array('foo','Bar',array(),array('foo' => 'Bar')),
            array('Claudson','Cloudson', array('anything' => new \stdClass), array('Claudson' => 'Cloudson')),

        );
    }

    public function indexColumns()
    {
        return array(
            array('0','id'),
            array(2,'date'),
        );
    }

    public function getTable()
    {
        $template  = $this->getMockForAbstractClass('\Twig_TemplateInterface');
        /* @var $table \Saturno\DataTablesBundle\Element\Table */
        $table = $this->getMockBuilder('Saturno\DataTablesBundle\Element\Table')
             ->setConstructorArgs( array($template))
             ->getMockForAbstractClass();

        return $table;
    }
}


// example of table
Class UserTable extends \Saturno\DataTablesBundle\Element\Table
{
    public function configure()
    {
        $this->addColumn('id','Code')
              ->addColumn('name','Name' )
              ->addColumn('date','Birthday');
    }
}
