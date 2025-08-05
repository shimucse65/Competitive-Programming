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
const int N = 1010;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector <int>g[N];
int deg[N];

void reset (int n) {
    for (int i=1 ; i<=n ;i++){
        g[i].clear ();
        deg[i]=0;
    }
}

void solve() {

    int n ;cin >>n ;
    reset (n);
    int a[n+1][n+1];

    for (int i=1 ; i<=n ;i++) {
        string s ;cin>>s ;
        for (int j=1 ; j <=n ;j++) {
            a[i][j]=( s[j-1]=='1');
        }
    }

    for (int i=1 ; i<=n ;i++) {
        for (int j=i+1 ; j<=n ;j++) {
            if (a[i][j]==1) {
                g[i].push_back (j);
                deg[j]++;
            } else {
                g[j].push_back (i);
                deg[i]++;
            }
        }
    }
 //   for (int i=1 ;i<=n ;i++) cerr << deg[i] <<" "; cerr <<"\n";
    queue <int>q ;
    for (int i=1 ;i<=n ;i++) if (deg[i]==0) q.push (i);


    vector <int>ans ;
    while (!q.empty()) {
        int cur= q.front(); q.pop ();
        ans.push_back (cur);
        for (auto it :g[cur]) {
            deg[it]--;
            if (deg[it]==0) q.push(it);
        }
    }
    for (auto it :ans) cout << it <<" " ; cout <<"\n";   
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