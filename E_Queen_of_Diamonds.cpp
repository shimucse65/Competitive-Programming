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
const int mod =1000000007;
const int N = 1e6 + 10;
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
    int n; cin >> n;
    string s; cin >> s;
    map <char, int> mp;
    for(auto it : s) mp[it]++;

    vector<int>ans;

    for(auto it : mp) {
        int id = 0;
        if( it.ss & 1) id = 1;
        int cnt =0; 
        for(int i = id;  i <= it.ss; i += 2) {
            cnt += nCr(it.ss, i);
            cnt %= mod;
        }
        ans.push_back(cnt);
    }
   int res = 1 ;
   for (auto it : ans) {
     res = (res * it ) % mod;
   }
   cout << res << "\n"; 
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    calc();
    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}