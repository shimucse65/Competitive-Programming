#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int vis[N];
vector <int>g[N];
void bfs (int s)
 {
     queue <int>q;
     q.push(s);
     vis[s]=true;
     while (!q.empty ())
      {
          int cur=q.front ();
          cout<<cur<<" ";
          q.pop();
          for(auto child :g[cur])
           {
               if(!vis[child])
                {
                    vis[child]=true ;
                    q.push(child);
                }
           }
      }
 }

void solve ()
 {
    int n,e;cin>>n>>e;
    for (int i=0;i<e;i++)
     {
         int x,y;cin>>x>>y;
         g[x].push_back (y);
         g[y].push_back (x);
     }
     bfs (1);
 }
 
 signed main()
  {
     // int t;cin>>t;
     // while (t--)
       {
           solve ();
       }
  }
 
 
 
 
 
 
 
 
 
 