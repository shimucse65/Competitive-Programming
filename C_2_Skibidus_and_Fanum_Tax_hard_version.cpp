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
    int n,m ; cin >> n>>m ;
    int a[n] ,b[m];
    for (int i=0; i< n ;i++)  cin >> a[i];
    for (int i=0; i < m ;i++) cin >> b[i];
    
    sort (b, b+m);
    int pv= min (a[0] , b[0]- a[0]);
    vector < int > ans ; ans.push_back (pv);

    for (int i=1 ; i < n ;i++) {
       if (a[i] >= pv )  {
             int ind= lower_bound (b, b+m , pv + a[i])-b;
             if (ind < m) pv=  min (a[i] ,b[ind]- a[i]);
             else pv= a[i]; 
             ans.push_back (pv);                  
       }  else {
           int ind= lower_bound (b, b+m , pv + a[i])- b;
           if (ind < m) {
            pv =  b[ind] - a[i];
            ans.push_back (pv);
           } else {
             cout <<"NO\n"; return;
           }
       }
    }
    //for (auto it :ans) cerr << it <<" " ; cerr <<"\n";
    if (is_sorted (ans.begin () , ans.end ())) cout <<"YES\n";
    else cout <<"NO\n";   
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