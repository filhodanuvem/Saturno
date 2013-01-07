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

namespace Saturno\DataTablesBundle\Tests;

class TableFactoryTest extends \PHPUnit_Framework_TestCase
{
    /**
     * @dataProvider providerIdentifiersAndTableNames
     * @param string $identifier
     * @param string $namespace
     */
    public function testConvertIdentifierToTableName($identifier, $namespace)
    {
        $template = $this->getMock('\Twig_Environment');
        $factory = new \Saturno\DataTablesBundle\Manager\TableFactory($template);
        $reflection = new \ReflectionClass($factory);
        $method = $reflection->getMethod('convertToClassName');

        $this->assertEquals($namespace, $method->invoke($factory, $identifier));
    }

    public function providerIdentifiersAndTableNames()
    {
        return array(
            array('AcmeFooBundle:Bar','Acme\FooBundle\Table\BarTable'),
            array('SaturnoAcmeFooBundle:Bar','Saturno\Acme\FooBundle\Table\BarTable'),
        );
    }
}
