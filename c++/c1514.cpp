#include <bits/stdc++.h>
#include <string>
using namespace std;
/*
첫째 줄에 세준이의 비밀번호의 길이 (자물쇠의 크기) N이 주어진다. N은 100보다 작거나 같다. 둘째 줄에 현재 자물쇠의 상태가 주어지고, 셋째 줄에 세준이의 비밀번호가 주어진다.
*/
int n;
string pwd ;
char temp[110],str_[110];
queue<pair<string,int>> q;
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
int go(){
    //cout <<r<<","<< s1 <<","<<pwd<< endl;
    //if(s1==pwd){return r;}
    //if(dp[s1]) return dp[s1]; 
    while(!q.empty()){
        string s1=q.front().first;
        int r = q.front().second;
        //if(r==1) break;
        //cout<<r<<"\n";
        q.pop();
        if(s1==pwd) return r;
        for(int k=0;k<=n-3;k++){
            for(int i=1;i<=10;i++){
                string s2 = s1;
                for(int j=0;j<3;j++){
                    int nn=s2[k+j]-'0';
                    nn+=i;
                    if(nn<0) {nn+=10;}
                    else if(nn>9){nn%=(10);}
                    s2[k+j]=char(nn+'0');
                }
                // 여기서 호출
                // res = min(res,go(s2,r+1));
                // dp[s1]=res;
                //if(s2==pwd) return r+1;
                q.push({s2,r+1});
                cout << s2 << endl;
            }
        }
        // for(int i=-3;i<=3;i++){
        // string s2 = s1;
        // for(int j=0;j<n;j++){
        //     int n=s2[j]-'0';
        //     n+=i;
        //     if(n<0) {n+=10;}
        //     else if(n>9){n%=(10);}
        //     s2[j]=char(n+'0');
        // }
        // // 여기서 호출
        // // res = min(res,go(s2,r+1));
        // // dp[s1]=res;
        // if(s2==pwd) return r+1;
        // q.push({s2,r+1});
        // cout << s2 << endl;
        // }
        for(int j=0;j<n;j++){
            for(int i=-3;i<=3;i++){
                if(i==0) continue;
                string s2 = s1;
                int k=s2[j]-'0';
                k+=i;
                if(k<0) {k+=10;}
                else if(k>9){k%=(10);}
                s2[j]=char(k+'0');
                //여기서 호출
                //res = min(res,go(s2,r+1));
                //if(s2==pwd) return r+1;
                q.push({s2,r+1});
                cout << s2 << endl;
            }
        }   
    }
    //1. 전체 돌리기
    // for(int i=-3;i<=3;i++){
    //     string s2 = s1;
    //     for(int j=0;j<n;j++){
    //         int n=s2[j]-'0';
    //         n+=i;
    //         if(n<0) {n+=10;}
    //         else if(n>9){n%=(10);}
    //         s2[j]=char(n+'0');
    //     }
    //     // 여기서 호출
    //     // res = min(res,go(s2,r+1));
    //     // dp[s1]=res;
    //     q.push({});
    //     cout << res << endl;
    // }
    //2.하나씩 돌리기
    // for(int j=0;j<n;j++){
    //     for(int i=-3;i<=3;i++){
    //         cout << i << endl;
    //         string s2 = s1;
    //         int k=s2[j]-'0';
    //         k+=i;
    //         if(k<0) {k+=10;}
    //         else if(k>9){k%=(10);}
    //         s2[j]=char(k+'0');
    //         //여기서 호출
    //         //res = min(res,go(s2,r+1));
    //         dp[s1]=res;
    //         cout << s2 << endl;
    //     }
    // }
    return 0;
}
int main(){
    //init();
    n=9;
    pwd="567412490";
    q.push({"123456789",0});
    cout << go() << endl;;
    return 0;
}