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

    int n,k;cin>>n>>k ;
    int a[n+1] ;
    for (int i=1;i<=n;i++) cin>>a[i] ;
    vector <pair <int , double> >v ;
    while (k--) {
        int ind ;cin>>ind ;
        double val ;cin>>val ;
        v.push_back ({ind ,val}) ;
    }
    double cnt=1 ;
    int ind=n+1 ;
    for (int i=1 ;i<=n ;i++) {
        if (a[i]!=i) ind=i ;
    }
    for (auto it :v) {
        int id= it.ff ;
        double val= it.ss ;
        if (id>=ind) {
            cnt*= (1-val) ;
        }
    }
    double ans= 1-cnt ;
    if (is_sorted (a+1,a+n+1)) ans=1 ;
    cout <<setprecision (6) << fixed << ans <<"\n";    
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