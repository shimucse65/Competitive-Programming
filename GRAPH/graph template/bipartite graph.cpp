#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int mod=998244353;
#define int long long
vector <int>g[N];
int cnt1=0 ,cnt2=0;
int vis[N];
void dfs (int node,int col)
 {
     vis[node]=true ;
     if (col==0) cnt1++ ;
     else cnt2++ ;
     for (auto child :g[node])
      {
          if (!vis[child]) dfs (child ,col^1);
      }
      
 }
 
 void solve ()
  {
      int n;cin>>n;
      for (int i=0;i<n-1;i++)
       {
           int x,y;cin>>x>>y;
           g[x].push_back (y);
           g[y].push_back (x);
       }
       dfs (1,0);
       cout<<cnt1*cnt2- (n-1)<<"\n";
  }



 
  int32_t main() {
    ios_base::sync_with_stdio(
        0); cin.tie(0);
  //  int t;
  //  cin >> t;
    //while(t--) 
     {
         solve ();
     }
}  

     
     
     
     
     
     
     
   
     
     
   

     
     
     
     
     
     
     
     
     
     
     
    
     

     
     
     
     
     
     
     
     
     
     
     
     
     
   
  
 
   
      
      
      
      
      
     
     
   
 


   
   
   
   
   
   
   
   
   
   
   
    
    
    
    
    
    
    
    
     
 
     
 
    
     
     
     
     
     
     
     
     
 
 
