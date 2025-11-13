#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e5 + 10;
const int inf=1e15 + 10 ;
const int blk=555 ;
#define ff first 
#define ss second 
vector <string>v ;
int tox[N][12] ,toy[N][12] ;
int n,m,q ;

bool isvalid (int x ,int  y) {
    return x>=1 && x<=n && y>=1 && y<=m ;
}
void update (int l,int r) {

  for (int i=l;i<=r ;i++)  {
    for (int j=1 ;j<=m ;j++) {
      tox[i][j]=-1 ;
      toy[i][j]=-1 ;
    }
  }
  for (int i=l;i<=r ;i++) {
    for (int j=1;j<=m;j++) {
      if (v[i][j]=='^') {
        if (i==l) tox[i][j]= i-1;
        else tox[i][j]= tox[i-1][j] ;
        
        if (i==l) toy[i][j]=j ;
        else toy[i][j]= toy[i-1][j] ;
      }
      else if (v[i][j]=='<') {
        tox[i][j]=tox[i][j-1] ;
        toy[i][j]=toy[i][j-1] ;
      }
    }
    for (int j=m ;j>=1;j--){
       tox[i][j]=tox[i][j+1] ;
        toy[i][j]=toy[i][j+1] ;
    }
  }


}
void solve() {
  cin>>n>>m>>q ;
  for (int i=1 ;i<=n;i++){
      cin>>v[i] ;
      v[i]='.'+v[i] ;
  }

for (int i=0;i<=n+1 ;i++) {
  tox[i][0]=i;
  tox[i][m+1]=i ;
  toy[i][0]= 0 ;
  toy[i][m+1]=m+1 ; 
}

for (int j=0 ;j<=m+1 ;j++) {
  tox[0][j]=0 ;
  tox[n+1][j]=n+1 ;
  toy[0][j]=j ;
  toy[n+1][j]=j ;
}    

  while (m--) {
    char ty;cin>>ty ;
    if (ty=='A') {
      int x,y;cin>>x>>y ;
      while (isvalid (x,y)) {
         int tmp=x ;
         x= tox[tmp][y] ;
         y= toy[tmp][y] ;
      }
      cout <<x<<" "<<y<<"\n" ;
    }
    else {
      int x,y ;cin>>x>>y ;
      char c;cin>>c ;
      v[x][y]=c ;
      int l= max (1ll ,x/blk*blk)  ,r= min (n ,l+blk-1) ;
      update (l,r) ;
    }
  }

}

signed main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;cin>>t;
    while (t--){
        solve () ;
    }
   
}
    
 
 

