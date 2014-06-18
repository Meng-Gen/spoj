import sys

case_count = int(sys.stdin.readline().strip())
for case_id in range(case_count):
    a, b = sys.stdin.readline().strip().split()
    print(int(str(int(a[::-1]) + int(b[::-1]))[::-1]))

