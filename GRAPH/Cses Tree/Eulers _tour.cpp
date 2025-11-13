#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e5+10 ;

vector <int>g[N] ;
int ft[N] ,s[N] ,t[N] ;

int timer=1;
void dfs (int node ,int par) {
    
    s[node]= timer ;
    ft[timer]=node ;
    timer++ ;
    
    for (auto it :g[node]) {   
        if (it!=par) 
        dfs (it ,node) ;     
    }        
      t[node]= timer ;
      ft[timer]=node ;
      timer++ ;             
}
void solve() { 
   
   int n,m;cin>>n>>m ;
   for (int i=0;i<m;i++) {
       int x,y;cin>>x>>y;
       g[x].push_back (y) ;
       g[y].push_back (x) ;
   }
  dfs (1,-1) ;
  for (int i=1 ;i<= 2*n ;i++) cout <<ft [i] <<" "; cout <<"\n" ;

   
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    {
        solve();
        
    }
    return 0;
}
