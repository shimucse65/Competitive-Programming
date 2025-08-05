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
int ans[200];
int vis[200];

void solve() {
    int n,k; cin >>n>>k;
    int a[k+1];
    for (int i=1 ; i<=k ;i++) cin >> a[i];

    //for (int i=1 ; i<=k ;i++) cerr << a[i] <<" "; cerr <<"\n";

    for (int i=1 ; i<=k ;i++) {
        if (a[i] != 0) {
            ans [i]= a[i];
            vis[a[i]]++;
        }
        else {
            int mn= inf , id=-1;

            for (int j=1 ; j<=n ;j++) {
                if (vis [j] < mn) {
                    mn = vis[j] ; id=j;
                }
            }
            ans [i]=id ; vis[id]++;
           // cerr << mn <<" " << id <<"\n";
        }
       // for (int i=1 ;i<=k ;i++) cout << ans[i] <<" "; cout <<"\n";  
    }
    for (int i=1 ;i<=k ;i++) cout << ans[i] <<" "; cout <<"\n";
    
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