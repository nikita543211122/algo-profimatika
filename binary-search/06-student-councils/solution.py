import sys


def good(c: int, k: int, a: list[int]) -> bool:
    """Можно ли собрать c советов по k человек."""
    # из группы в c советов идёт не больше c человек
    return sum(min(x, c) for x in a) >= k * c


def solve() -> None:
    data = sys.stdin.buffer.read().split()
    k, n = int(data[0]), int(data[1])
    a = [int(x) for x in data[2:2 + n]]

    # инвариант: good(left) = True, good(right) = False
    left, right = 0, sum(a) // k + 1
    while right - left > 1:
        mid = (left + right) // 2
        if good(mid, k, a):
            left = mid
        else:
            right = mid
    print(left)


if __name__ == "__main__":
    solve()
