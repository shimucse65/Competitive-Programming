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
    int n ,a,b,c ; cin>> n>>a>>b>>c ;
    
    int aa=a+b+c , bb=a+b ,cc=a ;
    int cnt=0 ;
    if (n>=aa) {
        int x= n/aa ;
        cnt+= x*3 ;
        n= n%aa ;
    }
    // else if (n>=bb) {
    //     int x= n/bb ;
    //     cnt+= x*2 ;
    //     n= n%bb ;
    // }
    // else if (n>=cc) {
    //     int x= n/cc ;
    //     cnt+= x*1 ;
    //     n= n%cc ;
    // }
    if (n>0) {
        cnt++ ; n-= a ;
    }
    if (n>0) {
        cnt++ ; n-=b ;
    }
    if (n>0){
        cnt++ ; n-=c ;
    }
    //cerr <<n <<"\n" ;
    cout <<cnt <<"\n" ;
    
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