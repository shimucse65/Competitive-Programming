#include<bits/stdc++.h>
using namespace std;
#define int  long long 
const int N=2e5+10;
const int mod=1e9+7;
vector<int>g[N];
int par[N];
int level[N];
int table[N][30];
int n;
void reset ()
 {
     for (int i=0;i<N;i++)
      {
          par[i]=0;
          level[i]=0;
          g[i].clear();
      }
 }
 //store parent and level
void dfs (int v,int p=1)
 {
    par[v]=p ;
    for (auto child :g[v])
     {
         if (child==p) continue;
         level[child]=level[v]+1;
         dfs (child ,v);
     }
 }
 void build ()
  {
    dfs (1);
    memset (table ,-1,sizeof(table)) ;
    //direct parent 
    for (int i=1;i<N;i++) table[i][0]=par[i];
    
    for (int i=1;i<N;i++)
    {
        for (int j=1;j<30;j++)
           {
             if (table[i][j-1]!=-1)
               {
                  int x=table[i][j-1];
                   table[i][j]=table[x][j-1];
               }
           }
    }
  }
 


 int lca (int a,int b)
  {
      if (level[a]>level[b]) swap (a,b);
      int d=level[b]-level[a];
      while (d>0)
     {
       int i=log2(d);
       b=table[b][i];
       d-=(1<<i);
     }
     if (a==b) return a;
     for (int i=29;i>=0;i--)
      
      {
          if (table[a][i]!=table[b][i])
           {
               a=table[a][i];
               b=table[b][i];
           }
      }
      return table[a][0];
  }
     
  
 
 
  
  void solve ()
   {
     int n,q;cin>>n>>q;
     for (int i=2;i<=n;i++)
      {
       int u;cin>>u;
       g[u].push_back (i);
       g[i].push_back (u);
      }
     build ();
     
     while (q--)
      {
          int x,y;cin>>x>>y;
        
          cout<<lca (x,y)<<"\n";
      }
      

   }       
         

       
   
 signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // int c=1;
     //int t;cin>>t;
    // while (t--)
      {
          //cout<<"Case "<<c++<<":"<<"\n";
          solve ();
          reset ();
      }
    
}
   

//codeNcode 






   
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  

