#include<bits/stdc++.h>
using namespace std;

string s , ps;
int p,len;
int main(){

    cin >> s >> ps;
    len = ps.size();

    p=s.find(ps);
    while(p!=-1){
        s.replace(p,len,"");
        // (1)
        p = s.find(ps);
    }
    if(s.size()==0){
        cout << "FRULA" <<endl;
    }
    else{
        cout << s <<endl;
    }
    return 0;
}