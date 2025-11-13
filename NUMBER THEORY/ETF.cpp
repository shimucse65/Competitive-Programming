/*1 theke n porjonto kotogulo number ache jara n er sathe coprime */
//complexity root (n) 

#include<bits/stdc++.h>
using namespace std;

int etf (int n) 
{ 
   int ans=n;
   for (int i=2;i*i<=n;i++)
    {
        while (n%i==0) n/=i;
        ans-= ans/i;
    }
    if (n>1) ans-=ans/n;
    return ans;
}
  int main()
  {
    cout<<etf (10)<<"\n";
    
  } 
  // complexity (nloglogn)
  
  void phi_1_to_n (int n) {
    vector<int> phi(n + 1);
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
  
   
        

