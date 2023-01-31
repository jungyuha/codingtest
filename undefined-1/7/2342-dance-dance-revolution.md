# 2342(Dance Dance Revolution)

#### **first Registered : 2023-1-31**

#### last modified : **2023-1-31**

## \[1] 이론

### (1) dp

### (2) dfs

## \[2] 코드

#### 내 코드

```cpp
#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int k=1,n;
vector<int> mp;
int dp[100010][5][5];
int getScore(int pre,int next){
    if(pre==next) return 1;
    if(pre==0) return 2;
    if(abs(next-pre)==2) {return 4;}
    else { return 3; }
}
int go(int idx,int left,int right){
    if(idx==n) return 0;
    if(idx >0 && left==right) return INF;
    if(dp[idx][left][right]>0) return dp[idx][left][right];
    int res = 0;
    res = min(go(idx+1,mp[idx],right)+getScore(left,mp[idx]),go(idx+1,left,mp[idx])+getScore(right,mp[idx]));
    dp[idx][left][right]=res;
    return res;
}
int main(){

    while(k!=0){
        cin >> k;
        mp.push_back(k);
        n++;
    }
    n--;
    cout << go(0,0,0) << endl;
    return 0;
}
```
