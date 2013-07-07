<?php

namespace Gandalf\Entity;

Class Calle
{
	protected $function; 

	public $matches = array();

	public function __construct($function)
	{
		if ($function instanceof \Closure) {
			$function = $function->bindTo($this);
		}
		$this->function = $function;
	}

	public function __invoke($params)
	{
		return call_user_func_array($this->function, $params);
	}

	public function __get($name)
	{
		if (preg_match('/_d+/', $name) === false) {
			throw new \UnexpectedValueException("Atributte {$name} dont exists");
		}
		
		$index = str_replace('_', '', $name);
		if (!array_key_exists($index, $this->matches)) {
			return null;
		}

		return $this->matches[$index];
	}

}