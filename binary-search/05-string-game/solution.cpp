#include <iostream>
#include <vector>
#include <string>
using namespace std;

// останется ли p подпоследовательностью t,
// если Петя вычеркнет первые k букв
bool ok(int k, const string& t, const string& p,
        const vector<int>& when) {
    int i = 0;  // указатель по t
    int j = 0;  // указатель по p
    while (i < (int)t.size() && j < (int)p.size()) {
        // буква жива и совпадает с нужной
        if (when[i] >= k && t[i] == p[j]) j++;
        i++;
    }
    return j == (int)p.size();
}

void solve() {
    string t, p;
    cin >> t >> p;
    int n = t.size();

    // when[j] — на каком шаге вычеркивается t[j]
    vector<int> when(n);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        when[a - 1] = i;
    }

    // инвариант: ok(left) = true, ok(right) = false
    int left = 0, right = n - (int)p.size() + 1;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (ok(mid, t, p, when)) left = mid;
        else right = mid;
    }
    cout << left << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}