#include <bits/stdc++.h>
using namespace std;
/*
각 테스트 케이스의 첫째 줄에는 섬의 수 n (1 ≤ n ≤ 75000)이 주어진다.
다음 n개 줄에는 각 섬의 좌표 xi, yi가 주어진다. 두 섬의 좌표가 같은 경우는 없다. (-109 ≤ xi, yi ≤ 109)

4
-10 -10
-10 10
10 -10
10 10
3
1 3
2 2
3 1
*/
vector<pair<int,int>> isl;
vector<int> resultLst;
int m,n,a,b,vis[75000],dp[75000];
int dx[]={1,1,0};
int dy[]={0,1,1};
void init(){
    memset(dp,-1,sizeof(dp));
    while(!isl.empty()){
        isl.pop_back();
    }
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        isl.push_back({a,b});
    }
    
}
int go(int index){
    if(dp[index]!=-1)return dp[index];
    int cx = isl[index].first; int cy = isl[index].second;
    int res=0;
    for(int i=0;i<n;i++){
        int nx = isl[i].first; int ny = isl[i].second;
        if(nx==cx && ny == cy) continue;
        if(nx>=cx && ny <= cy){
            if(vis[i]!=1) {
                vis[i] = 1;
                res+=1;
                go(i);
                vis[i] = -1;
            }
        }
    }
    dp[index]=res;
    return res;
}
int main(){
    cin >> m;

    while(m){
        init();
        for(int i=0;i<n;i++){
            vis[i]=1;
            go(i);
            vis[i]=-1;
        }
        int result =0;
        for(int i=0;i<n;i++){
            result+=dp[i];
        }
        resultLst.push_back(result);
        m--;
    }

    for(int el : resultLst){
        cout << el << endl;
    }
    return 0;
}