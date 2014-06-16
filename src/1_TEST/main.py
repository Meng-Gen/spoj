import sys

while True:
    line = sys.stdin.readline().strip()
    if line == "42":
        break
    else:
        print(line)
