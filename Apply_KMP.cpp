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

vector <int> buildLPS (string t) {
  int m= t.size () ;
  vector <int>lps(m);
  lps[0]=0;
  int i=1 ;
  int ln=0 ;
  while (i<m) {
    if (t[i]== t[ln]) {
        ln++ ;
        lps[i]=ln ;
        i++ ;
    } else {
        if (ln==0) {
            lps[i]=0; i++ ;
        } else {
            ln= lps[ln-1] ;
        }
    }
  }
 return lps;

}

int KMP (string s ,string t) {
    
    int n=s.size () ,m= t.size () ;
    int i=0 ,j=0 ,cnt=0 ;
    vector <int>lps = buildLPS (t) ;
    while (i<s.size()) {
        if (s[i]==t[j]) {
            i++ ;j++ ;
            if (j==m) {
                cnt++;
                j= lps[j-1] ;
            }
        } else {
            if (j==0) {
                i++ ;
            } else {
               j=lps[j-1] ; 
            }
        }
    }
    return cnt;
}
void solve() {

    string  t,s ;cin>>t>>s ;
    int res= KMP (s,t) ;
    cout << res <<"\n" ;
    
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