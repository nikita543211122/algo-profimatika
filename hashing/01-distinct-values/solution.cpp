#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;

        set<int> values;
        for (int i = 0; i < n; ++i) {
            int value;
            cin >> value;
            values.insert(value);
        }

        const char* separator = "";
        for (int value : values) {
            cout << separator << value;
            separator = " ";
        }
        cout << '\n';
    }
}
