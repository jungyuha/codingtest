/*
꽃은 세개
*) 입력
6
1 0 2 3 3 4
1 1 1 1 1 1
0 0 1 1 1 1
3 9 9 0 1 99
9 11 3 1 0 3
12 3 0 0 0 1

*) 메모리
int a;// 6
int mp1[6][6]; // 꽃밭
vector<tuple<int,int,int>> fl ; // 가능한 꽃 리스트 {y,x,비용}

*) 시나리오

(메인)
(y순회)int i=1;i<a-1;i++
    (x순회)int j=1;j<a-1;j++
        int width;
        {y,x}의 상하좌우 순회
            넓이 구하기
        fl.push_back(make_tuple(i,j,넓이))
fl 정렬(오름차순)
comb함수(0,0,0)

(comb함수: fl 조합, 3회전) : int start,int level,int res
    if level == 3 
        if result == -1 (제일 처음일 때만)
            result = res
        return
    (순회) int i = start ; i<fl.size();i++
        visYn=false;
        if 현재 봉우리(fl[i]) 방문되어있으면 continue;
        (상하좌우 순회)
            if 방문체크 : 방문되어있으면 
                visYn = true;
                break;
        if 방문흔적 있으면 continue;
        현재 봉우리 방문체크
        (상하좌우 순회)
            방문체크
        comb(start+1,level+1,res+fl[i]넓이)
        현재 봉우리 방문해제
        (상하좌우 순회)
            방문해제
        if result >0
            return


*/