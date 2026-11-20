from itertools import islice
import sys


def solve() -> None:
    tokens = iter(map(int, sys.stdin.buffer.read().split()))
    tests = next(tokens)
    for _ in range(tests):
        n = next(tokens)
        values = sorted(set(islice(tokens, n)))
        print(" ".join(map(str, values)))


if __name__ == "__main__":
    solve()
