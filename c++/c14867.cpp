#include <bits/stdc++.h>
using namespace std;
int a,b,c,d,res;
map<pair<int,int>,int> mp;
queue<pair<int,int>> q;

// (1)
void go_fill(char gubun,int ca,int cb){
    //(2) 
    int na,nb;
    // [F(x): Fill x]: 물통 x에 물을 가득 채운다. (물을 채우기 전에 물통 x가 비어있는지 여부는 관계없음. 다른 물통은 그대로 둠)
    if(gubun=='a'){
        if(ca == a) return;
        na = a; nb = cb;
    }
    else if(gubun=='b'){
        if(cb == b) return ;
        na = ca; nb = b;
    }
    if(mp[{na,nb}]) return;
    q.push({na,nb});
    mp[{na,nb}]=mp[{ca,cb}]+1;
    //(3)
}
void go_empty(char gubun,int ca,int cb){
    //(4) 
    // [E(x): Empty x]: 물통 x의 물을 모두 버린다. (다른 물통은 그대로 둠)
    int na,nb;
    if(gubun=='a'){
        if(ca == 0) return ;
        na = 0; nb = cb;
    }
    else if(gubun=='b'){
        if(cb == 0) return ;
        na = ca; nb = 0;
    }
    if(mp[{na,nb}]) return;
    q.push({na,nb});
    mp[{na,nb}]=mp[{ca,cb}]+1;
    // (3)
}
void go_move(char from , char to,int ca,int cb){
    // (5) 
    // [M(x,y): Move water from x to y)]: 물통 x의 물을 물통 y에 붓는다.
    // 이때 만약 물통 x에 남아 있는 물의 양이 물통 y에 남아 있는 빈 공간보다 적거나 같다면 물통 x의 물을 물통 y에 모두 붓는다.
    // 만약 물통 x에 남아 있는 물의 양이 물통 y에 남아 있는 빈 공간보다 많다면 부을 수 있는 만큼 최대로 부어 물통 y를 꽉 채우고 나머지는 물통 x에 남긴다.
    int ra = a - ca ; // a에 남아있는 공간
    int rb = b - cb ; // b에 남아있는 공간
    int na,nb;
    if(from=='a' && to == 'b'){
        if(cb == b || ca == 0) return ;
        int temp = min(ca,rb);
        nb = cb+temp; na = ca-temp;
    }
    else{
        if(ca == a || cb == 0) return ;
        int temp = min(cb,ra);
        nb = cb-temp; na = ca+temp;
    }
    if(mp[{na,nb}]) return;
    q.push({na,nb});
    mp[{na,nb}]=mp[{ca,cb}]+1;
    // (3)
}

int main(){
    cin >> a >> b >> c >> d ;
    q.push({0,0});
    mp[{0,0}]=0;

    while(!q.empty()){
        int ca = q.front().first;
        int cb = q.front().second;
        q.pop();
        // (1) 채우기
        go_fill('a',ca,cb);
        go_fill('b',ca,cb);
        // (2) 비우기
        go_empty('a',ca,cb);
        go_empty('b',ca,cb);
        // (3) 이동                  
        go_move('a','b',ca,cb);
        go_move('b','a',ca,cb);

        if(mp[{c,d}]) {
            res=mp[{c,d}];
            break;
        }
    }

    if(!mp[{c,d}]) res=-1;
    cout << res << endl;

    return 0;
}