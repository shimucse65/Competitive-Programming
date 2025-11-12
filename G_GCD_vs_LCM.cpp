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

int vis[N];
vector<int> prime;

void siv() {
    for(int i = 2; i < N; i++) {
        if (!vis[i]) {
            vis[i] = 1;
            prime.push_back(i);
            for (int j = i * i; j < N; j += i) vis[j] = 1; 
        }
    }
}

void solve() {
    int n, l; cin >> n >> l;

    vector<int> ans;
    int mm = 1;

    for (int i = 0 ; i < n ;i++) {
        if ((__int128) mm * prime[i] > l) {
            cout << -1 << "\n"; return;
        }
        mm *= prime[i];
    }

    for(int i = 0; i < n ;i++) {
        ans.push_back (mm / prime[i]);
    }
    for (auto it : ans) cout << it << " "; cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    siv();

    int t = 1, c = 1; cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}