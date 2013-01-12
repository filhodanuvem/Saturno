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

use Symfony\Component\HttpFoundation\Request;

interface GridRequest
{
    function format(Request $request);
}
