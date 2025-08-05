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
    int l1 ,b1 ,l2 ,b2 ,l3 ,b3;
    cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;

    if (l1==l2 && l2 == l3) {
        if (b1+b2+b3==l1) {
            cout <<"YES\n"; return;
        }
    }
    if (b1==b2 && b2==b3) {
        if (l1+l2+l3==b1) {
            cout <<"YES\n"; return;
        }
    }   
    if ( l1==l2  &&  b1+b2==b3 && l1+l3==b3) {
         cout <<"YES\n"; return;
    }
    if ( l2==l3  && b2+b3==b1  && l1 + l2 ==b1) {
        cout <<"YES\n"; return;
    }
    if (b1==b2) {
            if (b2+b3==l3 && l1+l2==l3) {
            cout <<"YES\n"; return;
        }
    }
    if (b2==b3) {
        if (l1==l2+l3 && b1+b2==l1) {
            cout <<"YES\n"; return;
        }
    }
    cout <<"NO\n";
    
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