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
    int n , m ;cin>>n>>m ;
    priority_queue < int> a,b ;
    for (int i=0 ; i<n ;i++) {
        int x;cin>>x;
        a.push (x);
    }
     for (int i=0 ; i<m;i++) {
        int x;cin>>x;
        b.push (x);
    }
    while (!a.empty ()) {
        if (b.size () > a.size() || b.empty ()) {
            cout <<"NO\n"; return;
        }
        int x= b.top (); b.pop ();
        if (a.top () == x)  {
            a.pop ();
        }
        else if (a.top () > x) {
            cout <<"NO\n"; return;
        }
        else {
            if (x & 1) {
                b.push(x/2) ; b.push( (x+1)/2);
            } else {
                  b.push(x/2) ;  b.push(x/2) ;
            }
        }
    }
    if (!b.empty ()) cout <<"NO\n";
    else cout <<"YES\n";
    
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