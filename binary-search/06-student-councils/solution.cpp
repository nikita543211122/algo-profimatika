#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// можно ли собрать c советов по k человек
bool good(long long c, long long k, const vector<long long>& a) {
    long long total = 0;
    for (long long x : a)
        total += min(x, c);  // из группы не больше c человек
    return total >= k * c;
}

void solve() {
    long long k;
    int n;
    cin >> k >> n;
    vector<long long> a(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    // инвариант: good(left) = true, good(right) = false
    long long left = 0, right = sum / k + 1;
    while (right - left > 1) {
        long long mid = (left + right) / 2;
        if (good(mid, k, a)) left = mid;
        else right = mid;
    }
    cout << left << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}