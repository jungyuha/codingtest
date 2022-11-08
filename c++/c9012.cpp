#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> resList;
int main(){

    cin >> n;

    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        string yn = "M";
        vector<char> strList;
        for(char c : s){
            if(c == '('){
                strList.push_back(c);
            }
            else if(c == ')' && strList.size() > 0){
                strList.pop_back();
            }
            else{
                strList.push_back(c);
                break;
            }
        }
        if(strList.size()>0){
            resList.push_back("NO");
        }
        else{
            resList.push_back("YES");
        }
         
    }
    for(string el : resList){
        cout << el << "\n";
    }
    return 0;
}