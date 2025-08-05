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

int in[N] ;
vector <int>g[N] ;
void solve() {
    int n ,m ; cin>>n>>m ;
    for (int i=0 ;i<m ;i++) {
        int x ,y;cin>> x>>y ;
        g[x].push_back (y) ;
        in[y]++ ;
    }
   // for (int i=1 ; i<=7 ;i++) cout <<in[i] <<" " ; cout <<"\n" ;
    vector <int>ans ;
    priority_queue < int , vector <int> , greater <int>  > pq ;
    for (int i=1 ;i<=n ;i++) {
        if (in[i]==0) pq.push(i) ;
    }
    // while (!pq.empty ()) {
    //     cout <<pq.top () <<" " ; pq.pop () ;
    // }
    while (!pq.empty ()) {
        int cur= pq.top () ; pq.pop () ;
        ans.push_back (cur) ;
        for (auto it :g[cur]) {
            in[it]-- ;
            if (in[it]==0) pq.push(it) ;
        }
    }
    for (auto it :ans) cout <<it <<" " ; cout<<"\n" ;
    
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