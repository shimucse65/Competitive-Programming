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

int n;

int inv(vector<int> &v) {
    o_set<pii> st;
    int cnt = 0;
    for(int i = n; i >= 1; i--) {
        cnt += st.order_of_key({v[i], inf});
        st.insert({v[i], i});
    }
    return cnt;
}

void solve() {
    cin >> n;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) cin >> v[i];
    cout << inv(v) << "\n";
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