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

int check (int a , int b) {
    return (a+b)* (a+b);
}
int check2 (int a) {
    return a*a;
}
void solve() {

    int n,m;cin>>n>>m ;
    vector < int>v ,vv;
    int a[n];
    for (int i=0;i<n;i++) cin>>a[i];
    int ex= n-m ;
    ex*=2;
    sort (a,a+n);
     for (int i=0 ; i< ex; i++) v.push_back (a[i]);

    for (int i=ex ; i<n ;i++) vv.push_back (a[i]);

    int sm1=0;
    int i=0 ,j= v.size ()-1 ;
    while (i < j) {
        sm1+= check (v[i] , v[j]); i++ ; j--;
    }

    int sm2=0;
    for (int i=0 ;i<vv.size () ;i++) {
        sm2+= check2 (vv[i]);
    }

    cout << sm1+ sm2 <<"\n";

    
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