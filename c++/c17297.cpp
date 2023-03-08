#include <bits/stdc++.h>
using namespace std;

map<int,int> dp;
string ans[3];
int m;
string go(int n,int k){
    string res;
    //cout << n << "," <<k<<endl;
    if(n==0 || n==1){
        res = ans[n][k-1];
        return res;
    }
    if(k<=dp[n-1]){
        res = go(n-1,k);
    }
    else if(k==dp[n-1]+1){
        res="Messi Messi Gimossi";
    }
    else {
        res = go(n-2,k-dp[n-1]-1);
    }
    return res;
}
int main(){
    dp[0]=7; ans[0]="Gimossi";
    dp[1]=5; ans[1]="Messi";

    cin >> m;

    int n=2;
    while(1){
        dp[n]=dp[n-1]+1+dp[n-2];
        if(dp[n]>=m) break;
        n++;
    }
    cout << go(n,m)<<endl;
    
    return 0;
}
/*
messi(1): Messi
messi(2)​​: Messi Gimossi
*/