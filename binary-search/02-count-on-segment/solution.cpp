#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// первый индекс i, где a[i] >= x (или n); массив отсортирован
int lowerBound(const vector<int>& a, int x) {
    int left = -1, right = a.size();
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (a[mid] < x) left = mid;
        else right = mid;
    }
    return right;
}

// первый индекс i, где a[i] > x (или n); массив отсортирован
int upperBound(const vector<int>& a, int x) {
    int left = -1, right = a.size();
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (a[mid] <= x) left = mid;
        else right = mid;
    }
    return right;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    int k;
    cin >> k;
    while (k--) {
        int l, r;
        cin >> l >> r;
        cout << upperBound(a, r) - lowerBound(a, l) << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}