import os
import sys
import subprocess

import preprocess
import pb
from logger import logger

def fatal(msg):
    sys.stderr.write("Dada: %s\n" % msg)
    sys.exit(1)

def warn(msg):
    sys.stderr.write("Dada: %s\n" % msg)

PB_BINARY = os.environ['PB_EXECUTABLE_PATH']

if __name__ == "__main__":
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument('filename', help="Filename to preprocess")
    parser.add_argument('-v', '--verbose', action='store_true', default=False, help="Makes verbose output appear on stderr")

    preprocessor_args = parser.add_argument_group('preprocessor')
    preprocessor_args.add_argument('-j', '--json-data', help="Json file containing data to render")
    preprocessor_args.add_argument('-I', '--include-dir', action='append', dest='include_dirs', help="directories to search", default=[])
    preprocessor_args.add_argument('-p', '--preprocess-only', action='store_true', default=False, help='only preprocess')

    pb_args = parser.add_argument_group('pb')
    pb_mode_group = pb_args.add_mutually_exclusive_group()
    pb_mode_group.set_defaults(mode='RESOLVE')
    pb_mode_group.add_argument('-c', '--check', action='store_const', const='CHECK', dest='mode', help='check a grammar')
    pb_mode_group.add_argument('-d', '--dump', action='store_const', const='DUMP', dest='mode', help='dump a grammar')
    pb_args.add_argument('-r', '--random-seed', type=int, dest='seed', help='random seed, for reproducibility', default=None)
    pb_args.add_argument('--nowrap', action='store_false', dest='wrap', help='prevents output wrapping', default=True)
    pb_args.add_argument('--start-state', help='where should pb start the grammar?', default=None)

    args = parser.parse_args()
    if args.verbose:
        logger.verbose = True

    if args.json_data:
        # let this blow up for now
        logger('Loading data for template from file %s' % args.json_data)

        try:
            f = open(args.json_data)
            data = json.load(f)
            f.close()
        except IOError as e:
            fatal("Unable to open data file: %s" % str(e))
    else:
        data = None

    try:
        grammar = preprocess.preprocess(args.filename, data, args.include_dirs)
    except:
        warn("Error in preprocess! Re-raising exception")
        raise

    if args.preprocess_only:
        logger("preprocess only, dumping grammar and quitting")
        print grammar
        sys.exit(0)

    pbw = pb.PBWrapper(PB_BINARY)

    if args.mode == 'CHECK':
        logger("Checking grammar...")
        grammar_ok, errors = pbw.check(grammar)
        map(logger, errors)
        sys.exit(not grammar_ok) # True --> 0
    elif args.mode == 'DUMP':
        print pbw.dump_grammar(grammar)
    elif args.mode == 'RESOLVE':
        logger("Resolving Grammar")
        print pbw.pb(grammar, seed=args.seed, wrap=args.wrap, start_state=args.start_state)
    else:
        raise RuntimeError("Unknown mode: %s" % args.mode)

