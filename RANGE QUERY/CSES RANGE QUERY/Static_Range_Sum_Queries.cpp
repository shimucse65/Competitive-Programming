#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e5 + 10;
const int inf=1e15 + 10 ;
const int mod=1e9+7 ;
#define ff first 
#define ss second 

int pf[N] ;
void solve() {
    
 int n,q;cin>>n>>q ;
 int a[n+1] ;
 for (int i=1 ;i<=n;i++) cin>>a[i] ;

 for (int i=1 ;i<=n;i++) {
    pf[i]= pf[i-1]+a[i] ;
 }
 while (q--){
    int l,r;cin>>l>>r ;
    cout <<pf[r]- pf[l-1]<<"\n" ;
 }

}

signed main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int t;cin>>t;
    // while (t--)
    {
        solve () ;
    }
   
}
    
 
 

