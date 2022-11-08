#include <bits/stdc++.h>
using namespace std;

int n,a,b; // b: 대상 숫자  a : n번째가 될 수
int main(){

    cin >> n;
    while(1){
        int cnt6 =0;
        int k = b;
        while(k>0){
            if(k%10 == 6){
                cnt6 ++;
            }
            else{
                cnt6 = 0;
            }
            if(cnt6 == 3) a++;
            k = k/10;
        }
        if(a == n){
            cout << b << "\n";
            break;
        }
        b++;
    }

    return 0;
}