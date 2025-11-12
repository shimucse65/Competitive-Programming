#include<bits/stdc++.h>
using namespace std;
int main(){

    string s="101101";
    string encode="";

    for(int i=0;i<s.size();i++){
        if(s[i]=='1')
            encode+='+';
        else
            encode+='.';
    }

    cout<<encode<<endl;

    string nrz_l="";
     for(int i=0;i<s.size();i++){
        if(s[i]=='1')
            nrz_l+='-';
        else
            nrz_l+='+';
    }

    cout<<nrz_l<<endl;

    string nrz_i="";
    char a='+',b='-';
    for(int i=0;i<s.size();i++){

        if(i==0){
            nrz_i+=a;
        }
        else{
            if(s[i]=='1'){
                if(nrz_i[i-1]==a)
                    nrz_i+=b;
                else
                    nrz_i+=a;
            }
            else{
                if(nrz_i[i-1]==a)
                    nrz_i+=a;
                else
                    nrz_i+=b;
            }
        }
    }
    cout<<nrz_i<<endl;

    string rz="";

    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            rz+='+';
            rz+='.';
        }
        else
        {

            rz+='-';
            rz+='.';
        }
    }
    cout<<rz<<endl;

    string manchester="";

    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            manchester+='+';
            manchester+='-';
        }
        else
        {
            manchester+='-';
            manchester+='+';
        }
    }

    cout<<manchester<<endl;


    string ami="";
    char am='-';

    for(int i=0;i<s.size();i++)
    {

        if(s[i]=='1')
        {
            if(am=='-'){
                ami+='+';
                am='+';
            }
            else
            {
                ami+='-';
                am='-';
            }
        } else
            ami+='.';
    }

    cout<<ami<<endl;


}