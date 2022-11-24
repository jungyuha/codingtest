/*
0.입력
4 11
..XXX...X..
.X.XXX...L.
....XXX..X.
X.L..XXX...

1. 메모리
1) mp1
..XXX...X..
.X.XXX...L.
....XXX..X.
X.L..XXX...

2) melted
00000000000
00000000000
00000000000
00000000000

3) vis 오리 순회용
00000000000
00000000000
00000000000
00000000000

2. 시나리오
queue q <pair<int,int>> // X들을 담는다.
int level= 0;
pair<int,int> ap,bp; // 백조 위치
const int dx[]  // 4방향
const int dy[]
bool meet=false;

(반복 : meet가 false인 동안에만 )
    level++;
    meet=false;
    queue<pair<int,int>> temp;
    (반복 : q.size()>0이 어야함)
        int qy = q.front().first;
        int qx = q.front().second;  // q의 위치
        bool xx = true
        (반복 : 한 정점당 4방향)
            int nqy = qy+dy;
            int nqx = qx+dx;
            if nqy,nqx 범위초과
                continue
            if mp1[nqy][nqx]!='X' || (melted[nqy][nqx] < 1evel && melted[nqy][nqx] >0)
                melted[qy][qx]=level
                bool = false
                break;
        if(xx) temp.push({qy,qx});
        q.pop
    q = temp;

    queue q1 <pair<int,int>> // 오리 순회용
    q1.push({ap.first,ap.second});
    (반복 : q1.size()>0이 어야함)
        int qy = q1.front().first;
        int qx = q1.front().second;  // q의 위치
        (반복 : 한 정점당 4방향)
            int nqy = qy+dy;
            int nqx = qx+dx;
            if nqy,nqx 범위초과 || (mp1[nqy][nqx]=='X'&& melted[nqy][nqx]==0 )
                continue
            if nqy == bp.first && nqx == bp.second
                res = level;
                meet = true;
                break;
            if mp1[nqy][nqx]!='X' || (melted[nqy][nqx] < 1evel && melted[nqy][nqx] >0)
                q1.push({nqy,nqx});
        if(meet) break;
        q1.pop
    vis 초기화

9.기타

*/

for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cout << mp1[i][j];
        }
        cout << "\n";
    }
    
    cout <<"ap : "<<ap.first<<","<<ap.second<<"bp :"<<bp.first<<","<<bp.second<<"\n";

----

    while(!meet){
        level++;
        meet=false;
        while(q.size()){
            int qy = q.front().first;
            int qx = q.front().second;
            queue<pair<int,int>> temp;
            bool xx = true;
            for(int i=0;i<4;i++){
                int nqy = qy+dy[i];
                int nqx = qx+dx[i];
                if(nqy < 0 || nqx<0 || nqy >=a || nqx >=b || mp1[nqy][nqx]=='X') continue;
                if(mp1[nqy][nqx]=='.'){
                    mp1[qy][qx]='.';
                    xx=false;
                    break;}
            }

        }
    }