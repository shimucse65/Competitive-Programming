#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int mod=1e9+7 ;
#define int long long
char s[3][N];
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int n;
int vis[3][N];
void reset ()
 {
     for (int i=0;i<2;i++)
      {
          for (int j=0;j<n;j++) 
           {
               vis[i][j]=false;
           }
      }
 }
bool isvalid (int x,int y)
 {
     if (x<0 || x>=2||y<0 ||y>=n) return false;

     return true;
      
 }
  void dfs (int x,int y,int f)
  {

      vis[x][y]=true;
      if (f)
       {
           for (int i=0;i<4;i++)
            {
                int p=x+dx[i];
                int q=y+dy[i];
                if (isvalid (p,q) && !vis[p][q]) dfs (p,q,0);
            }
       }
       else 
        {
            int next ;
            if (s[x][y]=='>') next =y+1 ;
            else next=y-1 ;
            if (isvalid (x,next) && !vis[x][next]) dfs (x,next ,1);
            
        }

  }         
        
        
        
        
        
        
        
        



void solve ()
 {
     cin>>n;
     for (int i=0;i<2;i++)
      {
          for (int j=0;j<n;j++) cin>>s[i][j];
      }
    dfs(0,0,1) ;
    if (vis[1][n-1]) cout<<"YES\n";
    else cout<<"NO\n";
    

      
 }
  int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--) 
     {
         solve ();
         reset ();
     }
} 
      
       
        
        
        
        
        
        
        
        
        
         
         
         
         
         
         
         
         
         
         
         
         
    
      
      
      
      
      
      
      
      

         

        

     
        
        
        
        
        
        
       
       
       
       
       
       
       
       
       
       
       

         
        


     
     
     
     
     
     
     
     
     
     
     
   
  
 
   
      
      
      
      
      
     
     
   
 


   
   
   
   
   
   
   
   
   
   
   
    
    
    
    
    
    
    
    
     
 
     
 
    
     
     
     
     
     
     
     
     
 
 