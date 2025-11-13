void siv () {
    prime[1]=0 ;
    for (int i=2 ;i<N; i++) {
        prime[i]= prime[i-1];
        if (!vis[i]) {
            prime[i]++;
            for (int j=i*i ;j<N ;j+=i) vis[j]=1 ;
        }
    }
}
