#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e5 + 10;
const int inf=1e15 + 10 ;
const int mod=1e9+7 ;
const int blk=555 ;
#define ff first 
#define ss second 
vector <int>st[N] ; 
int n,m,q;
int a[N] ;
int sm[N] ,bool mark[N] ;
int add[N] , int lazy[N] ;
int cnt[N][blk] ;

void update(int k ,int x) {
    if (st[k].size()>=blk) {
      lazy[k]= x ;
    }
    else {
      for (auto it :st[k]) {
        v[it]+=x ;
        sm[it]+=x ;
      }
    }
    for (int i=0;i<heavy.size();i++) {
        add[heavy[i]]= 1ll *cnt[k][i]*
    }
}

int query (int k) {
    int res=0 ;
   if (st[k].size ()>=blk) {
     res+= sm[i] ;
     res+= add[i] ;
   }
   else {
     for (auto it :st[k]) {
        res+= v[i] ;
     }
     for (int i=0;i<heavy.size();i++) {

     }
   }
   return res ;
}

void solve() {

   cin>>n>>m>>q ;
   for (int i=0;i<n;i++) cin>>a[i] ;

   for (int i=0;i<m;i++){
     int x;cin>>x ;
     if (x>=blk) heavy.push_back (i) ;
     while (x--) {
        int val;cin>>val ;
        st[i].push_back (val) ;
        sm[i]+= val ;
     }
   }

   while (q--) {
     char ty;cin>>ty ;
     if (ty=='?'){
       int k;cin>>k ;k-- ;
       cout<<query (k) <<"\n" ;
     }
     else {
      int k,x;cin>>k>>x ; 
      k-- ;
      update (k,x)<<"\n" ;
     }
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
    
 
 

