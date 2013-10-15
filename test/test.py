import os
import os.path
import sys
import subprocess

try:
    dada_executable = sys.argv[1]
except IndexError:
    print 'Please pass path to dada executable as first arg'
    sys.exit(1)


source_dir = os.path.dirname(os.path.realpath(__file__))

inputs_dir = 'input'
expecteds_dir = 'expected'

# Assume that for every thing in input, there is
# a corresponding file in expected

SEED = '1000'

full_inputs_dir = os.path.join(source_dir, inputs_dir)
full_expecteds_dir = os.path.join(source_dir, expecteds_dir)

tests = []
statusi = {}
for fp in os.listdir(full_inputs_dir):
    print '-' * 40

    test_name = fp.split('.')[0]
    print 'Testing %s...' % test_name
    tests.append(test_name)
    statusi[test_name] = True

    print '=' * 10
    
    full_fp = os.path.join(full_inputs_dir, fp)
    try:
        res = subprocess.check_output([dada_executable, full_fp, '-r', SEED], stderr=subprocess.STDOUT)
    except subprocess.CalledProcessError as e:
        print "FAILED\n%s\nFAILED" % e.output
        statusi[test_name] = False
    else:
        print res
        print '=' * 10
        
        # now check that it matches
        with open(os.path.join(full_expecteds_dir, "%s.txt" % test_name)) as ef:
            content = ef.read()
            if not content.strip() == res.strip():
                print "FAILED: does not match"
                print content
                statusi[test_name] = False 
            else:
                print 'OK!'



print "\n\n"
print "------------"

for test_name in tests:
   print "%s... %s" % (test_name, 'OK!' if statusi[test_name] else '~FAIL~')

print

total_count = len(tests)
failed = sum(not v for v in statusi.values())
print "%d / %d" % (total_count - failed, total_count)
