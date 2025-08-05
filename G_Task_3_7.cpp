#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define ff first 
# define ss second

bool cmp(pii a, pii b) {
    if (a.ff != b.ff) return a.ff < b.ff;  
    return a.ss > b.ss;                    
}

void solve() {
    int n; cin >> n;
    vector<pii> v;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
  
    sort(v.begin(), v.end(), cmp);
    for (auto it : v) {
        cout << it.ff << " " << it.ss << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1; 
    cin >> t;
    while (t--) {
        solve();
    }
}
