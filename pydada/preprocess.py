import sys
import json
import os
import os.path

import jinja2

import load_extension



def preprocess(filename, data=None, load_paths=None):
    data = data or {}
    load_paths = load_paths or []

    # figure out our search paths
    basedir = os.path.dirname(os.path.realpath(__file__))
    lib_path = os.path.join(basedir, 'lib')
    paths = [lib_path] + [os.getcwd()] + [os.path.abspath(p) for p in load_paths]

    loader = jinja2.FileSystemLoader(paths)
    env = jinja2.Environment(loader=loader, extensions=[load_extension.LoadExtension])
    tem = env.get_template(filename)

    return tem.render(data)

if __name__ == "__main__":
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument('filename', help="Filename to preprocess")
    parser.add_argument('-j', '--json-data', help="Json file containing data to render")
    parser.add_argument('-I', '--include-dir', action='append', dest='include_dirs', default=[])

    args = parser.parse_args()

    if args.json_data:
        # let this blow up for now
        f = open(args.json_data)
        data = json.load(f)
        f.close()
    else:
        data = None

    print preprocess(args.filename, data, args.include_dirs)
