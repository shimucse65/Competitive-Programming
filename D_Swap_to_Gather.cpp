#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> pos;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            pos.push_back(i);
        }
    }
    int one = pos.size();
    if (one == 0) {
        cout << 0 << endl;
        return;
    }
    int mi = one / 2;
    int mp = pos[mi];
    int tot = 0;
    for (int i = 0; i < one; ++i) {
        int tg = mp - (mi - i);
        tot += abs(pos[i] - tg);
    }
    cout << tot << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
