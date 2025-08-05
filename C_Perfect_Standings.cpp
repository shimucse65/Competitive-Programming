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

bool cmp(const pair<int, string>& a, const pair<int, string>& b) {
    if (a.first != b.first) return a.first > b.first;  
    return a.second < b.second;    
}
void solve() {
    int a[5];
    for (int i = 0; i < 5; i++) cin >> a[i];

    vector<pair<int, string>> v;
    string letters = "ABCDE";
   
    for (int mask = 1; mask < (1 << 5); mask++) {  
        int sum = 0;
        string name = "";
        for (int i = 0; i < 5; i++) {
            if (mask & (1 << i)) {
                sum += a[i];
                name += letters[i];
            }
        }
        v.push_back({sum, name});
    }
    sort(v.begin(), v.end(), cmp);
    for (auto it : v) cout << it.second << "\n";
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