import sys
import json
import os
import os.path

import jinja2

import load_extension
import jinja_utils
from logger import logger


def preprocess(filename, data=None, load_paths=None):
    data = data or {}
    load_paths = load_paths or []

    # figure out our search paths
    basedir = os.path.dirname(os.path.realpath(__file__))
    lib_path = os.path.join(basedir, 'lib')
    paths = [lib_path] + [os.getcwd()] + ['/'] + [os.path.abspath(p) for p in load_paths]

    logger("Rendering template %s with search path %s" % (filename, ':'.join(paths)))

    loader = jinja2.FileSystemLoader(paths)
    env = jinja2.Environment(loader=loader, extensions=[load_extension.LoadExtension])
    env.globals['pb_word_list'] = jinja_utils.pb_word_list
    tem = env.get_template(filename)

    return tem.render(data)
