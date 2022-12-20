/*
*) 입력
7 8 1
0 0 0 0 0 0  0 9
0 0 0 0 3 0  0 8
-1 0 5 0 0 0 22 0
-1 8 0 0 0 0 0 0
0 0 0 0 0 10 43 0
0 0 5 0 15 0 0 0
0 0 40 0 0 0 20 0

*) 메모리
int mp[50][50];
int air_y[2];
int w,h,t,tot;
const int dx[]={1,0,-1,0};
const int dy[]={0,-1,0,1};
queue <int> q1,q2;
const int dx_a[]={0,1,0,-1};
const int dy_a1[]={-1,0,1,0};
const int dy_a2[]={1,0,-1,0};

*) 시나리오
(t순회)
    1.확산
    int v[50][50]=0;
    (el:mp순회)
        if el < 5 : continue
        v[i][j] = el/5;
    (el:v순회)
        if v <= 0 : continue
        (el2 : mp 4방향 순회)
            if 범위체크
            mp[ny][nx] += v[i][j];
            mp[y][x] -= v;
    2.공기청정
    int d1 = 0,d2=0 cx = 0, cy = air_y[0];
    (공기청정기1 순회) : while 큐에 넣는다. 순서대로
        int nx = cx + dx_a[d1]; int ny = cy + dy_a1[d1];
        if(nx == 0 && ny == air_y[0]) : break;
        if(ny < 0 || nx >= w || ny > air_y[0]){
            d1 ++;
            nx = cx + dx_a[d1]; ny = cy + dy_a1[d1];
        }
        q1.push(mp[ny][nx]);
        cx = nx; cy = ny;
    q1.pop(); q1.push(0); 제일 첫번째꺼를 뽑고 제일 마지막꺼에 0을 넣는다.
    d1 = 0; cx = 0; cy = air_y[0];
    (공기청정기1 순회) : while 순서대로 다시 맵에 집어넣는다.
        int nx = cx + dx_a[d1]; int ny = cy + dy_a1[d1];
        if(nx == 0 && ny == air_y[0]) : break;
        if(ny < 0 || nx >= w || ny > air_y[0]){
            d1 ++;
            nx = cx + dx_a[d1]; ny = cy + dy_a1[d1];
        }
        mp[ny][nx]=q1.pop();
        cx = nx; cy = ny;
    d1 = 0; cx = 0; cy = air_y[1];
    (공기청정기2 순회) : while 큐에 넣는다. 순서대로
        int nx = cx + dx_a[d2]; int ny = cy + dy_a2[d2];
        if(nx == 0 && ny == air_y[1]) : break;
        if(ny >= h || nx >= w){
            d2 ++;
            nx = cx + dx_a[d2]; ny = cy + dy_a2[d2];
        }
        q2.push(mp[ny][nx]);
        cx = nx; cy = ny;
    q2.pop(); q2.push(0); 제일 첫번째꺼를 뽑고 제일 마지막꺼에 0을 넣는다.
    d2 = 0; cx = 0; cy = air_y[1];
    (공기청정기2 순회) : while 순서대로 다시 맵에 집어넣는다.
        int nx = cx + dx_a[d2]; int ny = cy + dy_a2[d2];
        if(nx == 0 && ny == air_y[1]) : break;
        if(ny >= h || nx >= w){
            d2 ++;
            nx = cx + dx_a[d2]; ny = cy + dy_a2[d2];
        }
        mp[ny][nx]=q2.pop();
        cx = nx; cy = ny;
0보다 큰 지역의 수를 센다.
    
*) 출력

(1) mp
    idx =0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cout << mp[i][j] << " ";
            if(mp[i][j]==-1){
                cout << air_y[idx++] << " ";
            }
        }
        cout << endl;
    }
(2) q
while(!q1.empty()){
        cout << q1.front() << " ";
        q1.pop();
    }
*) 헷갈린거
1. 미세먼지의 확산은 동시에 일어나는 것이다. 차례차례 순서대로 제거되는 게 아님 !!
*/