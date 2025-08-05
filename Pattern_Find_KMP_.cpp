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

vector <int>buildLPS (string t) {
   vector <int>lps (t.size() ,0) ;
   int i=1 ,ln=0;
   while (i<t.size ()) {
        if (t[i]==t[ln]) {
            ln++ ;
            lps[i]=ln ;
            i++ ;
        } else {
            if (ln!=0) {
                ln= lps[ln-1] ;
            } else {
                lps[i]=0 ;
                i++ ;
            }
        }
   }
   return lps ;
}
vector <int>KMP (string s ,string t) {
    int n= s.size () ,m=t.size () ;
    int i=0 ,j=0 ;
    vector <int>res ;
    vector <int>lps= buildLPS(t) ;
    while (i<s.size ()) {
        if (s[i]==t[j]) {
            i++ ;j++ ;
            if (j==m) {
                res.push_back (i-j) ;
                j= lps[j-1] ;
            }
        } else {
            if (j==0) {
                i++ ;
            } else {
                j= lps[j-1];
            }
        }
    }
    return res ;
}
void solve() {
    string s,t;cin>>s>>t ;
    vector <int>res= KMP (s,t) ;
    if (res.size()==0) {
        cout <<"Not Found"<<"\n" ; return ;
    }
    cout <<res.size ()<<"\n" ;
    for (auto it :res) cout <<it+1 <<" " ;
    cout <<"\n" ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
        cout <<"\n";
    }
}