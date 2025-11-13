//Climbing stairs :leetcode


#include <bits/stdc++.h>
using namespace std ;
int main () {
    int n;cin>>n ;
    vector <int >dp (n+1 ,-1);
    dp[0]=1 ,dp[1]=1 ;
    for (int i=2 ;i<=n;i++) {
        int one_step=  dp[i-1];
        int two_step=  dp[i-2];
        dp[i]=one_step+two_step ;
    }
   // for (int i=0;i<=n;i++) cout<<dp[i]<<" ";cout<<"\n";
    cout<<dp[n] <<"\n";
}
//TC : O (n) ,SC :O(n)+ O(n)
/*
Input: n = 2
Output: 2

Input: n = 3
Output: 3
*/


