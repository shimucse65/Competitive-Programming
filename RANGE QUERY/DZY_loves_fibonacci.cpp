#include <bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize ("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define int long long
#define endl '\n'
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 9;
const int N = 3e5 + 10;
const int INF = 1e15 + 10;
const int BLK = 555;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> fib(N), pf(N);

void solve() {

    //input 
    int n, q; cin>>n>>q;
    vector<int> v(n);
    for(auto &x : v) cin>>x;
    
    //add and substraction 
    auto add = [&] (int a, int b) {
        a += b;
        return a > mod ? a - mod : a;
    };

    auto sub = [&] (int a, int b) {
        a -= b;
        return a < 0 ? a + mod : a;
    };


  //vector<int> v = {10, 20, 30, 40, 50, 60, 70};
//   suppose block size 3 ,
//   then cur[0]={10,20,30 }
//   cur[1]= {40 ,50,60 }
//   cur[2]={70}

    vector<vector<int>> cur(BLK + 10);

    vector<int> sm(BLK + 10);  //sum of values in each block 
//sm[0]= 60 
//sm[1]=150 
// sm[2]=7 

    vector<array<int, 2>> lz(BLK + 10, {0, 0});

    //vector <pair <int,int>>lz[BLK] 
    //lz[i][0]=current value to be added ;
    //lz[i][1]=he Fibonacci number that should be propagated

//blockwise vag and prottek block er sum 
    for(int i = 0; i < n; i++) {
        cur[i / BLK].push_back(v[i]);
        sm[i / BLK] = add(sm[i / BLK], v[i]);
    }

    auto upd = [&] (int l, int r) {

        //notun sqrt array te l er starting index t ar r er ending  index
        //mane l je block e located sei block er starting index 
        int L = l / BLK, R = r / BLK;
        // block er moddhe se asole koi shuru hoise ar koi sesh hoise
        int lb = l % BLK, rb = r % BLK;

        //jodi same block e thake l ar r tahole tader value ekta ekta kore update korbo
        if(L == R) {
            for(int i = lb; i <= rb; i++) {
                //original array tai vag kora ache block akare cur er modddhe 
                //sekhane giye block er index e add korbo f(i-l+1) ke 
                //i-lb ,i-lb+1 noy karon amra add shuru korbo fib[0] theke
                cur[L][i] = add(cur[L][i], fib[i - lb]);
                sm[L] = add(sm[L], fib[i - lb]);
            }
        } 

        //different block
        else {

           // .......[][][]......., L ,L+1 to R-1 ,R
            //case of first... ekta ekta kore update 
            for(int i = lb; i < (int) cur[L].size(); i++) {
                cur[L][i] = add(cur[L][i], fib[i - lb]);
                sm[L] = add(sm[L], fib[i - lb]);
            }
            //kon porjonto add kora sesh hoise 
            //pore tarporer fibo add korbo 
            //koyta element ache left block e
            int tmp = (int) cur[L].size() - lb;
           //tmp-1  porjonto niye nisi 
           //next nibo fibo (tmp ,tmp+1 ,.....tmp+block-1) porjonto 
           //complete block gula handle 
            for(int i = L + 1; i < R; i++) {
                int curSm = sub(pf[tmp + BLK - 1], (tmp - 1 >= 0 ? pf[tmp - 1] : 0LL));
                sm[i] = add(sm[i], curSm);
                //prothom 2 ta update korbo ekhn ,porer gula dorkar hole korbo 
                //na hole rekhe dibo
                cur[i][0] = add(cur[i][0], fib[tmp]);
                cur[i][1] = add(cur[i][1], fib[tmp + 1]);
                lz[i][0] = add(lz[i][0], fib[tmp]);
                lz[i][1] = add(lz[i][1], fib[tmp + 1]);
                tmp += BLK;
            }
           //update R er block 
            for(int i = 0; i <= rb; i++) {
                cur[R][i] = add(cur[R][i], fib[tmp + i]);
                sm[R] = add(sm[R], fib[tmp + i]);
            }
        }
    };

    auto qur = [&] (int l, int r) {
        int L = l / BLK, R = r / BLK, ret = 0;
        int lb = l % BLK, rb = r % BLK;

        if(L == R) {

            //lazy te jodi kisu thake tahole seta niye kaj kora sesh
            //setar value 0 kore dibo 
            int a = lz[L][0], b = lz[L][1];
            lz[L][0] = lz[L][1] = 0;
            //jodi lazy te kisu store thake 
            if(a + b) {
                //2 theke shuru karon 0,1 er value ami age update korsi
                //mone koro a,b mile a+b ..porer iteration e hobe a er value hobe b 
                //ar b er value hobe a+b 
                for(int i = 2; i < (int) cur[L].size(); i++) {
                    cur[L][i] = add(cur[L][i], add(a, b));
                    swap(a, b);
                    //a=b
                     b = add(a, b);
                }
            }
           //block er ekta ekta kore value add korbo
            for(int i = lb; i <= rb; i++) {
                ret = add(ret, cur[L][i]);
            }
        } else {

            //l er block er result jog
            //lazy te kisu thakle setar kaj age korbo 
            int a = lz[L][0], b = lz[L][1];
            lz[L][0] = lz[L][1] = 0;
            if(a + b) {
                for(int i = 2; i < (int) cur[L].size(); i++) {
                    cur[L][i] = add(cur[L][i], add(a, b));
                    swap(a, b);
                    b = add(a, b);
                }
            }
            for(int i = lb; i < (int) cur[L].size(); i++) {
                ret = add(ret, cur[L][i]);
            }
         //L+1 theke R-1 porjonto direct tader sum gula jog korbo result e 
            for(int i = L + 1; i < R; i++) {
                ret = add(ret, sm[i]);
            }



       //R er block theke pawa result 
            a = lz[R][0], b = lz[R][1];
            lz[R][0] = lz[R][1] = 0;
            if(a + b) {
                for(int i = 2; i < (int) cur[R].size(); i++) {
                    cur[R][i] = add(cur[R][i], add(a, b));
                    swap(a, b);
                    b = add(a, b);
                }
            }
            for(int i = 0; i <= rb; i++) {
                ret = add(ret, cur[R][i]);
            }
        }

        return ret;
    };


  //query processsing 
    while(q--) {
        int ty, l, r; cin>>ty>>l>>r;
        --l; --r;
        if(ty == 1) {
            upd(l, r);
        } else {
            cout<<qur(l, r)<<endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


   //fibonacci number calculate  

    fib[0] = fib[1] = 1;
    for(int i = 2; i < N; i++) {
        fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
    }

//fibonaccir prefix sum
    pf[0] = 1;
    for(int i = 1; i < N; i++) {
        pf[i] = (pf[i - 1] + fib[i]) % mod;
    }

    int t = 1, c = 1; //cin>>t;
    while(t--) {
        // cerr<<"Case "<<c++<<": \n";
        solve();
    }
}

/*
i/p: 
o/p: 
*/