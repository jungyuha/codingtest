#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    vector<string> res;
    string s;
    map<string,string> mp1;
    cin >> a >> b;

    for (int i = 1 ;i <= a ;i ++){
        cin >> s;
        mp1[s]=to_string(i);
        mp1[to_string(i)]=s;
    }
    for (int i = 0 ;i < b ;i ++){
        cin >> s;
        res.push_back(mp1[s]);
    }

    for(string el : res){
        cout << el << '\n';
    }
    return 0;
}