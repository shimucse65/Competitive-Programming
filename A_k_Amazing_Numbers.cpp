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
const int N = 3e5 + 10;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector <int>g[N] ;
void reset () {
    for (int i=0 ;i<N ;i++) g[i].clear () ;
}
void solve() {
    reset () ;
    int n ;cin>>n ;
    int a[n+1] ;
    for(int i=1;i<=n ;i++) cin>>a[i] ;
    
    map <int ,int>mp ;
    for (int i=1 ;i<=n ;i++) mp[i]=0 ;

    for (int i=1 ;i<=n ;i++) {
        if (mp.count (a[i])) {
            g[a[i]].push_back (i-mp[a[i]]) ;
            mp[a[i]]=i ;
        } 
    }
    for (int i=1 ;i<=n ;i++) {
        g[i].push_back (n+1-mp[i]) ;
    }
    map <int ,int>mp2 ;
    for (int i=1 ;i<=n ;i++) {
        int mx=-inf ;
        for (auto it :g[i]) {
            mx= max (mx ,it) ;
        }
       mp2[i]=mx ;
    }
 //  for (auto it :mp2 ) cerr <<it.ff <<" "<<it.ss <<"\n" ;
   
    int ans[n+1] ;
    for (int i=1 ;i<=n ;i++) ans[i]=-1 ;
    int cur=n ;

   for (auto it :mp2) {
     int st= it.ss ;
     for (int i=st ;i<=cur ;i++) {
        if (ans[i]==-1) ans[i]= it.ff ;
     }
      cur= st ;
   }
   

//    for (int i=1 ;i<=n ;i++) {
//         while (cur >= mp2[i]) {
//             ans[cur]= i ;
//             cur-- ;
//         }
//    }

   for (int i=1 ;i<=n ;i++) cout <<ans[i] <<" " ; cout <<"\n" ;
    
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