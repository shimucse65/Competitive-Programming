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
    int n , k;cin>>n>>k ;
    int z=0 ,o=0 ;
    string s;cin>>s ;
    for (int i=0 ;i<k ;i++) {
        int zero=0 , one=0 ;
        for (int j=i ;j<n ;j+=k) {
            if (s[j]=='1') one=1 ;
            else if (s[j]=='0') zero=1 ;
        }
        if (one && zero) {
            cout <<"NO\n" ; return ;
        }
        if (one) s[i]='1' ;
        else if (zero) s[i]='0' ;
        if (s[i]=='1') o++ ;
        else if (s[i]=='0') z++ ;       
    }
    if (2*z>k || 2*o >k) {
        cout <<"NO\n" ; return ;
    }
    cout <<"YES\n" ;   
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