<?php
/**
 *  @package Saturno::DataTables
 *  @author  Claudson Oliveira <claudsonweb@gmail.com>
 *  @since   1.0
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Saturno\DataTablesBundle\Tests\HTTP;

class GridRequestTest extends  \PHPUnit_Framework_TestCase
{

    /**
     * @param $GET
     * @param $expected
     */
    public function testIfGridRequestWillformatSimpleGET()
    {
        // dados iniciais
        $GET = array(
            'iDisplayLength' => 20,
            'iDisplayStart' => 5,
        );

        $expected = array(
            'limit' => 20,
            'offset' => 5,
            'like' => null,
            'search' => null,
            'orderBy' => null,
        );

        $template  = $this->getMockForAbstractClass('\Twig_TemplateInterface');
        $table = $this->getMockBuilder('\Saturno\DataTablesBundle\Element\Table')
            ->setConstructorArgs( array($template))
            ->getMockForAbstractClass();

        $request = new \Symfony\Component\HttpFoundation\Request($GET);

        $gridRequest = new \Saturno\DataTablesBundle\HTTP\GridRequest($table);
        $formatMethod = $this->getMethodFormatAsPublic();
        $formatMethod->invoke($gridRequest, $request);

        // test
        $this->assertEquals($expected, $gridRequest->all());
    }

    public function testIfGridRequestWillFormatColumnsName()
    {


    }

    private function getMethodFormatAsPublic()
    {
        $reflectionClass = new \ReflectionClass('\Saturno\DataTablesBundle\HTTP\GridRequest');
        $method = $reflectionClass->getMethod('format');
        $method->setAccessible(true);

        return $method;
    }
}
