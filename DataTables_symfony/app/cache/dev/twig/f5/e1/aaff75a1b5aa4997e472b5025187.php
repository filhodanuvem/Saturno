<?php

/* SaturnoDataTablesBundle:Skeleton:javascript.html.twig */
class __TwigTemplate_f5e1aaff75a1b5aa4997e472b5025187 extends Twig_Template
{
    public function __construct(Twig_Environment $env)
    {
        parent::__construct($env);

        $this->parent = false;

        $this->blocks = array(
        );
    }

    protected function doDisplay(array $context, array $blocks = array())
    {
        // line 1
        echo "<script type='text/javascript'>
    var oTable";
        // line 2
        echo twig_escape_filter($this->env, twig_capitalize_string_filter($this->env, (isset($context["name"]) ? $context["name"] : $this->getContext($context, "name"))), "html", null, true);
        echo " = \$('#table";
        echo twig_escape_filter($this->env, twig_capitalize_string_filter($this->env, (isset($context["name"]) ? $context["name"] : $this->getContext($context, "name"))), "html", null, true);
        echo "').dataTable({

    ";
        // line 4
        if (($this->getAttribute((isset($context["config"]) ? $context["config"] : null), "url", array(), "any", true, true) && $this->getAttribute((isset($context["config"]) ? $context["config"] : $this->getContext($context, "config")), "url"))) {
            // line 5
            echo "        \"bProcessing\": false,
        \"bServerSide\": true,
        \"sAjaxSource\": \"";
            // line 7
            echo twig_escape_filter($this->env, $this->env->getExtension('routing')->getPath($this->getAttribute((isset($context["config"]) ? $context["config"] : $this->getContext($context, "config")), "url")), "html", null, true);
            echo "\",
        \"sServerMethod\" : \"POST\",

    ";
        }
        // line 11
        echo "        \"bFilter\" : false,
        \"sPaginationType\" : \"full_numbers\",
        \"fnServerParams\": function ( aoData ) {
            // Campos para exibição
            ";
        // line 15
        $context['_parent'] = (array) $context;
        $context['_seq'] = twig_ensure_traversable((isset($context["columns"]) ? $context["columns"] : $this->getContext($context, "columns")));
        $context['loop'] = array(
          'parent' => $context['_parent'],
          'index0' => 0,
          'index'  => 1,
          'first'  => true,
        );
        if (is_array($context['_seq']) || (is_object($context['_seq']) && $context['_seq'] instanceof Countable)) {
            $length = count($context['_seq']);
            $context['loop']['revindex0'] = $length - 1;
            $context['loop']['revindex'] = $length;
            $context['loop']['length'] = $length;
            $context['loop']['last'] = 1 === $length;
        }
        foreach ($context['_seq'] as $context["field"] => $context["name"]) {
            // line 16
            echo "            aoData.push({
                \"name\": \"aCampo_";
            // line 17
            echo twig_escape_filter($this->env, ($this->getAttribute((isset($context["loop"]) ? $context["loop"] : $this->getContext($context, "loop")), "index") - 1), "html", null, true);
            echo "\", \"value\": \"";
            echo twig_escape_filter($this->env, (isset($context["field"]) ? $context["field"] : $this->getContext($context, "field")), "html", null, true);
            echo "\"
            });
            ";
            ++$context['loop']['index0'];
            ++$context['loop']['index'];
            $context['loop']['first'] = false;
            if (isset($context['loop']['length'])) {
                --$context['loop']['revindex0'];
                --$context['loop']['revindex'];
                $context['loop']['last'] = 0 === $context['loop']['revindex0'];
            }
        }
        $_parent = $context['_parent'];
        unset($context['_seq'], $context['_iterated'], $context['field'], $context['name'], $context['_parent'], $context['loop']);
        $context = array_merge($_parent, array_intersect_key($context, $_parent));
        // line 20
        echo "        }
    });
</script>
";
    }

    public function getTemplateName()
    {
        return "SaturnoDataTablesBundle:Skeleton:javascript.html.twig";
    }

    public function isTraitable()
    {
        return false;
    }

    public function getDebugInfo()
    {
        return array (  87 => 20,  65 => 16,  48 => 15,  42 => 11,  29 => 4,  22 => 2,  19 => 1,  106 => 21,  100 => 20,  95 => 17,  88 => 15,  79 => 13,  75 => 12,  72 => 11,  68 => 17,  63 => 7,  44 => 5,  20 => 1,  108 => 20,  102 => 5,  96 => 22,  94 => 20,  90 => 18,  64 => 16,  59 => 13,  39 => 11,  35 => 7,  27 => 4,  21 => 1,  36 => 6,  31 => 5,  28 => 3,);
    }
}
