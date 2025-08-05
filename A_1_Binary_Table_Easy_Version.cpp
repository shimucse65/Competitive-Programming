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
const int N = 1010;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int a[N][N] ;
vector <pii> aa,bb,cc ;

void check (int x ,int y) {

    vector <pii>v ;
    v.push_back ({x,y});
      v.push_back ({x+1,y});
        v.push_back ({x,y+1});
          v.push_back ({x+1,y+1});
    int cnt=0 ;

    for (auto it :v) {
        int x= it.ff ,y=it.ss ;
        cnt+= a[x][y] ;
    }
    int target ;
    if (cnt &1) target= 0 ;
    else target=1 ;

    for (auto it :v) {
        int x=it.ff ,y=it.ss ;
        if (a[x][y]==target) {
           vector <pii>tmp ;
           for (auto j:v) {
             if (it==j) continue ;
             tmp.push_back (j) ;
           }
           aa.push_back ({tmp[0]}) ; 
           bb.push_back ({tmp[1]}) ; 
           cc.push_back ({tmp[2]}) ; 
        }
        a[x][y]=0;
    }
}

void solve() {

    aa.clear () ; bb.clear () ; cc.clear () ;

    int n,m ;cin>>n>>m ;
    for (int i=1 ;i<=n;i++) {
        string s;cin>>s ;
        for (int j=1 ;j<=m ;j++) {
            a[i][j]= s[j-1]-'0' ;
        }
    }
    for (int i=1 ;i<=n ;i+=2) {
        for (int j=1 ;j<=m ;j+=2) {
            int x=i , y= j ;
            if (i==n) x-- ;
            if (j==m) y-- ;
            check (x,y) ;
        }
    }
    //assert (aa.size ()==bb.size ()==cc.size ());
    int sz=aa.size () ;
    cout <<sz <<"\n" ;
    for (int i=0 ;i<sz ;i++) {
        cout << aa[i].ff <<" " <<aa[i].ss <<" " <<bb[i].ff <<" " <<bb[i].ss <<" " <<cc[i].ff <<" "<<cc[i].ss<<"\n" ;
    }
    cout <<"\n" ;   
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