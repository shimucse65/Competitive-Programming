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
    int n; cin >> n;
    int a[n];
    for(int i=0; i < n;i++) cin >> a[i];
    int f=0;
    int ev=0;
    vector<int >odd;
    for(int i=0;i <n ;i++) {
        if (a[i] & 1) f=1;
        if(a[i] % 2 ==0) ev += a[i];
        else odd.push_back(a[i]);
    } 
    int sm =0;
    sort(odd.begin(), odd.end(), greater<int>());

    int cur =0;
    for(int i = 1; i <= (odd.size() + 1)/2 ; i++) sm += odd[cur++];

    if(f==0) {
        cout << 0 << "\n"; return;
    }

    cout << sm + ev << "\n";
    
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