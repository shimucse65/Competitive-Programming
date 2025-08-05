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
int dp [1010][1010] ;

int f (int i ,int j ,string &a ,string &b ,string &c){
    if (i==a.size ()&& j==b.size ()) return 0 ;
    if (dp[i][j]!=-1) return dp[i][j] ;

    int res= 1e9 ;
    int pos=i+j ;

    if (i<a.size ()) res= min (res , f (i+1 , j , a,b,c)+ (c[pos] != a[i])) ;
    if (j <b.size ()) res= min (res , f (i , j+1 , a,b,c)+( c[pos] != b[j])) ;
    
     return dp[i][j]= res ;
}
void solve() {
    string a,b,c ;cin>>a>>b>>c ;
    for (int i=0;i<1010 ;i++) {
        for (int j=0 ;j<1010 ;j++)  dp[i][j]=-1;
    }
    cout <<f (0,0 ,a,b,c) <<"\n" ;
    
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