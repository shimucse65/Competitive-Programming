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

    int k;cin>>k ;
    string a,b;cin>>a>>b ;
    int n= a.size () ,m=b.size(); 
    int dif =abs (n-m);
    if (dif>=2) {
        cout <<"No\n"; return;
    }
    int i=0 ,j=0 ;
    int f=0 ;
    while (i < n && j < m) {
        if (a[i]==b[j]) i++ ,j++;
        else {
            if (f) {
                cout <<"No\n" ; return;
            }
            if (n > m) i++ ;
            else if (n < m) j++;
            else i++ ,j++;
            f=1;
        }
    } 
    cout <<"Yes\n";
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