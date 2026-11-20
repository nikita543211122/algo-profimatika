import sys


def solve() -> None:
    tokens = iter(map(int, sys.stdin.buffer.read().split()))
    n = next(tokens)
    values = list(tokens)
    total = sum(values)

    if n < 3 or total % 3 != 0:
        print(0)
        return

    target = total // 3
    second_target = 2 * target
    prefix = first_cuts = answer = 0
    for i in range(n - 1):
        prefix += values[i]
        if prefix == second_target:
            answer += first_cuts
        if prefix == target:
            first_cuts += 1

    print(answer)


if __name__ == "__main__":
    solve()
