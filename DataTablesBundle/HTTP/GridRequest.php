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

use Symfony\Component\HttpFoundation\Request;
use Saturno\DataTablesBundle\Element\Table;

class GridRequest
{
    /**
     * @var Table $table origin of the request
     */
    protected $table;

    public $variables;

    const LIMIT_DEFAULT = 10;

    public function __construct(Table &$origin)
    {
        $this->table = $origin;
        $this->variables  = array(
            'limit' => self::LIMIT_DEFAULT,
            'orderBy' => null,
            'like' => null,
            'search' => null,
            'offset' => 0,
        );
    }

    private function format(Request $request)
    {
       $requestArray = array_merge($request->query->all(), $request->request->all());

       foreach ($requestArray as $key => $value) {
           list($newKey, $newValue) = $this->converter($key, $value);
           $this->variables[$newKey] = $newValue;
       }

    }

    private function converter($key, $value)
    {
        if ($key == 'iDisplayLength' && $value >= 0 ) {
           return array('limit', $value);
        }

        if ($key == 'iDisplayStart'  && $value >= 0 ) {
           return array('offset', $value);
        }

        if (array_key_exists('iSortCol_0', $request)) {
//            $campos = array_keys($colunas);
//            $requestFormatada['orderBy'] = $campos[$request['iSortCol_0']];
        }
    }

    public function all()
    {
        return $this->variables;
    }

}
