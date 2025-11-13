//ax+by=c 
//given a,b print x,y,c 
/*Extended Euclidian Algorithm */

#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll x,y,d;

void  egcd (ll a,ll b)
 {
     if (b==0) 
      {
          x=1;  y=0;   d=a; 
          return ;
      }
      else 
       {
           egcd (b,a%b);
           int  x1= y;
           int  y1= x-(a/b)*y;
           x=x1;
           y=y1;
       }  
 }
int main()
 {
     ll a,b;
     while (cin>>a>>b)
      {
         egcd (a,b);
         cout<<x<<" "<<y<<" "<<d<<"\n";
      }
 }












