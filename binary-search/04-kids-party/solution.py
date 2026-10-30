import sys


def cnt(T: int, t: int, z: int, y: int) -> int:
    """Сколько шариков надует помощник за время T."""
    L = z * t + y  # полный цикл: z шариков + отдых
    return (T // L) * z + min(z, (T % L) // t)


def good(T: int, m: int, helpers: list[tuple[int, int, int]]) -> bool:
    return sum(cnt(T, t, z, y) for t, z, y in helpers) >= m


def solve() -> None:
    data = sys.stdin.buffer.read().split()
    m, n = int(data[0]), int(data[1])
    helpers = [
        (int(data[2 + 3 * i]), int(data[3 + 3 * i]), int(data[4 + 3 * i]))
        for i in range(n)
    ]

    # инвариант: good(left) = False, good(right) = True
    left, right = -1, 3_000_000
    while right - left > 1:
        mid = (left + right) // 2
        if good(mid, m, helpers):
            right = mid
        else:
            left = mid

    T = right
    rest = m  # сколько шариков ещё не раздали
    give = []
    for t, z, y in helpers:
        g = min(cnt(T, t, z, y), rest)
        rest -= g
        give.append(g)

    print(T)
    print(" ".join(map(str, give)))


if __name__ == "__main__":
    solve()
