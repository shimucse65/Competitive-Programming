#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10 ;
const int blk=1007 ;
int n,m,k ,a[N] ;
int fre[N] ,pf[N] ,ans[N] ;
int cur ;

struct query {
  int l,r,ind ;  
};

query q [N] ;


void upd (int i ,int delta){
    
    if (delta==1) {
        cur+=fre[ pf[i]^k] ;
        fre[pf[i]]++ ;
    }
    else {
         fre[pf[i]]-- ;
         cur-=fre[ pf[i]^k] ;
    }
}

bool cmp (query a ,query b ){
    if (a.l/blk != b.l/blk) return a.l/blk < b.l/blk ;
    return a.r <b.r ;
}

void solve() {
    cin>>n>>m>>k ;
    for (int i=1;i<=n;i++) cin>>a[i] ;
    pf[0]=0 ;
    for (int i=1 ;i<=n ;i++) pf[i]= pf[i-1]^a[i] ;
    
   for (int i=0;i<m;i++){
       cin>>q[i].l >>q[i].r; -- q[i].l ;
       q[i].ind= i ;
   }
   sort (q,q+m ,cmp) ;
   
   int msl =0 ,msr=-1 ;
   for (int i=0;i<m;i++) { 
       
       int l=q[i].l ,r= q[i].r ,ind= q[i].ind ;
       
       while (msr <r) upd (++ msr ,1) ;
       while (l  < msl) upd (--msl ,1) ;
       
       while (r<msr) upd (msr-- ,-1) ;
       while (msl <l) upd (msl++ ,-1) ;
       
       ans[ind]= cur ;
   }
   
   for (int i=0;i<m ;i++) cout <<ans[i]<<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}

//xenia and favourite number cf 