#include <bits/stdc++.h>
using namespace std;

int n ,mp[20][20];
int t,res=99999;
int a[20],b[20];
priority_queue<int,vector<int>,greater<int>> pq;
void func1(int idx,priority_queue<int,vector<int>,greater<int>> q){
    cout << endl;
    if(idx==t){
        for(int i=0;i<n;i++){
            if(a[i]==0) b[i]=1;
        }
        // (2)
        // 차이값 계산
        int tot_a=0;
        for(int i=0;i<n;i++){
            if(a[i] == 0) continue;
            for(int j=0;j<n;j++){
                if(a[j] == 0||i==j) continue;
                    // (3)
                    tot_a+=mp[i][j];
            }
        }
        int tot_b=0;
        for(int i=0;i<n;i++){
            if(b[i] == 0) continue;
            for(int j=0;j<n;j++){
                if(b[j] == 0||i==j) continue;
                    // (3)
                    tot_b+=mp[i][j];
            }
        }
        res=min(res,abs(tot_a-tot_b));
        // (4)
        memset(b,0,sizeof(b));
    }
    while(!q.empty()) {
        int x = q.top();
        a[x]=1;
        q.pop();
        func1(idx+1,q);
        a[x]=0;
    }
}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cin >> mp[i][j];
        }
    }
    t = n/2;
    for(int i=0;i<n;i++){
        pq.push(i);
    }
    func1(0,pq);
    return 0;
}