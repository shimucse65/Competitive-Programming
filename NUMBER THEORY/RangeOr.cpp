bool is_set(unsigned int number, int x) {
    return (number >> x) & 1;
}

int RangeOr (int l ,int r){
    int ans=0;
   for (int i=31 ;i>=0 ;i-- ){
       bool x = is_set (l ,i) ;
       bool y=  is_set (r,i) ;
       
       if (x!=y){
           int tmp= (1<<i  );
           int tmp2 =  (1<<i)-1 ;
            ans=  tmp|tmp2 ;break;
       }
       
   }
   return  (l |ans ) ;
}