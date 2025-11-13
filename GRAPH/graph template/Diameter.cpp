int diameter (vector <int>g[]) {

    for (int i=1 ;i<=num ;i++) dis[i]=-1 ;
    
    queue <int>q ;
    q.push(1) ;
    dis[1]=0 ;
    int mxnode=-1 ;
    while (!q.empty ())  {
        int u= q.front () ; q.pop () ;
        mxnode=u ;
        for (auto it :g[u]) {
           if (dis[it]==-1){
               q.push (it) ;
               dis[it]= dis[u]+1 ;
               
           } 
        }
    }
   
    
    for (int i=1 ;i<=num ;i++) dis[i]=-1 ;
    q.push(mxnode) ;
    dis[mxnode]=0 ;
    
    while (!q.empty ()) {
        int u= q.front () ; q.pop () ;
        mxnode= u;
        for (auto it :g[u]) {
           if (dis[it]==-1){
               q.push (it) ;
               dis[it]= dis[u]+1 ;
            
           } 
        }
    }
     return dis[mxnode] ;
    
}

