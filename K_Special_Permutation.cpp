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
    int n ; cin >> n;
    if (n < 4) {
        cout << -1 <<"\n";return;
    }
    if (n == 4) {
        cout << 2 <<" " << 4 <<" " << 1 <<" " << 3 <<"\n";
        return;
    }
    vector <int > v;
     if (n & 1) {
        for (int i = 2 ; i <= n ; i+= 2) {
            v.push_back (i);
        }
     } else {
        for (int i = 1 ; i <= n ; i+= 2) {
            v.push_back (i);
        }
     }
     if (v.size() != n) v.push_back (v.back() - 3);
     if (v.size() != n) v.push_back (v.back() + 4);
     if (v.size() != n) v.push_back (v.back() - 2);
     if (v.size() != n) v.push_back (v.back() - 4);
     if (v.size() != n) for (int i= v.back () - 2; v.size() != n; i-=2) v.push_back(i);

     for (auto it : v) cout << it <<" "; cout <<"\n";   
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