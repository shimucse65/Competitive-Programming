#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int N=5000007;

int sum[N] ;
bool prime[N];
int P, primes[N];



void generate_primes() {
  prime[0] = prime[1] = false;
  for(int i=2; i<N; i++) prime[i] = true;
  P = 0;
  for(long long i=2; i<N; i++) if(prime[i]){
      for(long long j=i*i; j<N; j+=i) prime[j] = false;
      primes[P++] = i;
  }
}

void  number_of_pf() {
    
    for (int i = 2; i < N; i++) {
        if (prime[i]) { 
            for (int j = i; j < N; j += i) {
                int temp = j;
                while (temp % i == 0) {
                    sum[j]++;
                    temp /= i;
                }
            }
        }
    }

    
    for (int i = 1; i < N; i++) {
        sum[i] += sum[i - 1];
    }
}


void solve() { 
    
   int a,b;cin>>a>>b ;
   cout <<sum[a]- sum[b] <<"\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    generate_primes() ;
    number_of_pf() ;
  
 
    int t;cin>>t ;
    while (t--)
    {
        solve();
        
    }
    return 0;
}
