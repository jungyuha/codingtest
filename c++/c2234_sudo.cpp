/*
*) 입력
7 4
11 6 11 6 3 10 6
7 9 6 13 5 15 5
1 10 12 7 13 7 5
13 11 10 8 10 12 13

*) 메모리
int a,b,max_sum,cnt,sum;
int mp1[50][50];
int vis[50][50];

*) 시나리오

(dfs)int cx,int cy 
    sum++
    cout <<"[dfs] cx :"<<cx<<",cy:"<<cy<<",_sum:"<<sum<<"\n";
    (상하좌우순회) int i=0;i<4;i++
        int nx = cx + dx[i]; int ny = cx + dy[i];
        cout <<"    nx :"<<nx<<",ny:"<<ny<<",vis[ny][nx]:"<<vis[ny][nx]<<"\n";
        cout <<"i:"<<i<<",mp1[cy][cx]:";for(int aa=0;aa<4;aa++){if(mp1[cy][cx]&(1<<aa)){cout << "1";}else{cout <<"0";}}cout<<"\n";
        if !범위체크 || vis[ny][nx] ==1 : continue
        if (mp1[cy][cx]&(1<<i)) 막혀있으면 : continue
        
        vis[ny][nx]=1;
        dfs(nx,ny);
(go)
    (행순회)(int i=0;i<b;i++):
        (열순회 )(int j=0;j<a;j++):
            sum=0;
            if 방문했다면 continue;
            cout << "출발점 => 행:"<<i<<",열:"<<j<<"\n";
            vis[i][j]=1;
            dfs(j,i);
            vis[i][j]=0;
            max_sum=max(max_sum,sum);
            cnt++;
            cout << "도착 => 넓이 :"<<max_sum<<"갯수 :"<<cnt<<"\n";
    vis 초기화
(메인)
    // 1. 방의 갯수 구하기 + 최대 넓이 구하기
    go();
    // 2. 하나를 제거하여 가장 넓은 방의 크기 구하기
    (행순회)(int i=0;i<b;i++):
        (열순회 )(int j=0;j<a;j++):
            (상하좌우순회) int k=0;k<4;k++
                int nx = j + dx[k]; int ny = i + dy[k];
                cout <<"go1    "<<"i:"<<i<<"j:"<<j<<",nx :"<<nx<<",ny:"<<ny<<"k:"<<k<<",1<<k"<<(1<<k)<<"\n";
                cout <<"mp1[i][j]:";for(int aa=0;aa<4;aa++){if(mp1[i][j]&(1<<aa)){cout << "1";}else{cout <<"0";}}cout<<"\n";
                if !범위체크 : continue
                if (mp1[cy][cx]&(1<<k)) 뚫려있으면 : continue
                    mp1[cy][cx]&=(~(1<<k)); // 비트 끄기
                    // 맞닿아있는 쪽 비트 끄기 (이걸 처음에 놓침 ㅠㅠ)
                    if k == 0: // 서
                        mp1[ny][nx]&=(~(1<<2)); // 동
                    else if k == 1 : // 북
                        mp1[ny][nx]&=(~(1<<3)); // 남
                    else if k == 2 : // 동
                        mp1[ny][nx]&=(~(1<<0)); // 서
                    else if k == 3 : // 남
                        mp1[ny][nx]&=(~(1<<1)); // 북
                    cout <<"go2    nx :"<<nx<<",ny:"<<ny<<",k:"<<k;
                    cout <<"mp1[i][j]:";for(int aa=0;aa<4;aa++){if(mp1[i][j]&(1<<aa)){cout <<"1";}else{cout << "0";}}cout<<"\n";
                    sum=0;
                    vis[ny][nx]=1;
                    dfs(nx,ny);
                    memset(vis,0,sizeof(vis));
                    cout <<"go_end!    sum :"<<sum<<"\n";
                    mp1[cy][cx]|=(1<<k); // 비트 켜기
                    // 맞닿아있는 쪽 비트 켜기 (이걸 처음에 놓침 ㅠㅠ)
                    if k == 0: // 서
                        mp1[ny][nx]|=(1<<2); // 동
                    else if k == 1 : // 북
                        mp1[ny][nx]|=(1<<3); // 남
                    else if k == 2 : // 동
                        mp1[ny][nx]|=(1<<0); // 서
                    else if k == 3 : // 남
                        mp1[ny][nx]|=(1<<1); // 북

*) 출력
1.
for(int i=0;i<b;i++){
        for(int j=0;j<a;j++){
            cout << mp1[i][j] <<" ";
        }
        cout <<"\n";
    }
2. dfs
cout <<"[dfs] cx :"<<cx<<",cy:"<<cy<<",_sum:"<<sum<<"\n";
cout <<"    nx :"<<nx<<",ny:"<<ny<<",mp1[cy][cx]&(1<<i) :"<<(mp1[cy][cx]&(1<<i))<<"\n";
*/