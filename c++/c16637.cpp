#include <bits/stdc++.h>
using namespace std;

int a;
int max_=-99;
vector<int> mp1;
vector<char> cc;

int calc(int a , char b , int c){
    if(b == '-'){
        return a-c;
    }
    else if(b=='+'){
        return a+c;
    }
    else if(b=='*'){
        return a*c;
    }
    else if(b=='/'){
        return a/b;
    }
}
void dfs (int strt,int mid , int cIndex,int lvl){
    // if(lvl == 5) {
    //     cout << lvl << " : dfs >> end  ";
    //     return;
    // }
    cout << lvl << " : dfs >> strt : "<< strt << ", mid : "<<mid<<", cIndex : "<<cIndex<<"\n";
    int new_,res;
    char c;

    new_ = mp1[strt];
    cout << lvl << " 1. new  : "<<new_<<"\n";
    if(cIndex>=0){
        if(cc[cIndex]=='/' && new_ == 0) return;
        res=calc(mid,cc[cIndex],new_);
    }
    else{
        res = new_;
    }
    cout << lvl <<  " 1. res  : "<<res<<"\n";
    cout << lvl <<  " 1. strt+1  : "<<strt+1<<", size :"<<mp1.size()<<"\n";
    if(strt == mp1.size()-1){
        if(res > max_) max_ = res;
        cout << lvl <<  " 1. max  : "<<max_<<"\n";
        return;
    }
    dfs(strt+1,res,cIndex+1,lvl+1);

    if(cc[cIndex+1]=='/' && mp1[strt+1] == 0) return;
    new_ = calc(mp1[strt],cc[cIndex+1],mp1[strt+1]);
    cout << lvl <<  " 2. new  : "<<new_<<"\n";
    if(cIndex>=0){
        if(cc[cIndex]=='/' && new_ == 0) return;
        res=calc(mid,cc[cIndex],new_);
    }
    else{
        res = new_;
    }
    if(strt+1 == mp1.size()-1){
        if(res > max_) max_ = res;
        cout << lvl <<  " 1. max  : "<<max_<<"\n";
        return;
    }
    cout << lvl <<  " 2. res  : "<<res<<"\n";
    dfs(strt+2,res,cIndex+2,lvl+1);
}
int main(){
    cin >> a;
    for(int i=0;i<a;i++){
        char c;
        cin >> c;
        if(c>='0' && c<='9') {mp1.push_back((int)(c-'0'));}
        else{cc.push_back(c);}
    }
    dfs(0,0,-1,0);
    cout << "ans : " << max_ ;
    return 0;
}