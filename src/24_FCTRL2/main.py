import math
import sys

case_count = int(sys.stdin.readline().strip())
for case_id in range(case_count):
    n = int(sys.stdin.readline().strip())
    print(math.factorial(n))
