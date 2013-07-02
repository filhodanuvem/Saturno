<?php

namespace Gandalf\Tests\Entity;

use Gandalf\Tests\Fixtures\Foo;

class CallerTest extends \PHPUnit_Framework_TestCase
{
	/**
	 * @test
	 */
	public function should_create_method_with_simple_name()
	{
		$foo = new Foo;
		$foo->addMethod('bar', function(){
			return 'fooBar';
		});

		$this->assertEquals($foo->bar(), 'fooBar');
	}

	/**
	 * @test 
	 */ 
	public function should_create_method_with_intuive_way()
	{
		$foo = new Foo;
		$foo->bar = function () {
			return 'Sr. Bilbo';
		};

		$this->assertEquals($foo->bar(), 'Sr. Bilbo');
	}
	
	/**
	 * @test
	 */ 
	public function should_accept_any_callable()
	{
		$foo = new Foo;
		$foo->first_char_to_upper = 'ucfirst';
		$this->assertEquals($foo->first_char_to_upper('foo'), 'Foo');

		$foo->strip = 'trim';
		$this->assertEquals($foo->strip(' This is my name, Galdalf      '), 'This is my name, Galdalf');
	}

	/**
	 * @test
	 * @expectedException \BadMethodCallException
	 */ 
	public function test_if_emit_error_calling_method_not_found()
	{
		$foo = new Foo;
		$foo->bar = 'print';

		$foo->foo();
	}

	/**
	 * @test
	 */ 
	public function should_call_methods_with_simple_pattern_name()
	{
		$foo = new Foo;
		$foo->addMethod('findBy[A-Z][a-z]+', function($pivot){
			return 'found!';
		});

		$this->assertEquals($foo->findByName('Bilbo'), 'found!');
	}

	/**
	 * @test
	 */
	public function should_use_magic_vars()
	{
		$foo = new Foo;
		$foo->addMethod('findBy[A-Z][a-z]+', function($pivot) {
			return $_1;
		});

		$this->assertEquals($foo->findByName('Bilbo'), 'Name');
	}

	/**
	 * @todo this is complicated, we will think about how
	 * it could pass
	 */ 
	public function should_works_with_method_exists()
	{
		$foo = new Foo;
		$foo->bla = function(){
			echo 'ops!';
		};

		$this->assertTrue(method_exists($foo, 'bla'));
	}

}