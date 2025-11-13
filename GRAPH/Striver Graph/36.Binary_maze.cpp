#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e5+10;
const int inf= 1e15 ;
int par[N] ;
int n,m ;
vector <int>v ;
vector <vector<int> > a ;
pair <int ,int> src ,des ;


bool isValid (int x ,int y) {
    return x>=0 && x<n && y>=0 && y<n ;
}

int dij (pair <int,int>src ,pair <int,int>des) {

   vector <vector <int > > dist (n+1 ,vector <int> (m+1 ,inf)) ;
   set < pair< int ,pair<int ,int>  > >st ; //dis ,cell 
   st.insert ({0 ,{src.first ,src.second}}) ;

   dist [src.first][src.second] = 0 ;

   while (st.size ()) {
     auto node= *st.begin () ;
     st.erase (st.begin()) ;
     int d1= node.first ;
     int row= node.second.first ;
     int col= node.second.second ;

     int dx[]= {-1 ,1,0,0} ;
     int dy[]= {0 ,0 ,-1 ,1} ;

     for (int i=0;i<4 ;i++) {
        int newr= row+ dx[i] ;
        int newc= col+ dy[i] ;
        if (isValid (newr ,newc) && a[newr][newc]) {
            if (d1+1 < dist[newr][newc]) {
                dist[newr][newc]= d1+1 ; 
                if (des.first==newr && des.second==newc) return dist[newr][newc] ;
                st.insert ({dist[newr][newc] , {newr ,newc}}) ;
            }
        }
     }
   }
return -1 ;

}


void solve() {
    int n,m;cin>>n>>m ;
    
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) cin>>a[i][j] ;
    }
    cin>> src.first >> src.second >> des.first >>des.second ;

    cout<<dij (src ,des) ;

}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
