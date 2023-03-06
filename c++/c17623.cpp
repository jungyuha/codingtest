#include <bits/stdc++.h>
using namespace std;

int res_1=0,pt=0;
const int INF=-1;
string st1;
map<string,string> mp1;
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
    if(strt==st1.length()-1) return INF;
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
    return INF;
}

int main(){
    mp1["("]=")";mp1["{"]="}";mp1["["]="]";
    //st1="[][][]{()}";
    st1="[[[]]]";
    //cout << val_(0);
    pt=0;
    int result =0;
    while(pt<st1.length()){
        result += val_(pt);
        pt++;
    }
    cout << result <<endl;
    return 0;
}