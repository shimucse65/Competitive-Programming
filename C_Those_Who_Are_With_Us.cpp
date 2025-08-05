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
    int n,m; cin >>n >>m ;
    int a[n][m];

    for (int i=0 ;i<n ;i++){
        for (int j=0 ; j<m ;j++) cin >>a[i][j];
    }
     
    vector <int>aa ,bb;

    for (int i=0 ; i < n ;i++) {
        int rsm = 0 ;
        for (int j=0 ; j< m ;j++) {
            rsm += a[i][j];
        }
        aa.push_back (rsm);
    }

       // for (auto it :aa) cerr << it <<" ";cerr <<"\n";
        //for (auto it :bb) cerr << it <<" "; cerr <<"\n";

     for (int j=0 ; j< m ;j++) {
        int csm =0;
        for (int i=0 ; i< n ;i++) {
              csm += a[i][j];

        }
        bb.push_back (csm);
     }
     int mx =-1 ;
     pii ans;
     for (int i=0 ; i< n ;i++) {
        for (int j=0 ; j<m ;j++) {
            int cur = aa[i]+ bb[j]- a[i][j];
            if (cur > mx) {
                mx = cur ;
                ans = {i,j};
            }
        }
     }
   //  cerr << ans.ff <<" " << ans.ss <<"\n";
   int x= ans.ff , y= ans.ss;

   for (int i=0;i<n ;i++) {
    if (i != x) continue;
    for (int j=0 ; j<m ;j++){
        a[i][j]--;
    }
   }
//    for (int i=0;i<n ;i++){
//     for (int j=0;j<m ;j++) cerr << a[i][j] <<" ";
//     cerr <<"\n";
//    }
    for (int i=0;i<n ;i++) {
    if (i == x) continue;
    for (int j=0 ; j<m ;j++){
        if (j!=y)continue;
        a[i][j]--;
    }
   }
    mx =-1 ;
   for (int i=0;i<n ;i++) {
    for (int j=0 ;j<m ;j++){
        mx = max (mx , a[i][j]);
    }
   }
   cout << mx <<"\n";

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