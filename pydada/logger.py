"""
Simple wrapper for handling verbosity OK
"""
import sys

class Logger(object):

    def __init__(self):
        self.verbose = False

    def __call__(self, msg):
        if self.verbose:
            sys.stderr.write("%s\n" % msg)

logger = Logger()
