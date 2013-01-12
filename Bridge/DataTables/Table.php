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

namespace Saturno\Bridge\DataTables;

interface Table
{

    public function createView();

    public function createJavascript();

    public function addColumn($property, $label, Array $settings = array());

    public function getColumns();

    public function setBody(Array $content);

    public function getBody();
}
