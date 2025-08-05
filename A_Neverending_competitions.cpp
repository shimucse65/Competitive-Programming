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

    int n; cin>>n ;
    string s; cin >>s;
   
    vector <string >v;
    for (int i=0;i<n ;i++) {
    string x; cin >>x;
    v.push_back (x);
    }
    map <pair <string, string> , int>mp;
  vector <string >vv;
  set < string >st;
  for (auto it :v) {
     string tmp= it;
     string nn="";
     int id=0;
     for (int i=0 ;i<tmp.size ();i++) {
       if (tmp[i]=='-') {
        id=i ; break;
       }
       nn+= tmp[i];
     }
     //cerr << nn <<"\n";
     string pp="";
     for (int i= id+2 ; i < tmp.size ();i++) {
        pp+= tmp[i];
     }
     mp [{nn,pp}]++;
     
  }
  for (auto it :mp) {
    string xx= it.ff.ff , yy= it.ff.ss;
    if (mp[{yy, xx}] != it.ss) {
        cout << "contest" <<"\n"; return;
    }
  }

  
  cout <<"home" <<"\n";
   
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