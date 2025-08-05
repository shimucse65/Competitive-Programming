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
    
    int a[6] ;
    for (int i=1 ; i<=5 ;i++) cin>>a[i] ;
    int cnt=0;
    vector <int>v;
    for (int i=1 ; i<=5 ;i++) {
        if (a[i]!=i) {
            cnt++ ; 
            v.push_back (i) ;
        }
    }
   
    if (cnt !=2) cout <<"No\n" ;
  
    else {
        if (v[1]-v[0]==1) cout <<"Yes\n" ;
        else cout <<"No\n";
    }
    
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
