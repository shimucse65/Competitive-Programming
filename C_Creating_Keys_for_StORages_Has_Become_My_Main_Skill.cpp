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
    int n, x; cin >> n>>x;
    vector < int >res ;
    int orr=0;
    for (int i=0 ; i < n ; i++) {
        bool f=1;
        for (int j = 0 ; j < 31 ;j++) {
            if (( (i & (1 << j)) != 0 ) && (( x & (1 << j))==0)) {
                f=0 ; break;
            }
        }
        if (!f) continue ;
        res.push_back (i); orr |= i;
    }
    // cerr << orr <<"\n";
    //for (auto it :res) cerr << it <<" " ; cerr <<"\n";

    if (orr==x) {
        while (res.size () != n) res.push_back (x);
    } else {
        if (res.size () != n) {
            while (res.size () != n) res.push_back (x); 
        }  else {
           res.pop_back() ;
           res.push_back (x);
        }
    }
   
    for (auto it :res) cout << it <<" " ; cout <<"\n";
    
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