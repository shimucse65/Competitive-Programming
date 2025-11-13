#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
const int mod=1e9+7 ;
const int inf=1e15+10 ;
int n,m ;
int a[N] ;
int vis[N] ;
vector <int>g[N] ;
vector <int>g2[N] ;
int dis[N] ,id[N];
int num ;
set <int>duplicate[N] ;



void dfs (int node ,int col) {
    vis[node]=1 ;
    id[node]=col ;
    for(auto it :g[node]){
        if (!vis[it] && a[it]==a[node]){
            dfs (it ,col) ;
        }
    }
}



int diameter (vector <int>g[]) {

    for (int i=1 ;i<=num ;i++) dis[i]=-1 ;
    
    queue <int>q ;
    q.push(1) ;
    dis[1]=0 ;
    int mxnode=-1 ;
    while (!q.empty ()) {
        int u= q.front () ; q.pop () ;
        for (auto it :g[u]) {
           if (dis[it]==-1){
               q.push (it) ;
               dis[it]= dis[u]+1 ;
               mxnode=it ;
           } 
        }
    }
    
    for (int i=1 ;i<=num ;i++) dis[i]=-1 ;
    q.push(mxnode) ;
    dis[mxnode]=0 ;
    
    while (!q.empty ()) {
        int u= q.front () ; q.pop () ;
        for (auto it :g[u]) {
           if (dis[it]==-1){
               q.push (it) ;
               dis[it]= dis[u]+1 ;
            
           } 
        }
    }
    return dis[mxnode] ;
    
}


void solve() {
 int n ;
 for (int i=1 ;i<=n;i++) cin>>a[i] ;
 
 for (int i=0;i<n-1 ;i++){
     int x,y ;cin>>x>>y ;
     g[x].push_back (y) ;
     g[y].push_back (x) ;
 }
 
  num=0 ;
 for (int i=1 ;i<=n ;i++){
     if (!vis[i]) {
         num++ ;
         dfs (i ,num) ;
     }
 }
 
 
 for (int i=1 ;i<=n;i++)  {
     for (auto it :g[i]) {
         if (id[i] != id[it] && !duplicate[id[i]].count (id[it]) ) {
             g2[id[i]].push_back (id[it]) ;
             g2[id[it]].push_back (id[i]) ;
             duplicate[id[i]].insert (id[it]) ;
             duplicate[id[it]].insert (id[i]) ;
         }
     }
 }
 
 int d= diameter (g2) ;
 
 if (n&1) cout <<d/2+1 <<"\n";
 else cout <<d/2<<"\n";
  
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve () ;
    return 0;
}
