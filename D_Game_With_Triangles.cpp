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

  int n ,m ;cin >>n>>m ;
  int a[n] , b[m];
  for (int i=0 ;i<n ;i++) cin>>a[i];
  for (int i=0 ;i<m ;i++) cin>>b[i];
  sort (a,a+n); sort (b,b+m);

  vector <int>v (1,0) ,vv (1,0);

  int i=0 , j= n-1 ;
  while (i < j) {
    v.push_back (a[j]- a[i]);i++ ; j--;
  }
  i=0 , j=m-1 ;
  while (i < j) {
    vv.push_back (b[j]- b[i]); i++ ;j--;
  }
  
  for (int i=1 ; i < v.size() ;i++) v[i] += v[i-1];
  for (int i=1 ; i < vv.size();i++)  vv[i] += vv[i-1]; 

  vector <int>ans ;

  for (int k=1 ;  ;k++) {
    int l= max (0ll , 2*k-m);
    int r= min (k ,n-k);

    if (l > r) break;

    while (r-l >=3) {
        int mid1 = l + (r-l)/3;
        int mid2=  r - (r-l)/3 ;

       int x= v[mid1] + vv[k- mid1];
       int y= v[mid2] + vv[k- mid2];

       if (x == y) {
             l= mid1 ; 
       } else if (x < y) {
            l= mid1;
       } else {
           r= mid2;
       }
    }

     int res=0 ;
     for (int i=l ; i <= r ;i++) {
        res= max (res ,v[i] + vv[k- i] );
     }
     ans.push_back (res);
  }
  cout << ans.size () <<"\n";
  for (auto it :ans) cout << it <<" " ; cout <<"\n";
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