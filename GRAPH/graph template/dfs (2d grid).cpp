#include<bits/stdc++.h>
using namespace std;
const int N=1010;
char s[N][N];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int n,m;
int vis[N][N];
bool isvalid (int x,int y)
 {
     if (x<0 || x>=n ||y<0 ||y>=m) return false;
    // if (s[x][y]=='#') return false;
     return true;
      
 }
 void dfs (int x,int y)
  {
      if (s[x][y]=='#') return ;
      vis[x][y]=true;
      for (int i=0;i<4;i++)
       {
           int p=x+dx[i];
           int q=y+dy[i];
           if (!vis[p][q] && isvalid (p,q)) dfs (p,q);
       }
  }
  
  void solve ()
   {
       cin>>n>>m;
       for (int i=0;i<n;i++)
        {
            for (int j=0;j<m;j++) cin>>s[i][j];
        }
        int cnt=0;
        for (int i=0;i<n;i++)
         {
             for (int j=0;j<m;j++)
              {
                  if (s[i][j]=='#') continue;
                  if (!vis[i][j] && isvalid(i,j));
                   {
                      
                       dfs (i,j) ;cnt++;
                   }
              }
         }
         cout<<cnt<<"\n";
   }
  int main()
   {
       solve ();
   }
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  