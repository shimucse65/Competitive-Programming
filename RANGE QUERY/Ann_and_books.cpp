#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10 ;
int n,k;
int cur ;
int a[N] ,type[N] ,plus[N] ,minus[N];
int fre[3*N] ;

struct query {
    int l,r,ind ;
};

query q [N] ;

void update (int i ,int delta ){
    if (delta==1){
        if (f) {
            cnt+= fre[plus[i]] ;
        }
        else {
            cnt+= fre[minus[i]] ;
        } 
    }
    
}


void solve() {
    
    cin>>n>>k ;
    for (int i=1;i<=n;i++) cin>>type[i] ;
    for (int i=1;i<=n;i++) cin>>a[i] ;
    int m ;cin>>m ;
    for (int i=0 ;i<m ;i++){
        cin>>q[i].l >>q[i].r ; q[i].l-- ;
        q[i].ind=i ;
    }
    
    int msl=0 ,msr= -1 ;
    for (int i=0;i<m;i++){
        int l= q[i].l ,r= q[i].r ,ind= q[i].ind ;
        
        while (msr <r) upd (++ msr ,1) ;
        while (l <msl) upd (--msl ,1) ;
        
        while (r <msr) upd (msr-- ,-1) ;
        while (l>msl) upd (msl++ ,-1) ;
        
        ans[ind]=cur ;
    }
    
    
    for (int i=0;i<m;i++) cout <<ans[i]<<" " ;
   

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
