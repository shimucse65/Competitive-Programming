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

    int n , m;cin >>n >>m ;
    set < int> st[n] ;
     map < int , int> mp;

    for (int i=0 ; i<n ;i++) {
       for (int j=0 ; j<m ;j++) {
            int x ;cin >>x ;
            st[i].insert (x);
            mp[x]++ ;
        }
    }

    for (auto it :mp) {
        if (it.ss>=2) {
            cout << -1 <<"\n" ; return;
        }
    }
    for (int i=0 ;i <=n ;i++) {
        for(auto it : st[i]) cerr << it <<" "; cerr <<"\n";
    }

    vector < int> v;

    int cur=0 ;
    cerr << n*m -1 <<"\n";

    while ( cur <= n*m-1) {

        for (int i=0 ;i<=n ;i++) {
           for (auto it :st[i]) {
            if (it==cur) v.push_back (i); break;
           }
        }

        cur++ ;
        
    }
   

  // for (auto it :v) cerr << it <<" "; cerr <<"\n";

   for (int i=0 ; i <v.size () ;i++) {
     if ()
   }


   
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
