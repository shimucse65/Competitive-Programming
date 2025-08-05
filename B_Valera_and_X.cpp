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
    char a[n][n] ;
    for (int i=0;i<n;i++) {
        for (int j=0 ;j<n;j++) cin>>a[i][j];
    }
    char p= a[0][0] ;
    char q= a[0][1] ;
    int f1=1 ;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (i==j) {
                if (a[i][j]!=p) {
                   
                    f1=0 ; break ;
                }
            }
                else if (i+j==n-1) {
                    if (a[i][j] !=p){
                       
                        f1=0 ; break ;
                    }
                }
                else {
                    if (a[i][j]==p || a[i][j]!=q) {
                       
                        f1=0 ; break;
                    }
                }
            
        }
    
    }
    if (f1) cout <<"YES\n" ; 
    else cout <<"NO\n" ;
    
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