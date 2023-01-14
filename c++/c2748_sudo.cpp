/*

*) 메모리
int mp[90];
*) 시나리오
(메인)
    memset(mp,-1,sizeof(mp));
    mp[0]=0;mp[1]=1; mp[2]=1;
    go(n);
go(n) : 
    if(mp[n]!=-1){
        return mp[n];
    }
    return go(n-1)+go(n-2);
*/