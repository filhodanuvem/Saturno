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
    public function testConvertIdentifierToTableName($bundleName, $bundleNamespace, $identifier, $namespace)
    {

        $template = $this->getMock('\Twig_Environment');
        $kernel = $this->getMockBuilder('Symfony\Component\HttpKernel\Kernel', array('getBundles'))
                       ->setConstructorArgs(array(
                            'dev', true
                        ))
                        ->getMock();
        $kernel->expects($this->once())
               ->method('getBundles')
               ->will($this->returnValue(array(
                    $bundleName => $bundleNamespace
                )));

        $factory = new \Saturno\DataTablesBundle\Manager\TableFactory($template, $kernel);
        $reflection = new \ReflectionClass($factory);
        $method = $reflection->getMethod('getTableClassName');
        $method->setAccessible(true);

        $this->assertEquals($namespace, $method->invoke($factory, $identifier));
    }

    public function providerIdentifiersAndTableNames()
    {
        return array(
            array('AcmeFooBundle', 'Acme\FooBundle\AcmeFooBundle', 'AcmeFooBundle:Bar','Acme\FooBundle\Table\BarTable'),
            array('SaturnoAcmeFooBundle', 'Saturno\Acme\FooBundle\SaturnoAcmeFooBundle', 'SaturnoAcmeFooBundle:Bar','Saturno\Acme\FooBundle\Table\BarTable'),
            array('FooBarBazBrazilBundle', 'Foo\Bar\Baz\BrazilBundle\FooBarBazBrazilBundle', 'FooBarBazBrazilBundle:Cloud','Foo\Bar\Baz\BrazilBundle\Table\CloudTable'),
        );
    }
}
