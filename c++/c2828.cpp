/*
5 1
3
1
5
3
*/
#include <bits/stdc++.h>
using namespace std;

int a , b , c ,d , le = 1 , ri , res ;
// a: 길이 , b : 바구니 길이 , c : 사과 갯수 , d : 각 사과의 위치 , le : 바구니 왼쪽 끝 , ri : 바구니 오른쪽 끝
// res : 바구니 이동 거리
int main(){

    cin >> a >> b >> c;
    ri = b;

    for(int i = 0 ; i < c ; i++){
        cin >> d;
        if(le <= d && d <= le + b - 1) continue;
        if(d < le){
            res += (le-d);
            le = d;
            ri -= (le-d);
        }
        else if(ri < d){
            res += (d-ri);
            le += (d-ri);
            ri = d;
        }
    }
    cout << res << "\n";
    return 0;
}