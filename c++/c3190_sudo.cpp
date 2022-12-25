/*

*) 입력
6
3
3 4
2 5
5 3
3
3 D
15 L
17 D

10
4
1 2
1 3
1 4
1 5
4
8 D
10 D
11 D
13 L

*) 메모리
int mp[100][100];
int vis[100][100];
int a,tot,dx,dy;
int cx,cy ; // 뱀의 머리 위치
queue<pair<int,int>> sn; // 뱀의 몸
priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>> pq; 
*) 시나리오
sn.push({0,0});
dx=1;// 오른쪽 방향 

while:
    cx=cx+dx; cy =cy+dy;
    if 이동 후 좌표가 벽이거나 뱀의 몸이면 : 끝
    sn.push({cy,cx});
    vis[cy][cx]=1;
    tot++;
    if 위치가 사과가 아니면 :
        vis[sn.top().first][sn.top().second]=0;
        sn.pop();
        
    if tot==pq.top().first 방향 전환 좌표를 만나면 :
        if 좌:  
             if 현재 방향이 우 :
                dx=0;dy=-1;
            else if 현재 방향이 하 :
                dx=-1;dy=0;
            else if 현재 방향이 좌 :
                dx=0;dy=1;
            else if 현재 방향이 상 :
                dx=-1;dy=0;
        else if 우 :
            if 현재 방향이 우 :
                dx=0;dy=1;
            else if 현재 방향이 하 :
                dx=1;dy=0;
            else if 현재 방향이 좌 :
                dx=0;dy=-1;
            else if 현재 방향이 상 :
                dx=1;dy=0;
        pq.pop();


*) 출력

(1) mp
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){

        }
        cout << "\n";
    }
(2) pq
    while(!pq.empty()){
        cout << pq.top().first << ","<< pq.top().second << " ";
        // cout << pq.top() << " ";
        pq.pop();
    }
(3)
    cout << "break:"<<cy<<","<<cx<<endl;
(4)
    cout << "push:"<<cy<<","<<cx<<endl;
(5)
    cout << "pop:"<<sn.front().first<<","<<sn.front().second<<endl;
(6)
    cout << "pq.top():"<<pq.top().first<<","<<pq.top().second<<endl;
(7)
    cout << "dx ,dy : "<<dx<<","<<dy<<endl;
*) 기타

*/