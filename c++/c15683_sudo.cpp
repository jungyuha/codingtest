/*
*) 입력
4 6
0 0 0 0 0 0
0 0 0 1 0 0
0 0 1 0 6 0
0 0 0 0 0 0

4 6
0 0 0 0 0 0
0 0 0 4 0 0
0 4 0 0 6 0
0 0 0 0 0 0

6 6
0 0 0 0 0 0
0 2 0 0 0 0
0 0 0 0 6 0
0 6 0 0 2 0
0 0 0 0 0 0
0 0 0 0 0 5
*) 메모리
const int dx[]={0,1,0,-1};
const int dy[]={-1,0,1,0};
int a,b,mp[8][8],vis[8][8],tot;
*) 시나리오
(go) int type , int cx , int cy , int tp[8][8] , int index
    if(index == tot){ // 기저사례
        // 사각지대 계산
    }
    if type == 1 (방향 1개씩 4번)
        (4방향 순회) int i=0;i<4;i++
            방향 선정
                int nx , ny
            CCTV 동선 처리
                int ttp[8][8];memcpy(ttp,tp,sizeof(ttp));
                while(nx>=0 && nx < b && ny >=0 && ny < a) :
                    if(ttp[ny][nx]==6) break;
                    if(ttp[ny][nx]==0) ttp[ny][nx]=9;
                    nx += dx[i]; ny += dy[i];
            방문처리 vis[cy][cx]=1; 
            (ttp 순회)
                if(ttp[i][j] > 0 && ttp[i][j] < 6 && vis[i][j]==0):
                        go(ttp[i][j],j,i,ttp,index+1);
            if(index+1 == tot) // 순회가 도중에 끝나면
                go(0,0,0,ttp,tot);
            방문해제 vis[cy][cx]=0; 
    else if type == 2 (방향 2개씩 2번)
        (2방향 순회) int i=0;i<2;i++ (1,3 / 2,4)
            방향 선정
                int nx1 = cx+dx[0],ny1 = cy+dy[0];
                int nx2 = cx+dx[2], ny=nx+dy[2];
                또는
                int nx1 = cx+dx[1],ny1 = cy+dy[1];
                int nx2 = cx+dx[3], ny=nx+dy[3];
            CCTV 동선 처리
                int ttp[8][8];memcpy(ttp,tp,sizeof(ttp));
                while(nx1>=0 && nx1 < b && ny1 >=0 && ny1 < a) :
                    if(ttp[ny1][nx1]==6) break;
                    if(ttp[ny1][nx1]==0) ttp[ny1][nx1]=9;
                    nx1 += dx[?]; ny1 += dy[?];
                while(nx2>=0 && nx2 < b && ny2 >=0 && ny2 < a) :
                    if(ttp[ny2][nx2]==6) break;
                    if(ttp[ny2][nx2]==0) ttp[ny2][nx2]=9;
                    nx2 += dx[?]; ny2 += dy[?];
            방문처리 vis[cy][cx]=1; 
            (ttp 순회)
                if(ttp[i][j] > 0 && ttp[i][j] < 6 && vis[i][j]==0):
                        go(ttp[i][j],j,i,ttp,index+1);
            if(index+1 == tot) // 순회가 도중에 끝나면
                go(0,0,0,ttp,tot);
            방문해제 vis[cy][cx]=0; 
(메인)


*) 출력
(1) cout << "go : "<<cy << "," << cx << ","<<type<<","<<index<<endl;
(2) cout << tp[i][j] << " ";
(3) cout << endl;
(4)

*) 기타
*/