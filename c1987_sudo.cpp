/* 1987번
0.입력
2 4
CAAB
ADCB

1.메모리
1) 알파벳 방문
int ap[26]
2) 입력맵 , 방문맵
char mp1[20][20]
int vis[20][20]

2. 수도코드 : dfs
(메인)시작 정점 : qy,qx => (0,0)
    ap[mp1[0][0]-'A'] = 1
    함수A(0,0,1)

(함수A) : 시작 정점
    bool endYn = true;
    (순회) 시작 정점의 상하좌우
        int nqy = qy+dy
        int nqx = qx+dx
        if nqx,nqy 범위 초과 || ap[mp1[nqy][nqx]-'A'] > 0 
            continue
        ap[mp1[nqy][nqx]-'A'] = 1
        vis[nqy][nqx] == 1
        함수A(nqy,nqx,level+1)
        ap[mp1[nqy][nqx]-'A'] = 0
        vis[nqy][nqx] == 0
    if(endYn) max비교
*/