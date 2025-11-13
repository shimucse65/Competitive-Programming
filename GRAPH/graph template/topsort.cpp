//linear ordering of u-v such that u comes before v 
//DAG :directed acyclic graph 

#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
vector <int>g[N];
bool vis[N];
int indegree[N];
vector <int>ans;
int main()
 {
    //input 
     int n,m;cin>>n>>m;
     for (int i=0;i<m;i++) 
      {
          int u,v;cin>>u>>v;
          g[u].push_back (v);
          indegree[v]++;   
      }
    //minimum priority queue 
      priority_queue <int ,vector <int> ,greater<int> >pq;

     //start from that vertex whose indegree is zero
       for (int i=1;i<=n;i++)
       {
           if (indegree[i]==0) pq.push(i);
       }
       
       while (!pq.empty())
        {
            int cur=pq.top ();
            pq.pop();
            ans.push_back (cur);
            for (auto child :g[cur])
             {
               indegree[child]--; //parent ke pop korar karone child er indegree 1 kome jay 
               if (indegree[child]==0)  pq.push(child);
               
             }
        }
       
       if (ans.size()!=n) cout<<"Sandro fails.\n";
       else
        {
            for (auto it :ans) cout<<it<<" ";
        }
       
       cout<<"\n";

       //reset 
       ans.clear ();
       for (int i=0;i<N;i++)
        {
            vis[i]=0;
            g[i].clear();
            indegree[i]=0;
        }
       
 } 
       
       
       
       
 
