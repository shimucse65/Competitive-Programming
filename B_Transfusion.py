
def solve ():
    n= int(input ()) 
    a= list (map (int ,input ().split()))
    sm=sum (a) 
    if (sm%n!=0):
        print ("NO")
        return
    p=sm//n
    odd_sm ,ev_sm=0,0 
    cnt1 ,cnt2=0,0 

    for i in range (n):
        if (i%2==1):
            odd_sm+= a[i] 
            cnt1+=1 
        else :
          ev_sm+= a[i] 
          cnt2+=1 
    if (cnt1 >0 and cnt2 >0 and odd_sm%cnt1==0 and
        ev_sm%cnt2==0 and odd_sm//cnt1==p and
        ev_sm//cnt2==p):
        print ("YES")
    else:
        print ("NO")


def main () :
    t= int(input ())
    for i in range (t):
        solve ()

if __name__ == "__main__":
    main()  
