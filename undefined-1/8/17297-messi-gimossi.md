# 17297(Messi Gimossi)

#### **first Registered : 2023-3-8**

#### last modified : **2023-3-8**

## **\[0] 접근 방법을 체계화 하자**

## \[1] 이론

### (1) 경우의 수의 숫자 범위를 먼저 체크해야한다.

* 이 문제는 문자열로 풀면 안된다.

### (2) 완전 탐색의 패턴을 체계화 한다.(완전 탐색의 패턴에서 식을 만들어 나간다.)

* 문자열이 만들어 지는 완전 탐색 패턴 경우의 수(문자의 갯수를 f(a)'라고 가정)
  * f(a) = f(a-1) + f(a-2)

### (4) 표현 방법을 간소화한다.

* 문자열을 간단하게 숫자로 치환하여 처리한다.

### (5) 경우의 수를 모두 만든 후 시작한다.

## \[2] 코드

### dp 완전탐색 코드

```cpp
#include <bits/stdc++.h>
using namespace std;

map<int,int> dp;
string ans[3];
int m;
string go(int n,int k){
    string res;
    //cout << n << "," <<k<<endl;
    if(n==0 || n==1){
        res = ans[n][k-1];
        return res;
    }
    if(k<=dp[n-1]){
        res = go(n-1,k);
    }
    else if(k==dp[n-1]+1){
        res="Messi Messi Gimossi";
    }
    else {
        res = go(n-2,k-dp[n-1]-1);
    }
    return res;
}
int main(){
    dp[0]=7; ans[0]="Gimossi";
    dp[1]=5; ans[1]="Messi";

    cin >> m;

    int n=2;
    while(1){
        dp[n]=dp[n-1]+1+dp[n-2];
        if(dp[n]>=m) break;
        n++;
    }
    cout << go(n,m)<<endl;
    
    return 0;
}
/*
messi(1): Messi
messi(2)​​: Messi Gimossi
*/
```
