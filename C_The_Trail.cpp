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

    int n,m;cin>>n>>m;
    string s;cin>>s;
    int a[n][m];
    for (int i=0 ;i<n ;i++) {
        for (int j=0 ;j<m ;j++)cin>>a[i][j];
    }
    vector <int>r (n) , c(m);

    for (int i=0 ;i<n ;i++) {
        int sm=0 ;
        for (int j=0 ;j <m ;j++) sm+= a[i][j];
        r[i]=sm;
    }
    for (int j=0 ; j<m ;j++) {
        int sm=0;
        for (int i=0 ;i<n ;i++) sm+= a[i][j];
        c[j]= sm;
    }
   
    int x=0 ,y=0 ;
    for (int i=0 ;i< s.size();i++) {
        if (s[i]=='D') {
            int tmp= r[x];
            a[x][y]=-tmp;
            r[x]+= (-tmp);
            c[y]+= (-tmp);
            x++;
        } else {
            int tmp= c[y];
            a[x][y]=-tmp;
            r[x]+= (-tmp);
            c[y]+= (-tmp);
            y++;
        }
    }
    int tmp= r[x];
    a[x][y]=-tmp;

    for (int i=0 ;i<n;i++) {
        for (int j=0 ;j<m ;j++) cout << a[i][j] <<" ";
        cout <<"\n";
    }    
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