import math 
def build (ind ,lo, hi):
    if (lo==hi):
        seg[ind]=lo 
    else:
        mid= (lo+hi)//2
        build (2*ind ,lo,mid)
        build (2*ind+1 , mid+1 ,hi) 
        seg[ind]= math.gcd (seg[2*ind] ,seg[2*ind+1])  


def query (ind ,lo,hi,l,r) :
    if (hi <l or lo>r) :
        return 0 
    if (l<=lo and hi <=r) :
        return seg[ind] 
    mid=(lo+hi)//2 
    return  math.gcd(query (2*ind , lo,mid ,l,r) , query (2*ind+1 ,mid+1,hi ,l,r))

def solve () :
    n,q= map (int ,input ().split())
    b= list (map (int ,input().split()))
    global a
    a=[0]* (n+1)
    for i in range (1,n) :
        a[i]= abs (b[i]-b[i-1])
    global seg 
    seg=[0]* (4*n)
    build (1,1,n-1)
    for i in range (q) :
        l,r= map (int , input().split())
        if (l==r) :
            print (0 ,end=" ")
        else :
            print (query (1,1,n-1,l,r-1) , end=" ")   

    print ()

def main () :
    t= int (input ()) 
    for i in range (t) :
        solve () 

if __name__ == "__main__":
    main()



