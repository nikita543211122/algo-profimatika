import sys


def solve() -> None:
    data = sys.stdin.buffer.read().split()
    n, k = int(data[0]), int(data[1])
    a = [int(x) for x in data[2:2 + n]]
    queries = data[2 + n:2 + n + k]

    out = []
    for q in queries:
        x = int(q)
        # инвариант: a[left] < x, a[right] >= x
        left, right = -1, n
        while right - left > 1:
            mid = (left + right) // 2
            if a[mid] < x:
                left = mid
            else:
                right = mid
        out.append("YES" if right < n and a[right] == x else "NO")
    print("\n".join(out))


if __name__ == "__main__":
    solve()
