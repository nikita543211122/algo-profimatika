import random
import sys


MOD1 = 1_000_000_007
MOD2 = 1_000_000_009


def build_hashes(text: bytes, base: int, mod: int) -> list[int]:
    prefix = [0] * (len(text) + 1)
    current = 0
    for i, letter in enumerate(text, start=1):
        current = (current * base + (letter - 96)) % mod
        prefix[i] = current
    return prefix


def substring_hash(
    left: int, right: int, prefix: list[int], power: int, mod: int
) -> int:
    return (prefix[right] - prefix[left] * power) % mod


def hash_pattern(pattern: bytes, base: int, mod: int) -> int:
    result = 0
    for letter in pattern:
        result = (result * base + (letter - 96)) % mod
    return result


def solve() -> None:
    text, pattern = sys.stdin.buffer.read().split()
    n, m = len(text), len(pattern)
    if m > n:
        print(0)
        return

    base1 = random.randrange(256, MOD1 - 1)
    base2 = random.randrange(256, MOD2 - 1)
    prefix1 = build_hashes(text, base1, MOD1)
    prefix2 = build_hashes(text, base2, MOD2)
    power1 = pow(base1, m, MOD1)
    power2 = pow(base2, m, MOD2)
    target1 = hash_pattern(pattern, base1, MOD1)
    target2 = hash_pattern(pattern, base2, MOD2)

    answer = 0
    for i in range(n - m + 1):
        if (
            substring_hash(i, i + m, prefix1, power1, MOD1) == target1
            and substring_hash(i, i + m, prefix2, power2, MOD2) == target2
        ):
            answer += 1

    print(answer)


if __name__ == "__main__":
    solve()
