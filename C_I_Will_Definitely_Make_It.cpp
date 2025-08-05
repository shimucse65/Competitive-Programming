#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define int long long
#define endl '\n'
#define ff first
#define ss second
#define pii pair<int, int>
using namespace std;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, k ; cin >> n >> k;
    vector <int > a (n);
    for (int i = 0 ; i < n ;i++) {
        cin >> a[i];
    }
    k --;
    vector <int > v;
    v.push_back (a[k]);
    for(int i = 0; i < n ;i++) {
        if (a[i] > a[k]) v.push_back (a[i]);
    }
    sort (v.begin(), v.end ());

    if (a[k] == v.back()) {
        cout << "YES\n"; return;
    }

    if (v[1] - v[0] > v[0]) {
        cout << "NO\n" ; return;
    }
    for(int i = 1 ; i < v.size() - 1 ; i++) {
        int need = v[i + 1] - v[i];
        int ache =  v[i - 1];
        if (need > ache) {
            cout << "NO\n"; return;
        }
        if (v[i] == v.back()) break;
    }

    cout << "YES\n";   
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}