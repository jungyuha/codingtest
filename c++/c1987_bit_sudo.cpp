/*
3 6
HFDFFB
AJHGDH
DGAGEH

*) 메모리
int a,b,ret=-99;
char mp1[20][20]

*) 시나리오
(dfs): cout << "[dfs] cx : "<< cx<<",cy :" << cy<<",num :"<<num<<",cnt :"<<cnt <<"\n";
    ret = max(ret,cnt);
    (상하좌우순회)
        int nx,ny;
        if 범위초과 : continue;
        if (num&(1 << mp1[ny][nx]-'A')) continue; // 방문 여부 확인
        int next = 1 << mp1[ny][nx]-'A';
        dfs(nx,ny,num|next,cnt+1);
(main)
    dfs(int cx, int cy ,int num ,int cnt);
    if(ret>0) {cout << ret;}
    else{cout <<"-1";}

*) 출력
1. mp1
cout <<"\n";
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cout << mp1[i][j];
        }
        cout <<"\n";
    }
2. dfs
cout << "[dfs] cx : "<< cx<<",cy :" << cy<<",num :"<<num<<",cnt :"<<cnt <<"\n";
*/