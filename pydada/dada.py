import os
import sys
import subprocess

import preprocess

PB_BINARY = os.environ['PB_EXECUTABLE_PATH']

def call_pb(grammar_string, args=[]):
    pb_call = [
        PB_BINARY,
    ] + args

    pb = subprocess.Popen(pb_call, stdin=subprocess.PIPE)
    pb.stdin.write(grammar_string)
    pb.stdin.close()

    pb.wait()

if __name__ == "__main__":
    import argparse

    parser = argparse.ArgumentParser()
    parser.add_argument('filename', help="Filename to preprocess")
    parser.add_argument('-j', '--json-data', help="Json file containing data to render")
    parser.add_argument('-I', '--include-dir', action='append', dest='include_dirs', help="directories to search", default=[])

    args, leftover = parser.parse_known_args()

    if args.json_data:
        # let this blow up for now
        f = open(args.json_data)
        data = json.load(f)
        f.close()
    else:
        data = None

    grammar = preprocess.preprocess(args.filename, data, args.include_dirs)
    call_pb(grammar, leftover)

