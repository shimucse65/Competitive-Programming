#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e5 + 10;
const int inf=1e15 + 10 ;
const int mod=1e9+7 ;
#define ff first 
#define ss second 
#define lc (ind<<1) 
#define rc (ind<<1|1) 

int n,q ,a[N] ,seg[4*N];

bool isPrime (int n) {
    if (n<2) return false ;
    for (int i=2 ;i*i<=n ;i++) {
        if (n%i==0) return false ;
    }
    return true ;
}

void build (int ind ,int lo ,int hi) {
    if (lo==hi){
       seg[ind]= a[lo] ;
    } else {
      int mid= (lo+hi)/2 ;
      build (lc ,lo,mid) ;
      build (rc ,mid+1 ,hi) ;
      seg[ind]= seg[lc]+ seg[rc];
    }
}

void update (int ind ,int lo ,int hi ,int i ,int x) {
    if (lo==hi){
        seg[ind]= x ;
    }
    else {
        int mid=(lo+hi)/2 ;
        if (i<=mid) update (lc ,lo,mid ,i,x) ;
        else  update (rc ,mid+1 ,hi ,i,x) ;
        seg[ind]= seg[lc]+ seg[rc];
    }     
}

int query (int ind ,int lo ,int hi ,int l, int r) {
   if (hi <l || lo >r) return 0ll ;
   else if (l <= lo && hi <=r) return seg[ind] ;
   else {
    int mid=(lo+hi)/2 ;
    return query (lc ,lo,mid ,l,r)+ query (rc ,mid+1,hi ,l,r) ;
   }
}

void solve() {

    cin>>n>>q ;
    for (int i=1 ;i<=n;i++) cin>>a[i] ;
    build (1,1,n) ;
    while (q--) {
       int l ,r ;cin>>l>>r ;
       int res= query (1,1,n ,l,r ) ;
       if (isPrime (res)) cout <<"YES\n";
       else cout <<"NO\n" ;
    }
}

signed main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;  cin>>t;
    while (t--)
    {
        solve () ;
    }
   
}

 
 



