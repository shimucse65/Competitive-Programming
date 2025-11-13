#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ff first 
#define ss second 
#define lc (ind<<1) 
#define rc (ind<<1|1) 
const int N = 2e5 + 10;
const int inf=1e15 + 10 ;
const int mod=1e9+7 ;

int a[N] ;
int seg[4*N] ,lz[4*N] ;

void push (int ind ,int lo ,int hi) {
  if (lz[ind]!=0) {
    seg[ind]+= (hi-lo+1)*lz[ind] ;
    if (lo!=hi){
     lz[lc]+= lz[ind] ;
     lz[rc]+= lz[ind] ;
    }
    lz[ind]=0 ;
  }
}

void build (int ind ,int lo ,int hi) {
    if (lo==hi) {
      seg[ind]= a[lo] ;
    } else {
      int mid= (lo+hi)/2 ;
      build (lc ,lo ,mid) ;
      build (rc ,mid+1 ,hi) ;
    }
}

void upd (int ind ,int lo ,int hi ,int l ,int r ,int x) {
   push (ind ,lo ,hi) ;
   if (hi<l |lo >r) return ;
   else if (l <=lo && hi <=r) {
     lz[ind]+=x ;
     push (ind ,lo ,hi) ;
   } else {
     int mid= (lo+hi)/2 ;
     upd (lc ,lo ,mid ,l,r,x) ;
     upd (rc ,mid+1 ,hi ,l,r,x) ;
   }
}

int qur (int ind ,int lo ,int hi ,int pos) {
  push (ind ,lo ,hi) ;
  if (lo==hi) return seg[ind] ;
  int mid=(lo+hi)/2 ;
  if (pos <=mid) return qur (lc ,lo ,mid ,pos) ;
  else return qur (rc ,mid+1 ,hi,pos) ;
}

void solve() {

 int n,q;cin>>n>>q ;
 for (int i=1 ;i<=n;i++) cin>>a[i] ;
 build (1,1,n) ;

  while (q--) {
    int ty;cin>>ty ;
    if (ty==1){
       int l,r,x ;cin>>l>>r>>x ;
       upd (1,1,n ,l,r,x) ;
    } else {
        int k;cin>>k ;
        cout <<qur (1,1,n,k)<<"\n" ;
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
    
 
 


