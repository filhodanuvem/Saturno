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

		$output_matches = array();
		foreach ($this->methods as $pattern => $calle) {
			if (preg_match("/^$pattern$/", $name, $output_matches)) {
				$calle->matches = $output_matches;
				//$calle = $this->setExpressionsVars($calle, $output_matches);
				return $calle;
			}
		}

		return null;
	}

	// protected function setExpressionsVars(Calle $calle, Array $output_matches)
	// {
	// 	if (count($output_matches) > 1) {
	// 		array_shift($output_matches);
	// 		// exists groups expressions
	// 		foreach ($output_matches as $key => $match) {
	// 			$index = $key + 1;
	// 			$varName = "_{$index}";
	// 			$calle->$varName = $match[0];
	// 			//$calle->addParameter($index, $match);
	// 		}
	// 	}
	// 	return $calle;
	// }
}