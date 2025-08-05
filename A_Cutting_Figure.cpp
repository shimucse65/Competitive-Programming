    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>
    using namespace __gnu_pbds;
    template <typename T> using o_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
    #define int long long
    #define endl '\n'
    #define ff first
    #define ss second
    #define pii pair<int, int>
    using namespace std;
    const int mod = 1e9 + 7;
    const int N = 70;
    const int inf = 1e18 + 10;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n,m ,vis ,mark[N][N] ;
    char s[N][N];
    int dx[]= {-1,1,0,0} , dy[]= {0,0,-1,1};

    void dfs (int x ,int y) {
        if (x <0 || y<0 || x>=n || y>=m) return ;
        mark[x][y]=vis ;
        //cerr << x <<" " << y <<"\n" ;
        for (int i=0 ;i<4 ;i++) {
            int nwx= x+ dx[i];
            int nwy= y+dy[i];
            if (s[nwx][nwy]=='.' || mark [nwx][nwy]==vis) continue ;
            dfs (nwx ,nwy);
        }
    }
    void solve() {
        cin>>n>>m ;
        int h=0 ;
        for (int i=0 ;i<n;i++) {
            for (int j=0 ;j<m ;j++) {
                cin>>s[i][j] ;
                if (s[i][j]=='#') h++ ;
            }
        }
        if (h<3) {
            cout<<-1 <<"\n" ; return ;
        }
        int ffx =-1,ffy=-1 ,ssx ,ssy ;
        for (int i=0 ;i<n ;i++) {
            for (int j=0 ;j<m ;j++) {
                if (s[i][j]=='#') {
                    if (ffx==-1 && ffy==-1) {
                        ffx=i ; ffy=j ;
                    } else ssx=i ,ssy=j ;
                }
            }
        }
    // cerr << ffx <<" " << ffy <<" " <<ssx <<" " <<ssy <<"\n" ;
        for (int i=0 ;i<n ;i++) {
            for (int j=0 ;j<m ;j++) {

                if (s[i][j]=='.') continue ;
                s[i][j]='.';
                vis++ ;
                if (i==ffx && j== ffy) dfs (ssx ,ssy) ;
                else dfs (ffx ,ffy) ;

                for (int ii=0 ;ii<n ;ii++) {
                    for (int jj=0 ;jj<m ;jj++) {
                        if (s[ii][jj]=='#' && mark[ii][jj] != vis) {
                            cout <<1 <<"\n" ; return ;
                        }
                    }
                }
                s[i][j]='#' ;

            }
        }
        cout <<2 <<"\n" ;
        
    }

    signed main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int t = 1, c = 1; //cin>>t;
        while(t--) {
            // cerr<<"Case "<<c++<<": \n";
            solve();
        }
    }