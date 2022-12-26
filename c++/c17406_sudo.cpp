/*

*) 입력
5 6 2
   0 1 2 3 4 5
0: 1 2 3 2 5 6
1: 3 8 7 2 1 3
2: 8 2 3 1 4 5
3: 3 4 5 1 1 1
4: 9 3 2 1 4 3
3 4 2
4 2 1

5 6 2
1 2 3 2 5 6
3 8 7 2 1 3
8 2 3 1 4 5
3 4 5 1 1 1
9 3 2 1 4 3
3 4 2
4 2 1
*) 메모리
int a,b,c;
int mp[50][50];
vector<tuple<int,int,int>> tu;
int vis[6];
*) 시나리오

(func1) int tp[50][50] , int k
if k == c :
    res 계산
    return ;
(int el : vis 순회)
    if (el == 1) : continue
    tp[el] 배열 돌리기
    배열값 구하기
    el = 1
    func1(tp)
    el = 0;
(메인)
    func1(mp,0)

*) 출력
(1) mp
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cout << mp[i][j];
        }
        cout << endl;
    }
(2)
    cout << "i :"<<i<<endl;
(3)
    cout << "lx :"<<lx << ",ly:"<<ly;
    cout << ",rx :"<<rx << ",ry:"<<ry<<endl;
(4)
    cout << "cx :"<<cx<<",cy :"<<cy<<","<<tp[cy][cx]<<endl;
*) 기타


*/