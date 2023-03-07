#include <bits/stdc++.h>
using namespace std;

int res_1=0,pt=0,n,min_;
map<string,int> dp;
const int INF=9999999999;
string st1,min_str;
map<string,string> mp1;
map<char,int> mp2;
vector<pair<int,string>> stack_;
int num_(string st,int gubun){
    if(gubun==0){
        if(st==")"){return 1;}
        else if(st=="}"){return 2;}
        else if(st=="]"){return 3;}
    }
    else if(gubun==1){
        if(st==")"){return 2;}
        else if(st=="}"){return 3;}
        else if(st=="]"){return 5;}
    }
}
int val_(int strt){
    pt=strt;
    if(strt==st1.length()-1) return -1;
    string st_,end_,curr;
    st_=st1[strt];end_=mp1[st_];
    int res_=0; 
    for(int i=strt+1;i<st1.length();i++){
        curr=st1[i];
        if(curr=="(" || curr=="{" || curr =="["){
            res_+=val_(i);
            i=pt;
        }
        else if(curr==end_){
            if(i==strt+1){ res_+=num_(end_,0); }
            else{ res_*=num_(end_,1);}
            pt = i;
            return res_;
        }
    }
    pt = st1.length();
    return -1;
}
int cal_(string c){
    int res=0;
    for(int i=0;i<c.length();i++){
        res=res*10+mp2[c[i]];
    }
    //cout << "cal :: "<<res << endl;
    return res;
}
int make_(string str_){
    if(dp[str_]) return dp[str_];
    //cout << str_ << endl;
    pt=0; int result =0; st1 = str_;
    int res = INF;
    while(pt<st1.length()){
        result += val_(pt);
        pt++;

    }
    if(result < 0) result = INF;
    dp[str_]=result;
    if(result == n){
        if(min_>cal_(str_)){
            min_=cal_(str_);
            min_str = str_;
        }
        //cout << "min_ :: "<<min_ << endl;
    }
    if(result>=n) return INF;
    // 1. str_()
    make_(str_ +"()");
    make_(str_ +"{}");
    make_(str_ +"[]");
    // 2. (str)
    make_("("+ str_ +")");
    make_("{"+ str_ +"}");
    make_("[" +str_ +"]");
    return res;
}
int main(){
    mp1["("]=")";mp1["{"]="}";mp1["["]="]";
    mp2['(']=1;mp2[')']=2;mp2['{']=3;mp2['}']=4;mp2['[']=5;mp2[']']=6;
    min_ = INF;
    cin >> n;

    make_("");
    cout << min_str;
    return 0;
}