#include <bits/stdc++.h>
using namespace std;

string s1;
string min_;
char res[55];
int cnt,vis[55];
void init(){
    cin >> s1;
    cnt = s1.length();
    min_="";
}
void go(int n){
    if(n==cnt){
        string s2=res;
        char res2[55];
        for(int i=cnt-1;i>=0;i--){
            res2[cnt-i-1]=res[i];
        }
        string s3=res2;
        if(s2==s3){
            if(min_==""){
                min_ = min(s2,s3);
            }
            min_ = min(min_,min(s2,s3)); 
        }
    }
     for(int i=0;i<cnt;i++){
        if(vis[i]==1) continue;
        res[n]=s1[i];
        vis[i]=1;
        go(n+1);
        vis[i]=0;
    }
}
int main(){
    init();
    go(0);
   
   if(min_==""){
        cout << "I'm Sorry Hansoo" << endl;
   }
   else{
        cout << min_ << endl;
   }
   
    return 0;
}