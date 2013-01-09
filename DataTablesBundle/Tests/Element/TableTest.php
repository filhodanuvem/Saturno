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

use Saturno\DataTablesBundle\Element\Column;

class TableTest extends \PHPUnit_Framework_testCase
{

    public function testGetTableName()
    {
        $template = $this->getMock('\Twig_Environment');
        $table = new \Saturno\DataTablesBundle\Tests\Fixtures\UserTable($template);
        $reflect = new \ReflectionClass($table);
        $method = $reflect->getMethod('getName');
        $method->setAccessible(true);

        $expected = 'User';

        $this->assertEquals($expected, $method->invoke($table));
    }


    public function testLabelsOfTable()
    {
        $template = $this->getMock('\Twig_Environment');
        $table = new \Saturno\DataTablesBundle\Tests\Fixtures\UserTable($template);
        $columns = array_values($table->getColumns());
        $column = $columns[0];

        $expected = 'Code';

        $this->assertEquals($expected, $column->getLabel());

    }

    public function testLabelsOfTableWithToString()
    {
        $template = $this->getMock('\Twig_Environment');
        $table = new \Saturno\DataTablesBundle\Tests\Fixtures\UserTable($template);
        $columns = array_values($table->getColumns());
        $column = $columns[0];

        $expected = 'Code';

        $this->assertEquals($expected, $column);

    }

    /**
     * @dataProvider providerCorrectAddColumns
     */
    public function testIfAddColumnInsertDataIntoColumnsArray($property, $label, $config, $expected)
    {
        $table = $this->getTable();
        $table->addColumn($property, $label, $config);
        $this->assertEquals($expected, $table->getColumns(), 'GetColumns is failed');
    }

    /**
     * @dataProvider indexColumns
     * @param $index
     * @param $expected
     */
    public function testIndexesAsNamesInColumns($index, $expected)
    {
        $template  = $this->getMockForAbstractClass('\Twig_Environment');
        $table = new \Saturno\DataTablesBundle\Tests\Fixtures\UserTable($template);

        $this->assertEquals($expected, $table->getColumnName($index));

    }

    public function testIfSetBodyReturnsCorrectContent()
    {
        $user1 = new \Saturno\DataTablesBundle\Tests\Fixtures\User(1,'Joseph','2013-05-23');
        $user2 = new \Saturno\DataTablesBundle\Tests\Fixtures\User(2,'Hellena','1988-06-27');

        $expected = array(
            array(1,'Joseph','2013-05-23'),
            array(2,'Hellena','1988-06-27')
        );

        $template  = $this->getMockForAbstractClass('\Twig_Environment');
        $table = new \Saturno\DataTablesBundle\Tests\Fixtures\UserTable($template);
        $table->setBody(array(
            $user1,
            $user2,
        ));

        $this->assertEquals($expected, $table->getBody());
    }

    // @todo to test columns extras that does linked to entities

    // providers
    public function providerCorrectAddColumns()
    {

        return array(
            array('foo','Bar',array(), array('foo' => new Column('foo','Bar'))),
            array('Claudson','Cloudson', array('anything' => new \stdClass), array('Claudson'=>new Column('Claudson','Cloudson',array('anything' => new \stdClass))))
        );
    }

    public function indexColumns()
    {
        return array(
            array('0','id'),
            array(2,'date'),
        );
    }

    // getting mock
    public function getTable()
    {
        $template  = $this->getMockForAbstractClass('\Twig_Environment');
        /* @var $table \Saturno\DataTablesBundle\Element\Table */
        $table = $this->getMockBuilder('Saturno\DataTablesBundle\Element\Table')
             ->setConstructorArgs( array($template))
             ->getMockForAbstractClass();

        return $table;
    }
}
