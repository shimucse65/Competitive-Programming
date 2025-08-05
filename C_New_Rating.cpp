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
const int N = 3e5 + 10;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 int n ;
 int a[N] ;



bool check (int a[] ,int n ,int x) {
   
    int pre[n] ; pre[0]=0 ;
    int cur = 1;
    for(int i = 1; i < n; i++) {
        
        if(a[i] > cur) cur += 1;
        else if (a[i] < cur) cur -= 1;
        pre[i]= max(pre[i-1], cur);
    }
    if(pre[n-1] >= x) {
        return true;
    }
    for(int i = n-1; i > 0; i--) {
        if(a[i] >= x) {
            x -= 1;
        } else {
            x += 1;
        }
        if( pre[i-1] >= x) return true;
    }
    return false;

}


void solve() {

    cin>>n ;
    for (int i=0;i<n;i++) cin>>a[i] ;
  
    int l=0 ,r=n ,ans=0 ;
    while (l<=r) {
        int mid=l+ (r-l)/2 ;
        if (check (a,n,mid)) {
            ans = mid ;
            l=mid+1 ;
        } else r= mid-1 ;
    }
    cout <<ans <<"\n" ; 
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