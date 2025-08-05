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
const int N = 1e6 + 10;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int fact[N] ;
void calc () {
    fact[0]=1 ;
    for (int i=1 ;i<N;i++) fact[i]= (fact[i-1]*i )%mod;
}
int bigmod (int a ,int b) {
    if (b==0) return 1 ;
    int res= bigmod (a,b/2) ;
    if (b&1) return (a*(res*res)%mod)%mod ;
    else return (res*res)%mod ;

}
void solve() {
    int n ;cin>>n ;
    int tot= fact[n] ;
    int uni= bigmod (2,n-1) ;
   // cerr <<fact[n]<<" "<<bigmod (2,n-1) <<"\n" ;
    cout <<(tot- uni+mod)%mod <<"\n" ;  
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    calc () ;
    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}