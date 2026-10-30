import sys


def ok(k: int, t: str, p: str, when: list[int]) -> bool:
    """Останется ли p подпоследовательностью t, если вычеркнуть первые k букв."""
    i = 0  # указатель по t
    j = 0  # указатель по p
    while i < len(t) and j < len(p):
        # буква жива и совпадает с нужной
        if when[i] >= k and t[i] == p[j]:
            j += 1
        i += 1
    return j == len(p)


def solve() -> None:
    data = sys.stdin.buffer.read().split()
    t = data[0].decode()
    p = data[1].decode()
    n = len(t)

    # when[j] — на каком шаге вычеркивается t[j]
    when = [0] * n
    for i in range(n):
        when[int(data[2 + i]) - 1] = i

    # инвариант: ok(left) = True, ok(right) = False
    left, right = 0, n - len(p) + 1
    while right - left > 1:
        mid = (left + right) // 2
        if ok(mid, t, p, when):
            left = mid
        else:
            right = mid
    print(left)


if __name__ == "__main__":
    solve()
