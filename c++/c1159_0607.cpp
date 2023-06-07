// 제출 : https://www.acmicpc.net/source/61829527
#include <bits/stdc++.h>
using namespace std;

int al[30];
vector<char> res;
int a;
void init(){
    cin >> a;
    string str;
    for(int i=0;i<a;i++){
        cin >> str;
        al[(int)(str[0]-'a')]++;
    }
}

int main(){
    init();
    for(int i=0;i<30;i++){
        if(al[i]>=5){
            res.push_back((char)(i+'a'));
        }
    }
    if(res.size()>0){
        sort(res.begin(),res.end());
        for(char ch : res){
            cout << ch ;
        }
    }
    else{
        cout << "PREDAJA" ;
    }
    return 0;
}
