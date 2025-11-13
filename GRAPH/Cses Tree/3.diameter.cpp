#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
vector <int> g[N];
bool vis[N];
int dis[N];
int n, mx = -1, mxNode = -1;

void reset ()
 {
     for (int i=0;i<= n;i++)
      {
          vis[i]=0;
          dis[i]=0;
      }
 }

void bfs (int a)
 {
     queue<int>q;
     q.push(a);
     vis[a]=1;
     dis[a]=0;
      while (!q.empty())
       {
          int cur=q.front ();
          q.pop();
          if(dis[cur] > mx) {
              mx = dis[cur];
              mxNode = cur;
          }
          for (auto it : g[cur])
           {
               if (!vis[it])
                {
                    q.push(it);
                    vis[it]=1;
                    dis[it]=dis[cur]+ 1;
                }
           }
       }
     
 }
int main()
 {
           cin>>n;
           reset();
           for (int i=0;i<n-1;i++)
            {
                int u,v;cin>>u>>v;
                g[u].push_back(v);
                g[v].push_back(u);
            }
            bfs (1);           
            reset ();
            bfs (mxNode);           
            cout <<mx <<"\n";
            
 }
            
            
            
            
            
            
      
 