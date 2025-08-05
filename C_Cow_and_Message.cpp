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
vector <int>g[N] ;
int ans[26][26] ;
void solve() {
    string s;cin>>s ;
    int n= s.size () ;
    int a[n] ;
    for (int i=0;i<n;i++) {
        a[i]= s[i]-'a' ;
    }
    for (int i=0;i<n ;i++) {
        g[a[i]].push_back (i) ;
    }
    for (int i=0;i<26 ;i++)  {
        for (auto it :g[i]) {
            for (int j=0;j<26 ;j++) {
            int ind= upper_bound (g[j].begin () ,g[j].end () ,it)- g[j].begin () ;
            ans[i][j]+= g[j].size ()-ind ;

        }
        }
    }
    int mx=-1 ;
    for (int i=0;i<26 ;i++) {
        for (int j=0 ;j<26;j++) {
            //cerr <<ans[i][j]<<" " ;
            mx= max (mx ,ans[i][j]) ;
        }
        //cerr <<"\n" ;
    }
    map <int ,int>mp ;
    for (int i=0;i<n;i++) mp[a[i]]++ ;
    
    int mx2=-1 ;
    for (auto it :mp) {
        mx2= max (mx2 ,it.ss) ;
    }
    cout <<max (mx ,mx2) <<"\n" ; 
    
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