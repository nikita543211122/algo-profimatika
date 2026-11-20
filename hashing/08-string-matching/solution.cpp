#include <iostream>
#include <random>
#include <string>
#include <vector>
using namespace std;

constexpr long long MOD1 = 1'000'000'007;
constexpr long long MOD2 = 1'000'000'009;

void buildHashes(const string& text, long long base, long long mod,
                 vector<long long>& prefix, vector<long long>& power) {
    int n = static_cast<int>(text.size());
    prefix.assign(n + 1, 0);
    power.assign(n + 1, 1);

    for (int i = 0; i < n; ++i) {
        int code = text[i] - 'a' + 1;
        prefix[i + 1] = (prefix[i] * base + code) % mod;
        power[i + 1] = power[i] * base % mod;
    }
}

long long substringHash(int left, int right, const vector<long long>& prefix,
                        const vector<long long>& power, long long mod) {
    long long removed = prefix[left] * power[right - left] % mod;
    return (prefix[right] - removed + mod) % mod;
}

long long hashPattern(const string& pattern, long long base, long long mod) {
    long long hash = 0;
    for (char letter : pattern) {
        hash = (hash * base + (letter - 'a' + 1)) % mod;
    }
    return hash;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string text, pattern;
    cin >> text >> pattern;
    int n = static_cast<int>(text.size());
    int m = static_cast<int>(pattern.size());
    if (m > n) {
        cout << 0 << '\n';
        return 0;
    }

    mt19937 generator(random_device{}());
    uniform_int_distribution<long long> chooseBase(256, MOD1 - 2);
    long long base1 = chooseBase(generator);
    long long base2 = chooseBase(generator);

    vector<long long> prefix1, power1, prefix2, power2;
    buildHashes(text, base1, MOD1, prefix1, power1);
    buildHashes(text, base2, MOD2, prefix2, power2);

    long long target1 = hashPattern(pattern, base1, MOD1);
    long long target2 = hashPattern(pattern, base2, MOD2);
    int answer = 0;
    for (int i = 0; i <= n - m; ++i) {
        if (substringHash(i, i + m, prefix1, power1, MOD1) == target1 &&
            substringHash(i, i + m, prefix2, power2, MOD2) == target2) {
            ++answer;
        }
    }

    cout << answer << '\n';
}
