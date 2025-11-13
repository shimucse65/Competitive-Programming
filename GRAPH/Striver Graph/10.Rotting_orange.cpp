#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define ff first
#define ss second
const int N=1010;
const int inf=1e15+10;
int cnt;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int a[N][N];
int vis[N][N];
int n,m;

bool isValid(int x,int y) {
    return x>=0 && x<n && y>=0 && y<m;
}

void bfs() {
    queue<pair<pair<int, int>, int>> q; // {{row, col}, time}

    
    int tm = 0;
    cnt = 0; 

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] == 2) {
                q.push({{i, j}, tm});
                vis[i][j] = 2;
            }
        }
    }


    while (!q.empty()) {
        int row = q.front().ff.ff;
        int col = q.front().ff.ss;
        int tim = q.front().ss;
        q.pop();
        cnt = max(cnt, tim);

        for (int i=0; i<4; i++) {
            int newr = row + dx[i];
            int newc = col + dy[i];

            if (isValid(newr, newc) && vis[newr][newc] != 2 && a[newr][newc] == 1) {
                q.push({{newr, newc}, tim + 1});
                vis[newr][newc] = 2;
            }
        }
    }


    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] == 1 && vis[i][j] != 2) {
                cnt = -1; 
                return;
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
            vis[i][j] = 0; 
        }
    } 

    bfs();
    cout << cnt << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}
