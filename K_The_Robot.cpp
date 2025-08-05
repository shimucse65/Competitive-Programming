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
string s ;
bool check (int x,int y) {
    int n=s.size () ;
    int tmpx=0 , tmpy=0 ;
    int nx=0 , ny=0 ;
    for (int i=0 ;i<n ;i++) {
        nx= tmpx , ny=tmpy ;
        if (s[i]=='R')      nx+=1;
        else if (s[i]=='L') nx-=1;
        else if (s[i]=='U') ny+=1 ;
        else if (s[i]=='D') ny-=1;   
        if (nx==x && ny==y) continue ;
        tmpx= nx ; tmpy= ny ;
    }
    return( tmpx==0 && tmpy==0);
}

void solve() {
   
    cin>>s ;
    int curx=0 ,cury=0 ;
    int n=s.size();
    for (int i=0 ;i<n ;i++) {

        char tmp= s[i] ; 
        if (tmp=='R') curx+= 1 ;
        else if (tmp=='L') curx-=1;
        else if (tmp=='U') cury+=1 ;
        else if (tmp=='D') cury-=1; 

        if (check(curx ,cury)) {
            cout << curx <<" " << cury <<"\n" ; return ;
        }

    }
    cout <<0<<" " <<0 <<"\n" ;   
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