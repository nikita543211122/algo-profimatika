import sys


def lower_bound(a: list[int], x: int) -> int:
    """Первый индекс i, где a[i] >= x (или len(a)); массив отсортирован."""
    left, right = -1, len(a)
    while right - left > 1:
        mid = (left + right) // 2
        if a[mid] < x:
            left = mid
        else:
            right = mid
    return right


def upper_bound(a: list[int], x: int) -> int:
    """Первый индекс i, где a[i] > x (или len(a)); массив отсортирован."""
    left, right = -1, len(a)
    while right - left > 1:
        mid = (left + right) // 2
        if a[mid] <= x:
            left = mid
        else:
            right = mid
    return right


def solve() -> None:
    data = sys.stdin.buffer.read().split()
    n = int(data[0])
    a = sorted(int(x) for x in data[1:1 + n])
    k = int(data[1 + n])

    out = []
    pos = 2 + n
    for _ in range(k):
        l, r = int(data[pos]), int(data[pos + 1])
        pos += 2
        out.append(upper_bound(a, r) - lower_bound(a, l))
    print(" ".join(map(str, out)))


if __name__ == "__main__":
    solve()
