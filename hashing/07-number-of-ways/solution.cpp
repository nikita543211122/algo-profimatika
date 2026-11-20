#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> values(n);
    long long total = 0;
    for (long long& value : values) {
        cin >> value;
        total += value;
    }

    if (n < 3 || total % 3 != 0) {
        cout << 0 << '\n';
        return 0;
    }

    long long target = total / 3;
    long long prefix = 0;
    long long firstCuts = 0;
    long long answer = 0;
    for (int i = 0; i < n - 1; ++i) {
        prefix += values[i];
        if (prefix == 2 * target) {
            answer += firstCuts;
        }
        if (prefix == target) {
            ++firstCuts;
        }
    }

    cout << answer << '\n';
}
