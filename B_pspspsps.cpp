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
    int n ;cin>> n ; 
    string s ;cin>>s ;
    if (s[0]=='s') s[0]='.' ;
    if (s[n-1]=='p') s[n-1]='.' ;
    int f1=0 , f2=0 ;
    for (auto it :s) {
        if (it=='s') f1=1 ;
        if (it=='p') f2=1 ;
    }
    if (f1==1 && f2==1) cout <<"NO\n" ;
    else cout<<"YES\n";
    
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