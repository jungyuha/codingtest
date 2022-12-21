/*
q를 이용해 조합 구현하기

*) 입력
4
0 1 2 3
4 0 5 6
7 1 0 2
3 4 5 0

*) 메모리
int n ,mp[20][20];
int t,res=99999;
int a[20],b[20];
priority_queue<int,vector<int>,greater<int>> pq;

*) 시나리오
(메인)
t = n/2;
for(int i=0;i<n;i++){
    pq.push(i);
}
func1(0,pq);

(func1 조합 함수) : int idx , priority_queue<int,vector<int>,greater<int>> q
    if(idx==t){
        for(int i=0;i<n;i++){
            if(a[i]==0) b[i]=i;
        }
        // 차이값 계산
    }
    while(!q.empty()) : 
        a[q.front()]=1;
        q.pop();
        func1(idx+1,q);

*) 출력
1)
    cout << endl;
    for(int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout << mp[i][j] << " ";
        }
        cout << endl;
    }
(2) 경우의 수 배열
        for(int i=0;i<n;i++){
            cout << a[i] <<" ";
        } cout << endl;
        for(int i=0;i<n;i++){
            cout << b[i] <<" ";
        }
        cout << endl;
(3) 경우의 수 좌표
cout << "("<<i<<","<<j<<")"<<endl;
(4) 결과 출력
cout << "tot_a : "<<tot_a<<",tot_b :"<<tot_b<<",res :"<<res<<endl;
*/