#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ff first
#define ss second
const int N=1010 ;
const int inf= 1e15+10 ;
int vis[N][N] ;
int cnt ;
int a[N][N] ;
int n,m ;
int dx[]= {1,-1,0,0} ;
int dy[]= {0,0,-1,1} ;

bool isValid (int x ,int y){
    return x >=0 && x<n && y>=0 && y<m && a[x][y]==1 ;
}
void dfs (int x ,int y ) {
    vis[x][y]= true ;
    for (int i=0;i<4 ;i++) {
        int newx= x+dx[i] ;
        int newy= y+ dy[i] ;
        
        if (!vis[newx][newy] && isValid (newx ,newy)) {
            dfs (newx ,newy) ;
        }
    }
}
 
void solve() {
    
   cin>>n>>m ;
   for (int i=0;i<n ;i++){
       for (int j=0;j<m;j++) cin>>a[i][j] ;
   }
   
  for (int i=0;i<n;i++){
      for (int j=0;j<m;j++) {
          if (a[i][j]==1 && !vis[i][j]) {
              dfs (i,j) ;cnt++ ;
          }
      }
  }

cout <<cnt <<"\n" ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int t;cin>>t ;
    // while (t--)
    {
        solve();
        
    }
    return 0;
}
