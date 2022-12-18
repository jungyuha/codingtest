/*
*) 입력
5
1 2 3 4 5

5
1 2 3 1 2

*) 메모리
int a,p1,p2,res,res_part;
int vis[100001];
vector<int> lst;
*) 시나리오
(lst순회)p1=0;p1<a;p1++
    vis[p1]=1;
    while(vis[p2] != 1 && p2 < a):
        res_part ++ ;
        vis[p2]=1;
        p2++;
    res += (res_part-1);
    res_part--;
    vis[p1]=0;


*) 출력
(1)
    cout << "p1 :"<<p1 << ",res_part :"<<res_part <<endl;
    cout << "p2 :"<<p2 << ",vis[lst[p2]] :"<<vis[lst[p2]]<<endl;
(2)
cout << "p2 :"<<p2 << ",res_part :"<<res_part<<endl;
*/