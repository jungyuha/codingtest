#include <bits/stdc++.h>
#include <string>
using namespace std;
/*
첫째 줄에 세준이의 비밀번호의 길이 (자물쇠의 크기) N이 주어진다. N은 100보다 작거나 같다. 둘째 줄에 현재 자물쇠의 상태가 주어지고, 셋째 줄에 세준이의 비밀번호가 주어진다.
*/
int n;
string pwd ;
char temp[110],str_[110];
map<string,int> dp;
void init(){
    //cin >> n;
    // cin >> str_; cin >> pwd;
    string s1 = "12345";
    cout << s1[0] <<endl;
    int n=s1[0]-'0';
    n+=3;
    cout << char(n+'0') << endl;
    s1[0]=char(n+'0');
    cout << s1 << endl;
}
int total_go(string s1,int r,string type){
    if(dp[s1]) return dp[s1];
    if(s1==pwd) return r;
    if(s1=="3456") cout << "go:"<<r<<","<< s1<< ","<<type<<endl;
    if(type=="T"){
        if(r+3>n) return 987654321;
        int res = 987654321;
        for(int i=1;i<10;i++){
            string s2 = s1;
            for(int j=0;j<3;j++){
                int nn=s2[r+j]-'0';
                nn+=i;
                if(nn<0) {nn+=10;}
                else if(nn>9){nn%=(10);}
                s2[r+j]=char(nn+'0');
            }
            // 여기서 호출
            // dp[s1]=res;
            //if(s2==pwd) return r+1;
            cout << s2 << endl;
            res = min(total_go(s2,r+1,"T"),total_go(s2,r,"U"));
        }  
        dp[s1]=res;
        return res; 
    }
    else if(type=="U"){
        if(r >= n) return 987654321;
        int res = 987654321;
        for(int i=-3;i<=3;i++){
            string s2 = s1;
            int k=s2[r]-'0';
            k+=i;
            if(k<0) {k+=10;}
            else if(k>9){k%=(10);}
            s2[r]=char(k+'0');
            //여기서 호출
            res = min(total_go(s2,r,"T"),total_go(s2,r+1,"U"));
            //dp[s1]=res;
            cout << s2 << endl;
        }
        dp[s1]=res;
        return res;          
    }
 
}
// int three_go(string s1,int r){
//     if(r+3>n) return 0;
//     if(dp[s1]) return dp[s1];
//     int res = 987654321;
//     for(int i=1;i<10;i++){
//         string s2 = s1;
//         for(int j=0;j<3;j++){
//             int nn=s2[r+j]-'0';
//             nn+=i;
//             if(nn<0) {nn+=10;}
//             else if(nn>9){nn%=(10);}
//             s2[r+j]=char(nn+'0');
//         }
//         // 여기서 호출
//         // dp[s1]=res;
//         //if(s2==pwd) return r+1;
//         cout << s2 << endl;
//         res = min(three_go(s2,r+1)+1,unit_go(s2,r)+1);
//     }  
//     dp[s1]=res;
//     return res;  
// }
// int unit_go(string s1,int r){
//     if(r >= n) return 0;
//     if(dp[s1]) return dp[s1];
//     int res = 987654321;
//     for(int i=-3;i<=3;i++){
//         string s2 = s1;
//         int k=s2[r]-'0';
//         k+=i;
//         if(k<0) {k+=10;}
//         else if(k>9){k%=(10);}
//         s2[r]=char(k+'0');
//         //여기서 호출
//         res = min(unit_go(s2,r+1)+1,three_go(s2,r)+1);
//         //dp[s1]=res;
//         cout << s2 << endl;
//     }
//     return 1;  
// }
int go(string s1,int r){

    return 0;
}
int main(){
    //init();
    n=4;
    //cout << three_go("1234",0) << endl;;
    pwd = "3456";
    cout << total_go("1234",0,"T") << endl;
    return 0;
}