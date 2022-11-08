#include <bits/stdc++.h>
using namespace std;

int n , sum1 , sum2 ,res1,res2;
string res1_str,res2_str;
int sc1[48][60];
int sc2[48][60];
// cout << " " << << "\n";
vector<string> split(string input , string delimiter){
    vector<string> ret;
    long long pos;
    string token;

    while((pos=input.find(delimiter)) != string::npos){
        token =  input.substr(0,pos);
        ret.push_back(token);
        input.erase(0,pos+delimiter.length());
    }
    ret.push_back(input);
    return ret;
}
int main(){

    cin >> n;
    for(int i =0;i<n;i++){
        int a;
        string s;

        cin >> a >> s;
        vector<string> hw = split(s,":");

        if(a==1){
            sc1[stoi(hw[0])][stoi(hw[1])]++;
        }
        else if(a==2){
            sc2[stoi(hw[0])][stoi(hw[1])]++;
        }   
    }

    for(int i = 0; i<48;i++){
        for(int j = 0 ;j<60;j++){
            sum1 += sc1[i][j] ;
            sum2 += sc2[i][j] ;
            if(sum1 > sum2){
                res1 ++;
            }
            else if( sum1 < sum2 ){
                res2 ++;
            }
        }
    }
    cout << "\n";
    if(res1/60 < 10 ){
        res1_str = "0";
    }
    res1_str += (to_string(res1/60)+":");
    if(res1%60 < 10 ){
        res1_str += "0";
    }
    res1_str += (to_string(res1%60));

     if(res2/60 < 10 ){
        res2_str = "0";
    }
    res2_str += (to_string(res2/60)+":");
    if(res2%60 < 10 ){
        res2_str += "0";
    }
    res2_str += (to_string(res2%60));

    cout << res1_str << "\n";
    cout << res2_str;

    return 0;
}