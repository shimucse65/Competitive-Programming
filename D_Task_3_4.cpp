#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int q;
    cin >> q;

    while (q--) {
        int p;
        cin >> p;

        auto low = lower_bound(v.begin(), v.end(), p);

        if (low != v.end() && *low == p) {
            cout << "Yes " << (low - v.begin() + 1) << "\n";
        } else {
            cout << "No " << (low - v.begin() + 1) << "\n";
        }
    }

    return 0;
}
