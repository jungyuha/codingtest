/*
3
1 6 4 3 5 2 7 ,
3
6 2
1 4 5 7

*) 시나리오
int n = 7;
int seq = 0;
int mp[]={1 6 4 3 5 2 7} 또는 {2 1 3}
<seq>: 배열의 값(임의 순서) {4,2,7,1,3,5,6}
            4
    2               7
1       3       5       6
<배열의 index> {0,1,2,3,4,5,6}
           0
    1             2
3       4     5       6


*) 수도코드
res {0,0,0,0,0,0,0}
메인{
    함수A(0)
}
함수A(cx:현재인덱스)
    int nx; // 새로운 인덱스
    nx = 2*cx+1;
    if(nx>n && nx+1>n){
        res[cx]=mp[seq];
        seq++;
        return;
    }
    함수A(nx);
    res[cx] = seq; seq++;
    함수A(nx+1);

*) 시나리오
n : 3 , level = 2
cx : 0 , nx : 1 , seq=0
    cx : 1 , nx : 3 , res[cx] =res[1]= mp[seq]=mp[0]=2;seq = 1;
    res[cx] =res[0]= mp[seq]=mp[1]=1;seq = 2;
    cx : 2 , nx : 5 ,  res[cx] =res[2]= mp[seq]=mp[2]=3;seq = 3;
res => [1,2,3] 

level = 0 , 1
pop=0;
for(int i=0;i<level;i++){
    for(int j=0;j<2^i;j++){
        cout << res[pop];
        pop++;
    }
    cout << "\n";
}

*) 출력 테스트
for(int el : mp1){
        cout << el << " ";
    }

*/