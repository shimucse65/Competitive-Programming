#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e5+10;
const int inf= 1e15 ;
int par[N] ;
int n,m ;
vector <vector<int> >g[N] ;
vector <int>v ;


void reset(int n) {
    for (int i = 0; i <=n; i++) {
       g[i].clear () ;
    }
}

int dij () {

    vector <int>dist (n+1 ,inf) ;
    set < vector <int> >st ;
    st.insert ({0 ,1}) ; //wt ,node 
    dist[1]= 0 ;
    par[1]=1 ;

    while (st.size ()) {
        auto  node= *(st.begin()) ;
        st.erase (st.begin ()) ;
        int  dis1= node[0] ,vertex= node[1] ;

        for (auto it :g[vertex]) {
            int child= it[0] , dis2= it[1] ;
            par[child]= vertex ;
            if (dis1+ dis2 < dist[child]) {
                dist[child]=dis1+dis2 ;
                st.insert ({dist[child] ,child}) ;
            }
        }
    }
  return dist[n] ;
  int cur= n ;
  while (par[cur] != cur) {
    v.push_back (cur) ;
    cur= par[cur] ;
  }   
}

void solve() {
    reset(n);
    cin>>n>>m ;
    for (int i=0;i<m;i++) {
        int u,v,wt ;cin>>u>>v>>wt ;
        g[u].push_back ({v,wt}) ;
        g[v].push_back ({u,wt}) ;
    }
  cout <<dij () <<"\n" ;
  for (auto it :v) cout <<it ;
    

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
