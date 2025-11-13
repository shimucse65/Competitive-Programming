#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e5+10 ;
const int inf= 1e15+10 ;
int par[N] ,level[N];
vector <int>g[N] ;
int n,q ;
int dp[N][21];

void dfs (int node ,int p) {
    for (auto it :g[node]){
        if (it==p) continue ;
        par[it]=node ;
        level[it]= level[node]+1 ;
        dfs (it,node) ;
    }
}

void build () {
    dfs (1,-1) ;
    memset (dp ,-1 ,sizeof dp) ;
    for (int i=1 ;i<=n;i++) dp[i][0]= par[i] ;
    for (int j=1 ;j<21 ;j++) {
       for (int i=1 ;i<=n;i++){
           if (dp[i][j-1]!=-1){
               dp[i][j]= dp[dp[i][j-1]][j-1] ;
           }
       }
    }
}

int lca (int a,int b) {

    if (level[a] >level[b]) swap (a,b) ;
    int k= level[b]- level[a] ;
    
    for (int i=20 ;i>=0 ;i--) {
        if (k & (1<<i)) {
           b= dp[b][i] ;
        }
    }
    if (a==b) return a ;
    
    for (int i=20 ;i>=0 ;i--) {
        while (dp[a][i]!= dp[b][i]) {
            a= dp[a][i] ;
            b= dp[b][i] ;
        }
    }
    return dp[a][0]  ;
    
} 

void solve() { 
   cin>>n>>q ;
   for (int i=2 ;i<=n;i++){
       int x;cin>>x ;
       g[x].push_back (i) ;
       g[i].push_back (x) ;
   }
   build () ;
   while (q--){
       int a,b;cin>>a>>b ;
       cout <<lca (a,b)<<"\n" ;
   }
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
