<?php

namespace Gandalf\Entity;

Trait Caller 
{
	protected $methods = array();
	public function addMethod($methodPatern, $function)
	{
		$this->methods[$methodPatern] = new Calle($function);
	}

	public function __set($name, $function)
	{
		$this->addMethod($name, $function);
	}

	public function __call($name, $params)
	{
		$calle = $this->getCalleByPattern($name);
		
		if (!$calle) {
			throw new \BadMethodCallException("Method {$name} not exists");
		}
		
		return $calle($params);
	}

	protected function getCalleByPattern($name)
	{
		if (array_key_exists($name, $this->methods)) {
			return $this->methods[$name];
		}

		foreach ($this->methods as $pattern => $calle) {
			if (preg_match("/^$pattern$/", $name)) {
				return $calle;
			}
		}

		return null;
	}
}