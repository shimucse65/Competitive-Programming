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
   int n; cin >>n ;
   vector < pair< int ,string>> v;
   for (int i=0 ;i<n ;i++) {
     string x; cin >>x;
     v.push_back ({x.size(),x});
   }
   sort (v.begin () , v.end ());

  //for (auto it :v) cerr << it.ff << it.ss <<"\n";

   vector <string> vv;
   for (int i=0 ;i<n ;i++) {
     vv.push_back (v[i].ss);
   }
  // for (auto it :vv) cerr << it <<" "<<"\n";

   string pv= vv[0];
   int pvl=vv[0].size();

   for (int i=1 ; i<n ;i++) {
     string cur= vv[i];
     int curl= vv[i].size();
     int f=0;
     for (int j=0 ;j <=curl- pvl; j++) {
        if (cur.substr (j ,pvl)==pv) {
            f=1; break;
        }
     }
     if (f==0) {
        cout << "NO\n"; return;
     }
    pv= cur ; pvl= curl;
   }
   cout << "YES\n";
   for (auto it :vv) cout << it <<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; 
    //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}