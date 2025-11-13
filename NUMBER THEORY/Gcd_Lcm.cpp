#include<bits/stdc++.h>
using namespace std;
int gcd (int a,int b)
 {
    if (b==0) return a;
    return gcd (b, a % b );
 }
 int lcm (int a,int b)
  {
    return (a*b)/gcd (a,b);
  }
  int main()
   {
    cout<<gcd (5,6)<<" "<<lcm (5,6)<<" "<<gcd (15,30)<<" "<<gcd (4,0)<<"\n";
   }