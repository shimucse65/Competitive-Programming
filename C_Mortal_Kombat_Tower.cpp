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
int a[N] ;
int dp[N][2] ;
int n ;

int f (int ind , bool who) {

    if (ind>=n) return 0 ;
    if (~ dp[ind][who]) return dp[ind][who] ;

    if (!who) {
        int x=inf ,y=inf ;
         x= f (ind+1 ,1) + a[ind] ;
         y= f (ind+2 ,1) + a[ind]+ a[ind+1] ;
        return dp[ind][who]= min (x,y) ;
    }
    if (who) {
        int x=inf ,y=inf ;
         x= f (ind+1 ,0) ;
         y= f (ind+2 ,0) ;
        return dp[ind][who]= min (x,y) ;
    }
}

void solve() {
    cin>>n ;
    for (int i=0 ;i<n ;i++) {
        cin>> a[i] ;
        dp[i][0]= -1 ;
        dp[i][1] =-1;
    }
    cout << f (0,0) <<"\n" ;    
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