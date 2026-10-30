import sys


def good(t: int, n: int, x: int, y: int) -> bool:
    """Можно ли за время t сделать n копий."""
    m = min(x, y)  # первую копию делает быстрый ксерокс
    if t < m:
        return False
    return (t - m) // x + (t - m) // y >= n - 1


def solve() -> None:
    n, x, y = map(int, sys.stdin.readline().split())

    # инвариант: good(left) = False, good(right) = True
    left, right = 0, n * max(x, y)
    while right - left > 1:
        mid = (left + right) // 2
        if good(mid, n, x, y):
            right = mid
        else:
            left = mid
    print(right)


if __name__ == "__main__":
    solve()
