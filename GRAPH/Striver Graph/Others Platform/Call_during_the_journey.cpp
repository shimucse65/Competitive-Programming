#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e5+10 ;
const int inf= 1e15+10 ;
int t,t1 ,t2 ;
int n,m;
vector < vector <int> > g[N];


bool canTake (int l ,int r) {
    return  (t2 <= l || t1 >=r)  ;
}

int dij (int mid ) {
    vector <int> dis (n+1 ,inf) ;
    set < vector <int> >st ;
    st.insert ({mid ,1}) ; // time ,node 
    dis[1]= mid ;
    
    while (st.size ()) {
        auto node= *(st.begin()) ;
        st.erase (st.begin ()) ;
        int  wt= node[0] , vertex= node[1] ;
        
        for (auto it : g[vertex]) {
            int child= it[0] ;
            int bus= it[1] ;
            int walk= it[2] ;
            
            int mn=inf ;
            
            if (wt+ walk <mn) mn= wt+walk ;
            
            if (canTake (wt ,wt+bus)) {
                if (wt+bus <mn) mn= wt+bus ;
            }
            else {
                if (t2+ bus <mn) mn= t2+bus ;
            }
            
            if(mn < dis[child]) {
                    if(dis[child] != inf) st.erase({dis[child], child});
                    dis[child] = mn;
                    st.insert({dis[child], child});
                }

        }
    }
    return dis[n] ;
}

void solve() { 
    cin>>n>>m ;
   cin>>t>>t1>>t2 ;
   
   
  for (int i=0;i<= n ;i++) g[i].clear ();
   
   for (int i=0;i<m;i++) {
       int u,v,l1,l2 ;cin>>u>>v>>l1>>l2 ;
       g[u].push_back ({v,l1,l2}) ;
       g[v].push_back ({u ,l1 ,l2}) ;
   }
   
   int ans=-1 ;
   int l=0 ,r=1e9 ;
   while (l<=r) {
       int mid= (l+r)/2 ;
       if (dij (mid ) <= t) {
           ans=mid ;l=mid+1 ;
       }
       else r=mid-1 ;
   }
   cout<<ans <<"\n" ;

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t;cin>>t ;
    while (t--)
    {
        solve();
        
    }
    return 0;
}
