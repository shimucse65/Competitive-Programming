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

    int n,k,q ;cin>>n>>k>>q ;
    vector <vector <int>>b (k ,vector <int> (n));
    for (int i=0;i<n;i++) {
        for (int j=0;j<k ;j++) cin>>b[j][i] ;
    }

     for (int j=0 ;j <k ;j++ ) {
        for (int i=1 ;i<n ;i++) {
            b[j][i]|= b[j][i-1] ;
        }
     }
     while (q--) {

        int m ;cin>>m ;
        int l=0 ,r=n-1 ;
        while (m--) {
            int r ;char c ;int val ;
            cin>>r >>c>>val ; r-- ;
            if (c=='>') {
                int it= upper_bound (b[r].begin () ,b[r].end () ,val) -b[r].begin() ;
                l= max (l ,it);
            } else {
                int it= lower_bound (b[r].begin () ,b[r].end () ,val)-b[r].begin () ;
                r=min (r ,it-1) ;
            }
        }
        if (l>r) cout <<-1<<"\n" ;
        else cout <<l+1 <<"\n" ;
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