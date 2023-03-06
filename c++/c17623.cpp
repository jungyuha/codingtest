#include <bits/stdc++.h>
using namespace std;

int res_1=0;
string st1;
vector<pair<int,string>> stack_;
int val_(int strt){
    string curr="";
    //vector<string> stack_;
    int res_=0;
    for(int i=strt;i<st1.length();i++){
        //cout << st1[i] << "";
        curr=st1[i];
        if(curr=="(" || curr=="{" || curr=="[") {stack_.push_back({i,curr});}
        else if(curr == ")") {
            if(stack_.back().second !="("){cout << "불완전"; res_=-1;}
            else if(stack_.back().first==i-1){
                stack_.pop_back();
                res_++;
            }
            else{
                stack_.pop_back();
                res_*=2;
            }
        }
        else if(curr == "}") {
            if(stack_.back().second !="{"){cout << "불완전"; res_=-1;}
            else if(stack_.back().first==i-1){
                stack_.pop_back();
                res_+=2;
            }
            else{
                stack_.pop_back();
                res_*=3;
            }
        }
        else if(curr == "]") {
            if(stack_.back().second !="["){cout << "불완전"; res_=-1;}
            else if(stack_.back().first==i-1){
                stack_.pop_back();
                res_+=3;
                cout << res_ << endl;
            }
            else{
                stack_.pop_back();
                res_*=5;
            }
        }
        // else if(curr=="(" || curr=="[" || curr=="{") {cout << "4 \n";res_+=val_(i,k+1);} //depth ++;
        // 
        // else if(stk == "{" && curr=="}") {cout << "6 \n";res_*=3; return res_;}
        // else if(stk == "[" && curr=="]") {cout << "7 \n";res_*=5; return res_;}
        
        //prev=st1[i];
    }
    cout << endl;
    return res_;
}
int main(){
    st1="[][][]{()}";
    cout << val_(0);
    return 0;
}