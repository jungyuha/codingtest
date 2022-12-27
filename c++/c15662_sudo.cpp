/*

*) 입력
4
10101111
01111101
11001110
00000010
2
3 -1
1 1
*) 메모리

*) 시나리오
turn  : int index,int di
    queue q1,q2;
    if d == 1
        순회 : 1~8
            1 부터 mp[index] q1에 담기 
    else if d == 01
            7 부터 mp[index] q1에 담기
    순회 : 1~8
        mp[index]에 q1 차례로 담기  

(메인)
(회전입력 순회)
    int c1,c2,vis[1000]; c1--;
    memset(vis,0,sizeof(vis));
    회전 톱니바퀴 : mp[c1] 
    int rd = c2;
    오른쪽 순회 : int i = c1; i<a;i++
        오른쪽 맞닿는 곳 : mp[i][t1]
        오른쪽 톱니바퀴 : mp[i+1][t2]
        vis[i]=rd;
        if i+1<a && mp[i][t1] + mp[i+1][t2] == 1 :
            rd*=(-1);
        else : break;
    int ld = c2;
    왼쪽 순회 : int i = c1; i>=0;i--
        왼쪽 맞닿는 곳 : mp[i][t2]
        왼쪽 톱니바퀴 : mp[i-1][t1]
        vis[i]=ld;
        if i-1>=0 && mp[i][t2] + mp[i-1][t1] == 1 :
            ld*=(-1);
        else : break;
    (vis 순회) int i=0;i<a;i++
        if vis[i]!=0:
            turn(i,vis[i]);
(톱니바퀴 순회) int i=0; i<a;i++
    if mp[i][0]==1 : tot++  
*) 출력
(1) mp
for(int i=0;i<a;i++){
        for(int j=0;j<8;j++){
            cout << mp[i][j] ;
        }
        cout << endl;
    }
*) 기타

*/