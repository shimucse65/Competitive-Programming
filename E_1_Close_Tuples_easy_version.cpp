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
int fact[N] ;

int bigmod (int a ,int b) {
    if (b==0) return 1 ;
    int x= bigmod (a,b/2) ;
    x= (x*x)%mod ;
    if (b&1) x= (x*a)%mod ;
    return x ;
}

int inv (int a ,int m) {
    return bigmod (a ,m-2) ;
}
void calc () {
    fact[0]=fact[1]=1 ;
    for (int i=2 ;i<N;i++) {
        fact[i]= fact[i-1]*i ;
    }
}

int comb (int n ,int r) {
    if (r>n) return 0 ;
    int x= fact [n] ;
    int y= (fact [r] * fact [n-r] )%mod;
    return( x* inv (y,mod)%mod) ;
}

void solve() {
    int n ;cin>>n ;
    int a[n] ;
    for (int i=0;i<n;i++) {
        cin>>a[i] ;
    }
    int ans=0 ;
    sort (a,a+n) ;
    for (int i=n-1 ;i>=2 ;i--) {
        int pos= lower_bound (a,a+n ,a[i]-2)-a ;
        int x= i-pos ;
       // ans+= comb (x,2) ;
       //ans+= (x*(x-1))/2 ;
    }

  
   cout << ans << "\n";   
}
signed main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    calc ();
    int t = 1;  cin>>t;
    while (t--)
    {
        solve () ;
    }
   
}


