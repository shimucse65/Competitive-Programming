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
int fact[N];

int bigmod(int a, int b)
{
    if(b == 0) return 1;
    int x = bigmod(a, b / 2);
    x = (x * x) % mod;
    if(b & 1) x = (x * a) % mod;
    return x;
}

int inv(int a, int m)
{
    return bigmod(a, mod - 2);
}
 
int nCr(int n, int r)
{
    if(n < r) return 0;
    int x = fact[n], y = (fact[r] * fact[n - r]) % mod;
    int ans = (x * (inv(y, mod))) % mod;
    return ans;
}
 
void calc()
{
    fact[0] = 1;
    for(int i = 1; i < N; i ++) fact[i] = (fact[i - 1] * i) % mod;
}

void solve() {
    int n,k ; cin >>n >> k;
    //int tmp= n-1 ;
   // cerr << nCr (5,3) <<"\n";
     for (int i=0 ; i< n ;i++) {
        cerr << nCr (n,i)  <<" ";
     }
     cout <<"\n";
    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    calc ();
    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}