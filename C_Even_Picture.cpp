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

void solve() {
    int n;cin>>n;
    vector <pii>ans;
    ans.push_back ({0,1});
    ans.push_back ({0,2});

    for (int i=1 ;i<=n;i++) {
        ans.push_back ({i,i});
        ans.push_back ({i,i+1});
        ans.push_back ({i,i+2});
    }
    ans.push_back ({n+1 ,n+1});
    ans.push_back ({n+1 ,n+2});
    cout << ans.size () <<"\n";
    for (auto it :ans) cout <<it.ff <<" " <<it.ss <<"\n";
    
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
