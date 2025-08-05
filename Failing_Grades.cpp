#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    int sm = 0;
    bool f = true;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sm += x;
        double avg = (double)sm / (i + 1);
        if (avg < 40) f = false;
    }
    cout << (f ? "Yes\n" : "No\n");
}

signed main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
