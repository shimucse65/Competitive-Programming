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
    string s ;cin>>s ;
    int n= s.size () ;
    int a[n] ;
    for (int i=0;i<n;i++) a[i]= s[i]-'0' ;

    for (int i=0 ;i<n;i++) {
       // if (a[i]==0) continue ;
        int mx=a[i] ;
        int ind=i ;
        for (int j=i+1 ; j < min (n,i+9) ;j++) {
            int nw= a[j]- (j-i) ;
            if (nw<=0) continue ;
            if (nw>mx) {
                mx= nw ;
                ind= j ;
            }
        }
            for (int k=ind ; k>i;k--) {
                    a[k]= a[k-1] ;
            }
            a[i]= mx ;
          //  for (int i=0;i<n;i++) cout <<a[i] ; cout <<"\n" ;
    }
    for (int i=0;i<n;i++) cout <<a[i] ; cout <<"\n" ;
    
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