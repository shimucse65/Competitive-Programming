#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1010;
const int mod=1e9+7 ;
const int inf=1e15+10 ;
char a[N][N];
int vis[N][N] ;
int n,m ;
int cnt ;
int dx[]= {-1,1,0,0 } ;
int dy[]= {0,0,-1,1} ;

bool isvalid (int x,int y) {
    return x>=0 && x<n && y>=0 && y<m && vis[x][y]==0 && a[x][y]=='.' ;
}

void dfs (int row ,int col) {
    vis[row][col]=1 ;
    for (int i=0;i<4 ;i++) {
        int nr= row + dx[i] ;
        int nc= col + dy[i] ;
        if (isvalid (nr ,nc)) 
        dfs (nr ,nc) ;
    }
}

void solve() {
    cin>>n>>m ;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++) cin>>a[i][j] ;
    }
    cnt=0 ;
    for (int i=0;i<n ;i++){
        for (int j=0;j<m;j++) {
            if (a[i][j]=='.' && !vis[i][j]) {
               
                dfs (i,j) ; cnt++ ;
            }
        }
    }
    cout <<cnt <<"\n" ;
 
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve () ;
    return 0;
}
