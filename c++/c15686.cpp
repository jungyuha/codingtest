#include <bits/stdc++.h>
using namespace std;

int a,b,c,min_res=9999; // 5,3 ,입력
vector<pair<int,int>> ch;
vector<pair<int,int>> zib;
pair<int,int> ch1[13]; // 뽑힌 치킨집

void dfs(int lvl,int index){
    ch1[lvl]={ch[index].first,ch[index].second};
    if(lvl+1 == b){
        // 순회 안 함
        int sum1 = 0;
        for(pair<int,int> el : zib){ //순회3
            int min1=9999;
            for(int i=0;i<b;i++){    //  순회 4
                int s=0;
                s = abs(ch1[i].first-el.first)+abs(ch1[i].second-el.second);
                if(min1>s) min1 = s;
            }
            sum1 += min1;
        }
        //cout << sum1 << "\n";
        if(min_res>sum1) min_res =sum1;
        return;
    }
    for(int i=index+1;i<ch.size();i++){ //순회2
        dfs(lvl+1,i);
    }
}
int main(){
    cin >> a >> b;
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            cin >> c;
            if(c == 2){
                ch.push_back({i,j});
            }
            else if(c == 1){
                zib.push_back({i,j});
            }
        }
    }

    for(int i=0;i<ch.size();i++){ // 순회1
        dfs(0,i);
    }

    cout << min_res << "\n";
    return 0;
}
/*
[수도코드]
// 도시 치킨 거리의 최소값
/* 입력
5 2
0 2 0 1 0
1 0 1 0 0
0 0 0 0 0
2 0 0 1 1
2 2 0 1 2
// 2. 치킨집 뽑기
1) b개를 뽑는다.
2) 조합으로 뽑는다.
치킨집 리스트 => vector<pair<int,int>> ch; => {{0,1},{3,0},{4,0},{4,1},{4,4},{...}; 
집 리스트 => vector<pair<int,int>> zib; => {{0,3},{1,0},{1,2},{3,3},{3,4},{4,3}...};
pair<int,int> ch1[13] 모양 = {{0,1},{3,0},...}; // 뽑힌 치킨집 조합 (y,x)
//1
(순회1)ch {{뽑0,1},{3,1},{4,0},{4,1},{4,4},0...} => int min_res(치킨거리 최소)
    lvl(0==1개) ==  b개(2) not ok
    index(=0) < 치킨집갯수(5) ok (순회,dfs)
    ch1[lvl] = {{0,1}}
    (순회2)ch {{0,1},{뽑3,1},{4,0},{4,1},{4,4},0...}  => 각 지도 모습 , int sum1; (각 지도의 치킨 거리)
        lvl(1 == 2개 ) == b개(2) ok => (순회안함)
        index(=1) < 치킨집갯수(5) ok (순회,dfs)
        ch1[lvl] = {{0,1},{3,1}}
        (순회3)zib(집) {{뽑0,3},{1,0},{1,2},{3,3},{3,4},{4,3}...} => int min1(각 집마다의 거리 최소);
            (순회4)ch1 {{뽑0,1},{3,1},...} => 1. int s(각 치킨집마다의 거리) 
                2.min1 비교,계산
            sum1 = sum1+min1 (sum1 계산)
        min_res 비교,계산           
*/
*/