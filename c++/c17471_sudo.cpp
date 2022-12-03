/*
*) 입력
6
5 2 3 4 1 2
2 2 4
4 1 3 6 5
2 4 2
2 1 3
1 2
1 2

*) 메모리
int a : 6
int val[10]; // 인구수
vector<int> adj[10];
int vis[10];
int s1[10];
int s2[10];
bool conYn ;
*) 시나리오
0: 지역구1 ,1 : 지역구2


(완전탐색 함수) int index,int level , int s1.size()
    if(level==s1.size()){
        conYn = true;
        return;
    }
    (int el : adj[index]순회)
        if(vis[el] ==1 || s1[el]==0) continue;
        vis[el] = 1;
        함수(el,level+1,size)
        if(conYn) break;
        vis[el] = 0;
    vis 초기화

(1~2^a순회)
    bool resYn = false;
    경우의 수 생성
    나누어진 지역구 설정
    0이면 s1 , 1이면 s2
    (s1순회)
        conYn = false;
        (함수)s1 완전탐색
        if conYn == true : break
    if conYn = false : continue;
    (s2순회)
        conYn = false;
        (함수)s2 완전탐색
        if conYn == true :
            resYn = true;
            break;
    if resYn == true : 인구차 비교// 둘다 성공하면 인구차 최소 비교
if min_ != INF : cout << min_
else cout << -1

*) 출력
1. 모든 경우의 수
    for(int i=1;i<=pow(2,a);i++){
        for(int j=0;j<a;j++){
            if(i&(1<<j)){
                cout << "1 "; 
            }
            else{cout << "0 ";}
        }
        cout <<"\n";
    }
2. 인접 리스트
for(int i=0;i<a;i++){
        for(int el : adj[i]){
            cout << el << " ";
        }
        cout << "\n";
    }
3. dfs 매개변수
cout << "[dfs] index:"<<index<<"level:"<<level<<",size : "<<size<<"\n";
4. s1,s2
for(int el : s1){cout << el << " ";} cout << "\n";
*/