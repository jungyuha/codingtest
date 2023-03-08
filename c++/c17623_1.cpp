#include <bits/stdc++.h>
using namespace std;

char res[1010];
map<int,string> dp;

string check(string a1 , string a2){
    string res;
    if(a1=="" && a2 ==""){res="";}
    else if(a1==""){res= a2;}
    else if(a1.length() < a2.length()){res= a1;}
    else if(a1.length() > a2.length()){res= a2;}
    else if(a1.length() == a2.length()){
        if(a1>=a2) {res= a2;}
        else{
            res= a1;
        }
    }
    return res;
}
int main(){

    dp[1]="12"; dp[2]="34"; dp[3]="56";
    
    for(int a=1;a<=1000;a++){
        if(a%2==0){ dp[a]=check(dp[a],"1" + dp[a/2] + "2"); }
        if(a%3==0){ dp[a]=check(dp[a],"3" + dp[a/3] + "4"); }
        if(a%5==0){ dp[a]=check(dp[a],"5" + dp[a/5] + "6"); }

        for(int i=1;i<a;i++){
            dp[a]=check(dp[a],dp[a-i]+dp[i]);
        }
    }

    cout << dp[22] << endl;
}