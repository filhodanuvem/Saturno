<?php

/* SaturnoDataTablesBundle:examples:simple.html.twig */
class __TwigTemplate_58855f1e8453db89681638976194a8ed extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        $this->parent = $this->env->loadTemplate("SaturnoDataTablesBundle:examples:index.html.twig");

        $this->blocks = array(
            'content' => array($this, 'block_content'),
        );
    }

    protected function doGetParent(array $context)
    {
        return "SaturnoDataTablesBundle:examples:index.html.twig";
    }

    protected function doDisplay(array $context, array $blocks = array())
    {
        $this->parent->display($context, array_merge($this->blocks, $blocks));
    }

    // line 3
    public function block_content($context, array $blocks = array())
    {
        // line 4
        echo $this->env->getExtension('table_render')->table_render((isset($context["table"]) ? $context["table"] : $this->getContext($context, "table")));
        echo "

";
        // line 6
        echo $this->env->getExtension('table_render')->table_render_js((isset($context["table"]) ? $context["table"] : $this->getContext($context, "table")));
        echo "

";
    }

    public function getTemplateName()
    {
        return "SaturnoDataTablesBundle:examples:simple.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  36 => 6,  31 => 4,  28 => 3,);
    }
}
