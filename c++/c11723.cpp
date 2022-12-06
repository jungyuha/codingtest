#include <bits/stdc++.h>
using namespace std;

int a,res,p;
int k , num;
string s;
int main(){

    cin >> a;
    for(int i=0;i<a;i++){
        cin >> s ;
        if (s == "add") {
            cin >> p;
            if(!(res&(1 << p))){
                res |= (1 << p);
            }
        }
        else if(s=="remove"){
            cin >> p;
            if(res&(1 << p)){
                res &= ~(1 << p);
            }
        }
        else if(s=="toggle"){
            cin >> p;
            if(res&(1 << p)){
                res &= ~(1 << p);
            }
            else if(!(res&(1 << p))){
                res |= (1 << p);
            }
        }
        else if(s=="all"){
            res = (1<<21)-1;
        }
        else if(s=="empty"){
            res = 0;
        }
        else if(s=="check"){
            cin >> p;
            if(res&(1 << p)){
                num |= (1<<k);
            }
            else{
                num &= ~(1<<k);
            }
            k++;
        }
    }
    for(int i=0;i<k;i++){
        if(num&(1<<i)){cout <<"1"<<"\n";}
        else{cout <<"0"<<"\n";}
    }
    return 0;
}