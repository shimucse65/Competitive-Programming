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

    int n ,a,b,k ;cin>>n>>a>>b>>k;
    int ar[n];
    for (int i=0 ;i <n ;i++) cin>>ar[i];
    vector <int>v;
    int tot = a+b;
    for (int i=0 ;i<n ;i++) {
        int tmp = ar[i];
        int last = ((tmp - 1 )/ tot )*tot;
        int baki= tmp-last ;
        int step=( baki + a -1)/ a ; 
        v.push_back (step-1);
    }
    sort (v.begin () ,v.end ());
    int pf[n] ;
    pf[0]= v[0] ;
    for (int i=1 ; i < n ;i++) pf[i]= pf[i-1]+ v[i];
    int ind= upper_bound (pf ,pf+n ,k)-pf -1 ;
    cout << ind + 1 <<"\n";
    
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