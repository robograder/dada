"""
wrapper around PB binary
"""
import subprocess
import random

from logger import logger

class PBException(RuntimeError):
    pass

class PBWrapper(object):

    def __init__(self, binary_path):
        self.path = binary_path

    def pb(self, grammar, seed=None, start_state=None, wrap=True):
        """
        main entry point
        """
        # more randomness
        seed = str(random.random() if seed is None else seed)

        args = (
            ['-r', seed] +
            (['-s', start_state] if start_state is not None else []) +
            (['-w', '0'] if not wrap else []) +
            # turn on trace if we want verbose output
            (['-t'] if logger.verbose else [])
        )

        stdout, stderr, retcode = self._call(grammar, args)
        if retcode == -11: # segfault!
            raise PBException('Segmentation Fault! Args: %s' % ' '.join(args))
        elif retcode != 0:
            raise PBException(stderr)
        else:
            map(logger, [e for e in (ln.strip() for ln in stderr.split('\n')) if e])
            return stdout

    def check(self, grammar):
        """
        checks a grammar
        returns (ok?, any errors)
        """
        args = ['-i'] # inhibit
        stdout, stderr, retcode = self._call(grammar, args)
        if retcode == 0:
            return True, []
        else:
            # clean up stderr
            errors = [e for e in (err.strip() for err in stderr.split('\n')) if e]
            return False, errors

    def dump_grammar(self, grammar):
        """
        return a string representation of the grammar
        """
        args = ['-d', '-i'] # dump and inhibit
        stdout, stderr, retcode = self._call(grammar, args)
        if retcode == 0:
            return stdout
        else:
            raise PBException(stderr)

    def _call(self, grammar, args=None):
        args = args or []

        pb_call = [self.path] + args
        logger("Calling PB with cmd: %s" % ' '.join(pb_call))
        pb = subprocess.Popen(
                 pb_call,
                 stdin=subprocess.PIPE,
                 stdout=subprocess.PIPE,
                 stderr=subprocess.PIPE,
        )
        stdout, stderr = pb.communicate(grammar)
        logger("PB finished, return code: %d" % pb.returncode)
        return stdout, stderr, pb.returncode
