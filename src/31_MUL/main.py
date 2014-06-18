import sys

case_count = int(sys.stdin.readline().strip())
for case_id in range(case_count):
    a, b = map(int, sys.stdin.readline().strip().split())
    print(a * b)