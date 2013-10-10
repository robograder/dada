import sys
import subprocess

# pipes passed script
# assumes a lot - this is POC

PB_BINARY = 'bin/pb'
CPP_BINARY = 'cpp'

args = sys.argv[1:]

script, rest = args[0], args[1:]

cpp_call = [
  CPP_BINARY,
  '-I',
  './include',
  script
]

pb_call = [
  PB_BINARY,
] + rest

cpp = subprocess.Popen(cpp_call, stdout=subprocess.PIPE)
pb = subprocess.Popen(pb_call, stdin=cpp.stdout)

cpp.wait()
pb.wait()

