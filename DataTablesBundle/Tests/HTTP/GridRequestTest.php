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
            'orderDir' => 'desc',
        );

        $template  = $this->getMockForAbstractClass('\Twig_Environment');
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
        $GET = array(
            'iSortCol_0' => 1,
            'sSearch'    => 'foo',
        );

        $expected = $expected = array(
            'limit' => 10,
            'offset' => 0,
            'like' => 'foo',
            'search' => null,
            'orderBy' => 'name',
            'orderDir' => 'desc',
        );
        $request = new \Symfony\Component\HttpFoundation\Request($GET);

        $template  = $this->getMockForAbstractClass('\Twig_Environment');
        $table = new \Saturno\DataTablesBundle\Tests\Fixtures\UserTable($template);

        $gridRequest = new \Saturno\DataTablesBundle\HTTP\GridRequest($table);
        $gridRequest->format($request);

        $this->assertEquals($expected, $gridRequest->all());

    }

    /**
     * @dataProvider convertionsGET
     * @param $GET
     * @param $expected
     */
    public function testConvertKeys($GET,$expected,$value)
    {

        $request = new \Symfony\Component\HttpFoundation\Request(array($GET => $value));

        $template  = $this->getMockForAbstractClass('\Twig_Environment');
        $table = new \Saturno\DataTablesBundle\Tests\Fixtures\UserTable($template);

        $gridRequest = new \Saturno\DataTablesBundle\HTTP\GridRequest($table);
        $reflectionClass = new \ReflectionClass($gridRequest);
        $method = $reflectionClass->getMethod('converter');
        $method->setAccessible(true);

        $this->assertEquals(array($expected, $value), $method->invoke($gridRequest, $GET, $value));

    }

    public function convertionsGET()
    {
        return array(
            array('iDisplayLength','limit',20),
            array('sSearch','like','foo'),
            array('iDisplayStart','offset',4),
            array('sSortDir_0','orderDir',4),
        );
    }

    /**
     * @expectedException \OutOfBoundsException
     */
    public function testIfCatchExceptionAccessingUnknowColumn()
    {
        $GET = array(
            'iSortCol_0' => 100,
            'sSearch'    => 'foo',
        );

        $request = new \Symfony\Component\HttpFoundation\Request($GET);

        $template  = $this->getMockForAbstractClass('\Twig_Environment');
        $table = new \Saturno\DataTablesBundle\Tests\Fixtures\UserTable($template);

        $gridRequest = new \Saturno\DataTablesBundle\HTTP\GridRequest($table);
        $gridRequest->format($request);
    }

    /**
     * @expectedException \InvalidArgumentException
     */
    public function testIfCatchExceptionAccessingColumnNotNumeric()
    {
        $GET = array(
            'iSortCol_0' => 'foo',
        );

        $request = new \Symfony\Component\HttpFoundation\Request($GET);

        $template  = $this->getMockForAbstractClass('\Twig_Environment');
        $table = new \Saturno\DataTablesBundle\Tests\Fixtures\UserTable($template);

        $gridRequest = new \Saturno\DataTablesBundle\HTTP\GridRequest($table);
        $gridRequest->format($request);
    }

    private function getMethodFormatAsPublic()
    {
        $reflectionClass = new \ReflectionClass('\Saturno\DataTablesBundle\HTTP\GridRequest');
        $method = $reflectionClass->getMethod('format');
        $method->setAccessible(true);

        return $method;
    }
}
