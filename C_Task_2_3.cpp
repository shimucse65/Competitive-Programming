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
const int N = 1e7 + 10;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
bool vis[N];
int prime[N];
void siv () {
    for (int i = 2 ; i*i <= N ;i++) {
        if (!vis[i]) {
            for (int j=i*i ; j <= N ; j += i) {
                if (!vis[j]) {
                    vis[j]=1 ;
                }
            }
        }
    }
    int cnt=0;
    for (int i=2 ;i<=N ;i++) {
        if (!vis[i]) prime[ cnt++]=i;
    }
}
void solve() {
   int n; cin >>n ;
   int cnt=0 ;
   for (int i=0 ; prime[i] <= n/2 ;i++) {
        if (vis[n-prime[i]]==0) cnt++;
   }
   cout << cnt <<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    siv ();
    int t = 1, c = 1; cin>>t;
    while(t--) {
        cout<<"Case "<<c++<<": ";
        solve();
    }
}