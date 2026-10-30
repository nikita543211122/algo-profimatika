#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    while (k--) {
        int x;
        cin >> x;
        // инвариант: a[left] < x, a[right] >= x
        int left = -1, right = n;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (a[mid] < x) left = mid;
            else right = mid;
        }
        if (right < n && a[right] == x) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}