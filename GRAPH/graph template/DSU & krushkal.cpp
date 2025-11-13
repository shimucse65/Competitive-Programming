


#include<bits/stdc++.h>
using namespace std;
#define int  long long 
const int N=2e5+10;
const int mod=1e9+7;
int par[N];
int siz [N];
//create new nodes 
void make (int n)
 {
     for (int i=1;i<=n;i++)
      {
          par[i]=i;
          siz[i]=1;
      }
 }
 
 //find root 
 int  find (int n)
  {
      if (par[n]==n) return n;
      return (find (par[n]));
  }
  //merge two nodes 
void merge (int a,int b)
 {
     a=find (a);
     b=find (b);
     if (a==b) return ;
     if (siz[a]<siz[b]) swap (a,b);
      par [b]=a;
      siz[a]+=siz[b];
     
 }
 void solve ()
  {

    //kruskal (for building minimum spanning tree)
    int n,m;cin>>n>>m;
    vector <pair <int ,pair <int,int> >>ed;
    for (int i=0;i<m;i++)
     {
        int u,v,wt;cin>>u>>v>>wt;
        ed.push_back ({wt ,{u,v}});
     }

   sort (ed.begin(),ed.end ());
   for (int i=1;i<=n;i++) make (i);
   int cost=0;
   for (auto it :ed)
    {
        int wt=it.first ;
        int u=it.second.first;
        int v=it.second.second;
        if (find(u)==find(v))  continue;
        
        merge (u,v);
        cost+=wt;
       // cout<<cost;
    }

  cout<<cost<<"\n";

  }
 signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cout<<"Case "<<c++<<": ";
        solve();
    }
}
 



  





  














      
 

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
