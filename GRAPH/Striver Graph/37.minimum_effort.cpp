#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e5+10;
const int inf= 1e15 ;
int par[N] ;
int n,m ;
vector <vector<int> >a ;
vector <int>v ;

bool isValid (int x,int y) {
    return x>=0 && x<n && y>=0 && y<n ;
}
int dij () {
    vector < vector <int> > dist (n+1 ,vector <int> (m+1 ,inf)) ;
    set < pair <int ,pair <int ,int> > > st ; //dif ,row ,col 
    st.insert ({0 ,{0,0}}) ;
    dist[0][0]=0 ;

    int dx[]= {-1 ,1,0,0} ;
    int dy[]= {0,0,1,-1} ;

    while (st.size()){
         auto  node= *(st.begin ()) ;
         st.erase (st.begin ()) ;
        int dif= node.first ;
        int row= node.second.first ;
        int col= node.second .second ;

        if (row==n-1 && col==m-1) return dist[row][col] ;
        int mx=-1 ;
        for (int i=0;i<3;i++) {
            int newr= row+ dx[i];
            int newc= col+dx[i] ;
            if (isValid (newr ,newc)) {
               int mx= max (mx ,abs (a[newr][newc]- a[row][col]));
               if (mx <dist[newr][newc]) {
                 dist[newr][newc]=mx ;
                 st.insert ({dist[newr][newc] , {newr ,newc}}) ;
               } 
            }

        }


    }

}

void solve() {
   cin>>n>>m ;
   for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) cin>>a[i][j] ;
   }
   cout <<dij () <<"\n" ;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
