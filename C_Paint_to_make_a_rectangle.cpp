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
const int N =1010;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
char a[N][N] ;
 int n , m;

bool isvalid (int x ,int y) {
    return  x >=0 && y >=0 && x <n && y <m &&  a[x][y]!='.';
}
void solve() {
    cin>>n>>m ;
  
    for (int i=0; i<n ;i++) {
        for (int j=0 ; j<m ;j++) cin>>a[i][j] ;
    }
    int mnr= n , mxr=-1 , mnc= m , mxc=-1 ;

    for (int i=0 ; i< n ;i++) {
        for (int j=0 ; j<m ;j++) {
            if (a[i][j]=='#') {
                mnr= min (mnr , i);
                mxr= max (mxr , i);
                mnc= min (mnc , j);
                mxc= max (mxc , j);
            }
        }
    }

    for (int i=mnr ; i <= mxr ;i++) {
        for (int j= mnc ; j<= mxc ;j++) {
            if (a[i][j]=='.') {
                cout <<"No\n" ; return;
            }
        }
    }

    for (int i=0 ; i< n ;i++) {
        for (int j=0 ;j <m ;j++) {
            if (a[i][j]=='#' && (i <mnr || i >mxr || j <mnc || j>mxc)) {
                cout <<"No\n" ; return;
            }
        }
    }

    cout <<"Yes\n" ;
    
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