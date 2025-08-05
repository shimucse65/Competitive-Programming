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

    int n,m,k;cin >>n>>m >>k;
    if (max (n,m) <  k) {
        cout << -1 <<"\n"; return;
    }
    string ans;
    if (n > m) {
        ans += string (k,'0');
        n -= k;
    } else {
        ans += string (k,'1');
        m -= k;
    }
    while (n || m) {
        if (ans.back ()=='1') {
            if (n) {
                ans += '0'; n--;
            } else {
                ans += '1'; m--;
            }
        } else {
            if (m) {
                ans += '1'; m--;
            } else {
                ans += '0'; n--;
            }
        }       
    }
    int sm=0 ;
    for (auto ch : ans) {
        sm += ch=='0'? -1 : 1;
        if (abs(sm) > k) {
            cout << -1 <<"\n"; return;
        }
    }
    cout << ans <<"\n";    
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