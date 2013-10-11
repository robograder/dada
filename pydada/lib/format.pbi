{#   format.pbi  acb  65 Afm 3161 #}
{#   Main Dada Engine include file, for selecting the output format from #}
{#   preprocessor defines #}

{% if HTML is defined %}
{% load "format/html.pbi" %}
{% elif NROFF is defined or TROFF is defined or DITROFF is defined %}
{% load "format/troff.pbi" %}
{% else %}
{% load "format/plain.pbi" %}
{% endif %}
