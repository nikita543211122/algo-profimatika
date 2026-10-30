#include <iostream>
#include <algorithm>
using namespace std;

// можно ли за время t сделать n копий
bool good(long long t, long long n, long long x, long long y) {
    long long m = min(x, y);
    if (t < m) return false;
    return (t - m) / x + (t - m) / y >= n - 1;
}

void solve() {
    long long n, x, y;
    cin >> n >> x >> y;

    // инвариант: good(left) = false, good(right) = true
    long long left = 0, right = n * max(x, y);
    while (right - left > 1) {
        long long mid = (left + right) / 2;
        if (good(mid, n, x, y)) right = mid;
        else left = mid;
    }
    cout << right << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}