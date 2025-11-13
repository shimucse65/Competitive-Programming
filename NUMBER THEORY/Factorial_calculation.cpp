const int N=2e5+10 ;
int fact[N] ;
const int mod=1e9+7 ;

int bigmod(int a, int b)
{
    if(b == 0) return 1;
    int x = bigmod(a, b / 2);
    x = (x * x) % mod;
    if(b & 1) x = (x * a) % mod;
    return x;
}

int inv(int a, int m)
{
    return bigmod(a, mod - 2);
}
 
int nCr(int n, int r)
{
    if(n < r) return 0;
    int x = fact[n], y = (fact[r] * fact[n - r]) % mod;
    int ans = (x * (inv(y, mod))) % mod;
    return ans;
}
 
void calc()
{
    fact[0] = 1;
    for(int i = 1; i < N; i ++) fact[i] = (fact[i - 1] * i) % mod;
}
