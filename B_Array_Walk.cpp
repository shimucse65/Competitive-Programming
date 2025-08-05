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
const int N = 1e5 + 10;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n,k ,z;
int a[N];
int dp[N][6][2];

void reset (int n) {
    for (int i=0; i<n;i++) a[i]=0;
}

int f (int ind , int k ,int z ,bool back) {
    if (k==0) return 0;
    int &ans= dp[ind][z][back];
    if (~ans) return ans;

    int x=0 ,y=0;
    if (back==0) {
        if (z!=0 && ind!=0) {
            x+= f (ind-1 , k-1 , z-1,1)+ a[ind-1];
        }
    }
  if (ind+1 < n) y += f (ind+1 ,k-1 ,z,0) + a[ind+1];
  return ans= max (x,y);

}

void solve() {
    
    cin >> n >>k >>z;
    reset(n);
    for (int i=0 ;i<n ;i++) cin>>a[i];
    for (int i=0;i<=n ;i++) {
        for (int j=0;j<=5 ;j++) {
            for (int k=0 ;k<2;k++) dp[i][j][k]=-1;
        }
    }
    cout << f (0 ,k,z,0) + a[0] <<"\n";   
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