<?php

namespace Gandalf\Entity;

Class Calle
{
	protected $function; 

	public function __construct($function)
	{
		$this->function = $function;
	}

	public function __invoke($params)
	{
		return call_user_func_array($this->function, $params);
	}
}