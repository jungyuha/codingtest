#include <bits/stdc++.h>
using namespace std;
string s;
int a,max_,mid,res;
vector<char> lst;
int main(){
    cin >> a >> s;
    for(char c:s){
        if(c=='('){
            mid++;
            lst.push_back('(');
        }else if(lst.size()>0){
            mid++;
            lst.pop_back();
            if(lst.size()==0){
                res+=mid;
                mid=0;
            }
        }else{
            max_=max(max_,res);
            mid=0;res=0;
        }
    }
    max_=max(max_,res);
    cout << max_ << "\n";
    return 0;
}