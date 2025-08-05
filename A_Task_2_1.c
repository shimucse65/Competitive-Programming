#include <stdio.h>

#define ll long long 
const ll inf = 1e18 + 10;

ll gcd (ll a , ll b) {
    return (b == 0 ? a : gcd(b, a % b));
}

int main () {
    ll n, m, l, r;
    scanf ("%lld%lld%lld%lld", &n , &m ,&l , &r);
    --l;
    ll g = gcd(n,m);
    ll p = n / g;
    ll ans;
    if(m > inf / p) ans = 0;
    else ans = r / (p * m) - l / (p * m);
    printf ("%lld" , ans);
}