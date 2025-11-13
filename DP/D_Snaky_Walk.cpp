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
const int N = 1010;
const int inf = 1e18 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int dx[]={-1,1,0,0};
int dy[]= {0,0,-1,1};
int vis[N][N][2];
int n,m;
bool isValid (int x ,int y , vector <string> &v) {
    return x>=0 && y>=0 && x<n && x<m && v[x][y]!='#';
}

void solve() {

    cin >>n>>m ;
    vector <string> v(n);
    for (int i=0 ;i<n;i++) cin>>v[i];

    int stx ,sty , gx ,gy;
    for(int i=0 ;i<n ;i++) {
        for (int j=0 ;j<m ;j++) {
            if (v[i][j]=='S') {
                stx=i , sty=j;
            } else if (v[i][j]=='G') {
                gx=i , gy=j;
            }
        }
    }
    queue < pair <pii,pii> >q; //stx ,sty , type , step 
   // memset (vis ,0, sizeof vis);
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(2, false)));
    q.push ({ {stx ,sty},{0,0}});
    q.push ({ {stx ,sty},{1,0}});

    vis[stx][sty][0]=1;
    vis[stx][sty][1]=1;

    while (!q.empty()) {
        auto cur= q.front () ; q.pop () ;
        int ssxx= cur.ff.ff;
        int ssyy= cur.ff.ss;
        int ty= cur.ss.ff;
        int ans= cur.ss.ss;

        if (ssxx==gx && ssyy==gy) {
            cout <<ans <<"\n"; return;
        }

        for (int i=0 ;i<4 ;i++) {
            int nwx= ssxx+ dx[i];
            int nwy= ssyy+ dy[i];

            bool ishori= (dx[i]!=0);
            if (ishori != (ty==0)) continue;

            if ( isValid (nwx , nwy ,v) && !vis[nwx][nwy][1 -ty]) {
                vis[nwx][nwy][1-ty]=1 ;
                q.push({{nwx, nwy},{1-ty ,ans+1}});
            }
        }
     }
    cout << -1 <<"\n";
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