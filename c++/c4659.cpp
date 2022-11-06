/*
a
tv
ptoui
bontres
zoggax
wiinq
eep
houctuh
end
*/
#include <bits/stdc++.h>
using namespace std;
vector<string> mp1;
string buffer;
string s;
int main(){
    while(1){
        getline(cin,s);
        if(s=="end") break;
        mp1.push_back(s);
    }
    for(string s1 : mp1){
        
        vector<char> str; // 모음 : 0 , 자음 : 1 , 그 외 : 2
        bool moem = false;
        bool success = true ;
        for(int i = 0 ;i <s1.length();i++){
            if(s1[i]=='a'||s1[i]=='e'||s1[i]=='i'||s1[i]=='o'||s1[i]=='u') {
                str.push_back('0');
            }
            else if(s1[i]>='a' && s1[i]<='z') {
                str.push_back('1');
            }
            else{
                str.push_back('2');
            }
        }
        // cout << "s1 : " << s1 << " : ";
        // for(char el : str){
        //     cout << el ;
        // }
        // cout << "\n";
        for(int i =0 ;i <str.size();i++){
            if(str[i]=='0') moem =true;
            if(i+1 <= str.size()-1 && str[i] == str[i+1] && (str[i]=='a'||str[i]=='i'||str[i]=='u')) success =false;
            if(i+2 <= str.size()-1 && str[i] == str[i+1] && str[i+1] == str[i+2] && (str[i]=='0'||str[i]=='1')) success =false;
            if(success == false) break;
        }
        if(success == true && moem == true ) {cout << "<" << s1<< "> is acceptable.";}
        else {cout << "<" << s1<< "> is not acceptable.";}
    }  

    return 0;
}