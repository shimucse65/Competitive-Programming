#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1010 ;
int size[N] ,heavy[N] ,parent[N] ,depth[N] ;
int head[N] ,lt[N] ,pos[N] ,idx;
vector<int>g[N];

void reset () {
    for (int i=0;i<N;i++) {
        size[i] =heavy[i]=parent[i]=depth[i]= 0 ;
        head[i] =lt[i] =pos[i] =0 ;
          g[i].clear () ;
    }
  
}

//kon node er heavy child konta seta  selection
void dfs (int node) {
    for (auto child :g[node]) {
        depth[child]= depth[node]+1 ;
        parent[child]= node ;
        dfs (child) ;
        size[node]+= size[child] ;
        if (size[child] > size[heavy[node]] ) {
            heavy[node]= child ;
        }
    }
    size[node]++  ;
}

//kono ekta chain e jara jara ache sobar leader selection 
//head= ultimate parent 
void dfsHLD (int node ,int chain) {

    head[node]= chain ;
    pos[node]=idx ; idx++ ;
    
    //leaf node er heavy 0 
    //leaf node hole call korbo na 
    //otherwise tar heavy child ke call korbo ar bolbo tomar head hocche chain 
    if (heavy[node] !=0) {
        dfsHLD (heavy[node] ,chain) ;
    }

    //baki sobar head first e se nijei ,tara alada chain shuru korbe 
    for (auto it :g[node]) {
        if (heavy[node] !=it) {
            dfsHLD (it ,it) ;
        }
    }
}

int lca (int a ,int b) {
    while (head[a]!=head[b]) {
        //we assume a er leader er depth b er leader er cheye boro 
        if (depth[head[a]] <depth[head[b] ]) {
            swap (a,b) ;
        }
        a= parent[head[a]] ;
    }
    if (depth[a] <depth[b]) swap (a,b) ;
    
    return b ;
}
void solve() { 
    
    reset ();
    int n;cin>>n ;
    for (int i=1 ;i<=n;i++) {
        int m;cin>>m ;
        while (m--) {
            int x ;cin>>x ;
            g[i].push_back (x) ;
        }
    }
    dfs (1) ;
    idx=0 ;
    dfsHLD (1,1) ;
    int q;cin>>q ;
    while (q--) {
        int x,y;cin>>x>>y ;
        cout <<lca (x,y) <<"\n";
    }
  
    
   
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;cin>>t;
    int cs=1 ;
    while (t--){
        cout<<"Case "<<cs++<<":" <<"\n";
        solve () ;
    }
    return 0;
}
