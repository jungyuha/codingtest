/*
9
> < < < > > > < <
예시 : 3 < 4 < 5 < 6 > 1 < 2 < 8 > 7 < 9 > 0
*) 메모리
int vis[11]
vector<int> res;
*) 시나리오
  >   <
1 
2
    1
        3
        4
        5..
3
    1
        2
        4
        5..
    2
        4
        5
        6..
4
    1
    2
    3
5...

*) 수도코드 
(메인)

for(int i = n;i>=0;i--){
    vis[i]=1;
    함수A(0,i,"i");
    vis[i]=0;
}

(함수A) 현재 인덱스(cx,0) , 현재값(cp) , 누적값(pp)
    if(cx==n){
        res.push_back(pp+cp);
        return;
    }
    (반복) for(int np = 9 ; np >= 0 ; np--)
        if(vis[np]>0) continue;
        if(부등호[0]=='<' && cp >= np)
            continue;
        else if(부등호[0]=='>' && cp <= np)
            continue;
        vis[np]=1;
        함수A(cx+1,np,pp+np)
        vis[np]=0;

*/