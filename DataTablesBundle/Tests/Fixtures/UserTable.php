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

namespace Saturno\DataTablesBundle\Tests\Fixtures;

Class UserTable extends \Saturno\DataTablesBundle\Element\Table
{
    public function configure()
    {
        $this->addColumn('id','Code')
            ->addColumn('name','Name' )
            ->addColumn('date','Birthday');
    }
}
