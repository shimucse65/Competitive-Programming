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

void push(deque<int> &dq, int x) {
    while(!dq.empty() && dq.back() > x) dq.pop_back();
    dq.push_back(x);
}

void pop(deque<int> &dq, int x) {
    if(!dq.empty() && x == dq.front()) dq.pop_front();
    // eta check korar reason hocche hote pare v[i - k] agei remove
    //hoye gese abar remove korte hobe na 
}

void solve() {
    int n, k; cin >> n >> k;
    int x, a, b, c; cin >> x >> a >> b >> c;
    vector<int> v(n);
    v[0] = x;
    for(int i = 1; i <= n - 1; i++) {
        v[i] = (v[i - 1] * a + b) % c;
    }
    deque<int> dq;
    for(int i = 0; i < k; i++) {
        push(dq, v[i]);
    }
    int xr = dq.front();
    for(int i = k; i < n; i++) {
        pop(dq, v[i - k]);
        push(dq, v[i]);
        xr ^= dq.front();
    }
    cout << xr << "\n";
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