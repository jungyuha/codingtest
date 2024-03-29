#include <bits/stdc++.h>
using namespace std;

vector<int> mp[2600];
string str;
queue <pair<int,int>> q;

bool check(int s, int e){
    // aba s=0,e =2 ,size = 3
    if(s>e || s<0 || e>=str.size()) return false;
    bool res= true;
    int ss = s ; int ee = e;
    while(ss<=ee){
        if(str[ss]!=str[ee]) {res = false; break;}
        ss++;ee--;
    }
    return res;
}
int go_bfs(){
    int seq = 1;
    for(int i=0;i<mp[0].size();i++){
        q.push({mp[0][i],seq});
    }

    while(!q.empty()){
        int cur = q.front().first; // 0
        seq = q.front().second; // 1
        q.pop();
        if(cur == str.size()-1) return seq;

        for(int i=0;i<mp[cur+1].size();i++){
            q.push({mp[cur+1][i],seq+1});
        }
    }
    return seq;
}
int main(){
    
    cin >> str;
    for(int i=0;i<str.size();i++){
        // i = 0 -> 00
        // i = 1 ->   01 11
        // i = 2 ->         02 12 22
        for(int j=0;j<=i;j++){
            if(check(j,i)){
                // aba => mp[0]={0,2}, mp[1]={1}, mp[2]={2}
                mp[j].push_back(i);
            }
        }
    }
    // for(int i=0;i<str.size();i++){
    //     cout << "mp["<<i<<"] : ";
    //     for(int el : mp[i]){
    //         cout << el << ",";
    //     }
    //     cout << endl;
    // }
    cout << go_bfs()<<endl;
    return 0;
}