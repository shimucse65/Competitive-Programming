#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e5+10 ;

int vis[N] ;
vector <int>g[N];
vector < vector <int> > bridges ;
int low[N] ,in[N] ,size[N] ;
int timer=1 ;

void reset () {
    for (int i=0;i<N;i++) {
       vis[i]= in[i]=low[i]=size[i] =0 ; g[i].clear () ;
    }
    
    bridges.clear () ; timer=1 ;
}
void dfs1(int vertex, int par)
{
    vis[vertex] = true ;
    size[vertex] = 1 ;
    for(auto it: g[vertex])
    {
        if(vis[it]) continue ;
        dfs1(it, vertex) ;
        size[vertex] += size[it] ;
    }
}

void dfs (int node ,int parent) {
        
        vis[node]= 1 ;
        low[node]=in[node]=timer ; timer++ ;
    
        for (auto it :g[node]) {
            
            if (it==parent) continue ;
            if (vis[it]==0) {
                
                dfs (it ,node );
                low[node]=min (low[node] ,low[it]) ;
                
                if (low[it]> in[node]) {
                    bridges.push_back ( {it ,node}) ;
                }
            } 
            else {
                low[node]=min (low[node] ,low[it]) ;
            }
             
        }
        
    }
 
void solve() { 
    
    int n,m;cin>>n>>m ;
    for (int i=0;i<m;i++) {
        int x,y;cin>>x>>y;
        g[x].push_back (y);
        g[y].push_back (x);
    }
    
    dfs1 (1,-1) ;
    memset (vis ,-1 ,sizeof vis);
    
    dfs (1,-1) ;
   
    int ans= n*(n-1)/2 ;
    int mx=0 ;
    for (auto it :bridges) {
        int x= it[1]; 
      
      mx=max (mx ,size[x] *  (n-size[x] )) ; 
    }
   
   cout <<ans-mx <<"\n";
   
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t;cin>>t ;
    while (t--)
    {
        solve();
        reset () ;
    }
    return 0;
}
