#include <bits/stdc++.h>
using namespace std;

vector<string> res;
int main(){

    while(1){
        string buffer;
        vector<char> vc1;
        vector<char> vc2;
        getline(cin,buffer);
        if(buffer == ".") break;
        for(char c : buffer){
            if(c=='('|| c == '['){
                vc1.push_back(c);
            }
            else if(c == ')'){
                if(vc1.size() > 0 && vc1.back() == '('){
                    vc1.pop_back();
                }
                else{
                    vc1.push_back(c);
                    break;
                }
            }
            else if(c == ']'){
                if(vc1.size() > 0 && vc1.back() == '['){
                    vc1.pop_back();
                }
                else{
                    vc1.push_back(c);
                    break;
                }
            }
        }
        if(vc1.size() > 0){
            res.push_back("no");
        }
        else{
            res.push_back("yes");
        }
    }
    for(string el : res){
        cout << el << "\n";
    }
    
    return 0;
}