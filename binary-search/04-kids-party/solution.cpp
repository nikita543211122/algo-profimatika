#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// сколько шариков надует помощник за время T
long long cnt(long long T, long long t, long long z, long long y) {
    long long L = z * t + y;  // полный цикл: z шариков + отдых
    return (T / L) * z + min(z, (T % L) / t);
}

bool good(long long T, long long m, const vector<long long>& t,
          const vector<long long>& z, const vector<long long>& y) {
    long long total = 0;
    for (int i = 0; i < (int)t.size(); i++)
        total += cnt(T, t[i], z[i], y[i]);
    return total >= m;
}

void solve() {
    long long m;
    int n;
    cin >> m >> n;
    vector<long long> t(n), z(n), y(n);
    for (int i = 0; i < n; i++) cin >> t[i] >> z[i] >> y[i];

    // инвариант: good(left) = false, good(right) = true
    long long left = -1, right = 3000000;
    while (right - left > 1) {
        long long mid = (left + right) / 2;
        if (good(mid, m, t, z, y)) right = mid;
        else left = mid;
    }

    long long T = right;
    cout << T << '\n';

    long long rest = m;  // сколько шариков ещё не раздали
    for (int i = 0; i < n; i++) {
        long long give = min(cnt(T, t[i], z[i], y[i]), rest);
        rest -= give;
        cout << give << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}