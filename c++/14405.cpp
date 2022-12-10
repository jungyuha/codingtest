#include <bits/stdc++.h>
using namespace std;  
string s;
// "pi", "ka", "chu"
int main() {   
    cin >> s ;
    int index=0;
    bool flag = true;
    for(int i=0;i<s.size();i++){
        if((i<=s.size()-1)&&(s.substr(i,2)=="pi" || s.substr(i,2)=="ka")){
            i+=1;
        }
        else if((i<=s.size()-2)&&(s.substr(i,3)=="chu")){
            i+=2;
        }
        else{
            flag=false;
            break;
        }
    }
    if(flag){cout<<"YES";}
    else{cout << "NO";}
    
    return 0;
} 