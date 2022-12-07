#include <bits/stdc++.h>
using namespace std;

int a,b,max_sum;
int mp1[4][4];
int main(){

    scanf("%d %d",&a,&b);
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            scanf("%1d",&mp1[i][j]);
        }
    } 

for(int i=0;i<(1<<(a*b));i++){
    int sum=0;
    // 가로합
    for(int y=0;y<a;y++){ // 행
        int res=0;
       for(int x=0;x<b;x++){ // 열
            int k = x + b*y; 
            if(i&(1<<k)){
                res = res*10 + mp1[y][x];
            }
            else{ 
                sum += res;
                res = 0;
            }
        } 
        sum += res;
    }
    // 세로합
    for(int x=0;x<b;x++){ // 열
        int res=0;
       for(int y=0;y<a;y++){ // 행
            int k = x + b*y;
            if(!(i&(1<<k))){
                res = res*10 + mp1[y][x];
            }
            else{ 
                sum += res;
                res = 0;
            }
        } 
        sum += res;
    }
    // 맵 완성
    max_sum=max(sum,max_sum);
}
cout <<max_sum<<"\n";
    return 0;
}