import os.path

import jinja2
from jinja2.ext import Extension

class LoadExtension(Extension):
    """
    Extension that creates tag 'load' that implements c INCLUDE-like behavior

    Example:
        {% load "lib/stdlib.pbi" %}

    The first part of the basename is the files identifer - this case would be 'stdlib'

    A file is only ever _included_ once (it's text is outputted only once)
    A file is _imported_ to its identifer every time load is called

    So after this statement, macros and variables defined in stdlib.pbi could be accessed
    stdlib.my_macro
    stdlib.my_variable

    etc.
    """

    _TAG_NAME = 'load'

    # declare which strings set off this extension
    tags = set([_TAG_NAME])

    def __init__(self, environment):
        Extension.__init__(self, environment)

        # state to keep track of which files have been loaded
        environment.extend(_loaded_files=set())

    def parse(self, parser):
        # the first token is the token that started the tag.
        # get the line number so that we can give
        # that line number to the nodes we create by hand.
        lineno = parser.stream.next().lineno

        # parse the passed template name
        # `template` is a jinja2.nodes.Const after this
        try:
            template = parser.parse_expression()
        except jinja2.exceptions.TemplateSyntaxError:
            parser.fail('Missing Argument to %s' % self._TAG_NAME, lineno)

        # target variable value will be name up to first dot
        # but after any slashes in the path. Like go.
        try:
            template_name = template.value
        except AttributeError:
            parser.fail('Argument to %s must be a string' % self._TAG_NAME)
        basename = os.path.basename(template_name)
        import_as = basename.split('.')[0]

        # key uniqueness on the import_as
        already_included = import_as in self.environment._loaded_files
        self.environment._loaded_files.add(import_as)

        # build the nodes
        import_node = jinja2.nodes.Import(template, import_as, True).set_lineno(lineno) # template, target, with_context
        include_node = jinja2.nodes.Include(template, True, False).set_lineno(lineno) # template, with_cotext, ignore_missing

        if already_included:
            return import_node
        else:
            return [import_node, include_node]