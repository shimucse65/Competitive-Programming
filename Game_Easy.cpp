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
    vector <int> a(n + 1), v(n + 1);
    for(int i = 1; i <= n ;i++) cin >> a[i];

    
    sort(a.begin(), a.end(), greater<int>());
    //for(auto it:a) cerr << it << " "; cerr << "\n";
    for (int i = 1 ; i <= n ; i++) v[i] = a[i - 1];
    
    vector <int > ans (n + 1);
    ans[1] = v[1];
    ans[2] = v[2] + v[1];

    for (int i = 3; i <= n ; i++) {
        int op1 = ans[i - 1] + v[i];
        int op2 = ans [i - 2] + (i - 2) + v[i - 1];
        ans [i] = max (op1, op2);
    }

    for(int i = n + 1 ; i <= 2*n ; i++) {
        int tmp = 2*n - 1 - i ;
        vector< int > p( n + 1);
        for (int i = n ; i >= tmp ; i--)   p[i] = 2;
        for(int  i = tmp - 1; i >= 1 ; i--) p[i] = 1;

        for (auto it : p) cerr << it << " "; cerr << "\n";

        // int sm = 0;
        // for (int  j = 1 ; j <= n ; j++) {
        //     if (p[j] == 1) {
        //         sm += v[j];
        //     } else {
        //         sm += v[j] + j -1;
        //     }
        // }
        // ans [i] = sm;
    }

    for (int i = 1 ; i <= n ;i++) cout << ans[i] << " "; cout << "\n";    
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