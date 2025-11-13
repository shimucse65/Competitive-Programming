#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
const int N = 1010;
const int inf = 1e15+10;
int vis[N][N];
int a[N][N];
int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int sr, sc;
int newc;
int initialColor;

bool isValid(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] == initialColor;
}

void dfs(int x, int y) {
    vis[x][y] = true;
    a[x][y] = newc; 
    for (int i = 0; i < 4; i++) {
        int newx = x + dx[i];
        int newy = y + dy[i];
        
        if (isValid(newx, newy) && !vis[newx][newy]) {
            dfs(newx, newy);
        }
    }
}

void solve() {
    cin >> n >> m;
    cin >> sr >> sc >> newc;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    initialColor = a[sr][sc]; 

   
    if (initialColor != newc) {
        dfs(sr, sc);
    }
   
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
