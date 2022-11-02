#include <bits/stdc++.h>
using namespace std;

int main(){
    int a , cnt = 0, arr[26] = {0}; 
    string b;

    cin >> a;
    string bufferflash;
    getline(cin,bufferflash);
    cout << '\n';

    for(int i = 0; i<a ; i++){
        getline(cin,b);
        arr[b[0]-'a']++;
    }
    for(int i = 0 ; i<26;i++){
        if(arr[i] >=5){
            cnt ++;
            cout << (char)('a'+i);
        }
    }
    if(cnt==0){
        cout << "PREDAJA" << '\n' ;
    }
    return 0;
}

