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

    int a,b,c,d; cin >> a >> b >> c>> d;
    int mn = min (c, d);

    if (a == b) {
        cout << 0 <<"\n"; return;
    } 
    if (a > b) {
        if (a % 2 == 0) {
            cout << -1 <<"\n"; return;
        }
        if (a - b > 1) {
             cout << -1 <<"\n"; return;
        }
        if ( a - b == 1) {
            cout << d <<"\n"; return;
        }
    }
    
     if (a < b) {
        int cnt = 0;
        while ( a != b) {
            if (a & 1) {
                cnt += c; a++;
            }
            else {
               cnt += mn;
               a ++; 
            }
        } 
        cout << cnt <<"\n";
        return;
    }   
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