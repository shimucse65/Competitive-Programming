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

int gcd(int a, int b) {
    while(b > 0) {
        int k = a / b;
        a -= k * b;
        swap(a, b);
    }
    return a;
}

int lcm (int a ,int b) {
    return ( a / gcd(a, b) * b);
}

void solve() {
    int n, m, l, r; 
    scanf ("%d%d%d",&n ,&m ,&l,&r);
    cerr << n<<m <<l <<r ;
    int lc= lcm (n,m);
    l--;
    if (lc > r) {
        printf ("0\n"); 
        return;
    }
    int ans = r / lc - l/lc;
    printf ("%d\n", ans);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1, c = 1; 
    //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}