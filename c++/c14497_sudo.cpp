/*
1. 입력
5 7
3 4 1 2
1#10111
1101001
001*111
1101111
0011001

주난의 위치 a (y,x) : 2,3
도둑 위치 b (y,x) : 0,1

2.시나리오
(반복) 도둑놈이 방문처리가 되어있을때까지 반복한다.
queue q1
    level++;
    (1번째 q순회)q 순회를 시작한다.(조건은 1을 둘러싼 공간까지만 순회가 끝났을 때이다.q.size()==0) q =[{2,3}] 
        int qx,qy (방문 정점)
        q에 방문 정점을 뽑는다. qx,qy {2,3}
        (q정점 상하좌우 순회)q로부터 상하좌우 순회를 시작한다. => 0이면 계속 순회하고 1이면 멈춰야한다. 1을 둘러싼 공간만 순회한다.
            int nqx,nqy (순회 정점)
            nqx = qx + dx[]
            nqy = qy + dy[]
            if 범위를 초과 확인 , 방문 사실 확인
                if 1이면 q1 =[{2,3상},{2,3하},{2,3좌},{2,3우}]
                else q에 넣는다. q =[{2,3}] , 방문 처리한다.(level=1)
            else continue
        q의 방문 정점을 pop한다.
    (q순회끝)
    q= q1 =[{2,3상},{2,3하},{2,3좌},{2,3우}],level=2
        level++;
        int qx,qy (방문 정점)
        q에 방문 정점을 뽑는다. qx,qy {1,3} / {3,3}
        (q정점 상하좌우 순회)q로부터 상하좌우 순회를 시작한다. => 0이면 계속 순회하고 1이면 멈춰야한다. 1을 둘러싼 공간만 순회한다.
            int nqx,nqy (순회 정점)
            nqx = qx + dx[]
            nqy = qy + dy[]
            if 범위를 초과 확인 , 방문 사실 확인
                if 0이면 q에 넣는다. 방문처리한다(level=2) , q =[{2,3상},{2,3하},{2,3좌},{2,3우},{1,3상0},{1,3하0},{1,3좌0},{1,3우0}] /
                else if 1이면 q1 =[{1,3상1},{1,3하1},{1,3좌1},{1,3우1}]
            else continue
        q1의 방문 정점을 pop한다. q1 =[{2,3하},{2,3좌},{2,3우},{1,3상0},{1,3하0},{1,3좌0},{1,3우0}]
    (q순회끝)
    ...

*/