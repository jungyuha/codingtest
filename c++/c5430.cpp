#include <bits/stdc++.h>
using namespace std;
int main(){
int tot;
cin >> tot;
vector<string> result;
while(tot){
    string func_str,inp;
    vector<int> mp;
    int num=0,mid=0;
    cin >> func_str >> num >> inp;
    for(char c : inp){
        if(c=='[' || c==']') {continue;}
        else if((int)(c-'0')>=0 && (int)(c-'0') <=9) {
            mid = mid*10 + (int)(c-'0');
        }
        else if(c==','){
            mp.push_back(mid);
            mid=0;
        }
    }
    if(mid>0) mp.push_back(mid);

    int start=0,end=mp.size()-1;
    bool res = true;
    int drc=0; // 앞 :0 , 뒤 :1 => 1->0 , 0->1
    for(char c : func_str){
        if(c=='R'){
            drc &= ~(1<<0);
        }
        else if(c=='D'){
            if(start>end){
                res= false;
                break;
            }
            if(drc==0){
                start ++;
            }
            else if(drc==1){
                end --;
            }
        }
    }
    if(res){
        string temp="";
        temp+="[";
        for(int i=start;i<=end;i++){
            temp += to_string(mp[i]);
            if(i<end) temp += ",";
        }
        temp+="]";
        result.push_back(temp);
    }else{
        result.push_back("error");
    }
    tot--;
}

    for(string el : result ){
        cout << el << "\n";
    }
    return 0;
}