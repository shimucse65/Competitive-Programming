#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
const int mod=1e9+7 ;
const int inf=1e15+10 ;
int a[N] ;
int n,q ;
int pf[N] ;

 

int pfx_sm (int r ) {
    
    int complete= (r/n)*pf[n] ;
    
    int koyta= r%n ;
    
    int start=(complete+1)%n  ;
    int end = (start+koyta-1)%n ;
    
    if (start<=end) complete+= pf[end]- pf[start-1] ;
    else complete+= pf[n]- pf[start-1]+ pf[end] ;
    
    return complete ;
    
}


void solve() {
  cin>>n>>q ;
  
  
  for (int i=1;i<=n;i++) cin>>a[i] ;
  
   pf[1]=a[1] ;
   for (int i=2 ;i<=n ;i++) pf[i]= pf[i-1]+a[i] ;
  
   while (q--){
      int l,r ;cin>>l>>r ;
      cout <<pfx_sm (r)- pfx_sm (l-1)<<"\n" ;
  }

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int t;cin>>t ;
    while (t--){
        solve ();
    }
    return 0;
}
