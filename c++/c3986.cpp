#include <bits/stdc++.h>
using namespace std;

int a,cnt;
string s1;
vector<string> sLst;
int main(){
    cin >> a;

    for(int i=0;i<a;i++){
        cin >> s1;
        sLst.push_back(s1);
    }
    
    for(string s : sLst){
        vector<char> cLst;
        for(char c : s){
            if(!cLst.empty() && cLst.back()==c){
                cLst.pop_back();
            }
            else{
                cLst.push_back(c);
            }
        }
        if(cLst.size() == 0){
            cnt++;
        }
    }

    cout << cnt << '\n';
    return 0;
}