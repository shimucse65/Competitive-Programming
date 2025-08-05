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

vector<int> divi (int n) {
    vector <int> res ;
    for (int i = 1 ;i * i <= n ;i++) {
        if (n % i == 0) {
            res.push_back (i) ;
            if(i * i != n) {
                res.push_back (n / i) ;
            }
        }
    }
    sort (res.begin (), res.end ()) ;
    return res ;
}

void solve() {
    int l, r, x, y; cin >> l >> r >> x >> y;
    vector<int> xx = divi(x);
    vector<int> yy = divi(y);

    set<int> st1, st2;
    for(auto it: xx) {
        if (it >= l && it <= r) st1.insert(it);
    }
    for(auto it : yy) {
        if (it >= l && it <= r) st2.insert(it);
    }

    set<int> st3;

    for (auto it : st1) st3.insert(it);
    for (auto it : st2) st3.insert(it);
    if(st1.size() >= 1 && st2.size() >= 1) {
    for(auto it : st1) {
        for(auto it2 : st2) {
            int x = it * it2;
            if (x < l || x > r) continue;
            st3.insert(x);
        }
    }
}
   
    int cnt = 0;
    int z = x * y;
    for(auto it : st3) {
        int it2 = z / it;
        if(it2 < l || it2 > r) continue;
        if (gcd(it, it2) == x && lcm(it, it2) == y) cnt++;
    }
    cout << cnt << "\n";   
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}