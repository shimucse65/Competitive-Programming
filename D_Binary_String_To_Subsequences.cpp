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
    int n ;cin>>n ;
    string s;cin>>s ;
    stack <int>zero ,one ;
    int next=1 ;
    vector <int>ans (n) ;
    for (int i=0 ;i<n;i++) {
        if (s[i]=='0') {
            if (one.empty ()) {
                ans[i]= next ; next++ ;
                zero.push (ans[i]);
            } else {
                int c= one.top () ; one.pop () ;
                ans[i]= c;
                zero.push (c) ;   
            }

        } else {
            if (zero.empty ()) {
                ans[i]= next ; next++ ;
                one.push (ans[i]);
            } else {
                int c= zero.top () ; zero.pop () ;
                ans[i]= c;
                one.push(c) ;
            }

        }
    }
    int mx=-inf ;
    for (int i=0 ;i<n ;i++) {
        mx= max (mx ,ans[i]) ;
    }
    cout <<mx <<"\n" ;
    for (int i=0;i<n ;i++) cout <<ans[i] <<" " ; cout <<"\n" ;
    
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