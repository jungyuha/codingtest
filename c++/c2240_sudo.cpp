/*
*) 입력
자두는 T(1≤T≤1,000)초 동안 떨어지게 된다.
자두는 최대 W(1≤W≤30)번만 움직이고 싶어 한다.
매 초마다 어느 나무에서 자두가 떨어질지에 대한 정보가 주어졌을 때, 자두가 받을 수 있는 자두의 개수를 구해내는 프로그램을 작성하시오.
자두는 1번 자두나무 아래에 위치해 있다고 한다.

입력
첫째 줄에 두 정수 T, W가 주어진다. 다음 T개의 줄에는 각 순간에 자두가 떨어지는 나무의 번호가 1 또는 2로 주어진다

7 2
2
1
1
2
2
1
1

*) 메모리
//int mp[t][p][w]
int mp[1000][2][30],arr[1000];
*) 점화식 (t : 7 / w : 5)
mp[0][0] = 0;
mp[0][1] = -987654321;

mp[t][0][m]=max(mp[t-1][0][m],mp[t-1][1][m-1]) +(arr[t]==1 ? 1:0)
mp[t][1][m-1]=max(mp[t-1][0][m-2],mp[t-1][1][m-1]) +(arr[t]==2? 1:0)
res => max(mp[t][0][m],mp[t][1][m-1])

*) 시나리오
(메인)
    memset(mp,-1,sizeof(mp));
    res = max(go(n,0,m),go(n,1,m-1));
(go)
go(n,p,m):
    if(n<0 || m <0): return -987654321;
    if(n==0):
        if p==0 :
            return 0;
        else if p==1 :
            return -987654321;
    if(mp[n][p][m] == -1) :
        return mp[n][p][m] = max(go(n-1,p,m),go(n-1,(p^1),m-1))+(arr[n]==p+1 ? 1:0);


*) 출력
(1) cout << "go : "<<n<<","<<p<<","<<m<<endl;
(2) cout << "("<<n<<") : return  "<<-987654321<<endl;
(3) cout << "("<<n<<") : n: "<<n<<",p:"<<p <<endl;
(4) cout << "("<<n<<") : return  "<<0<<endl;
(5) cout << "("<<n<<") : return  "<<-987654321<<endl;
(6) cout << "("<<n<<") : return  "<<"max(mp["<<n-1<<"]["<<p<<"]["<<m<<"],mp["<<n-1<<"]["<<(p^1)<<"]["<<m-1<<"])+("<<(arr[n]==p+1 ? 1:0)<<")"<<endl;
(7) cout << "("<<n<<") 존재 : return  mp["<<n<<"]["<<p<<"]["<<m<<"] :"<<mp[n][p][m]<<endl;
(8) int res = max(go(0,0,1),go(0,1,0));cout << "res :"<<res;
*/