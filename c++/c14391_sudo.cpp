/*
4 4
4 9 3 7
2 5 9 1
3 8 4 6
9 1 5 0

*) 메모리
int a,b,max_sum;
int mp1[4][4];

*) 시나리오 : 좌표 나누기(경우의 수)
1. 모든 칸 경우의 수(한줄)
for(int i=0;i<(1<<(a*b));i++){
    for(int j=0;j<(a*b);j++){
        if(i&(1<<j)){
            cout << "1";
        }
        else{
            cout <<"0";
        }
    }
}
2. 가로세로 나누기 
for(int i=0;i<(1<<(a*b));i++){
    for(int y=0;y<a;y++){
       for(int x=0;x<b;x++){
            int k = x + b*y;
            if(i&(1<<k)){
                cout <<"1";
            }
            else{
                cout <<"0";
            }
        } 
        cout << "\n";
    }
    cout <<"\n";
}
3. 합구하기
(맵 경우의 수 순회=1개의 맵 순회) i=0;i<(1<<a*b);i++
    int sum = 0; 
    (행순회)
        int res =0;
        (열순회)
            if 요소가 1이면 : res = res*10 + (요소의 값)
            else if 요소가 0이면 :
                sum += res;
                res =0;
        sum += res; // 맨 마지막이 1로 끝날 때
    (열순회)
        int res=0;
        (행순회)
            if 요소가 1이면 : res = res*10 + (요소의 값)
            else if 요소가 0이면 :
                sum += res;
                res =0;
    max_sum =max(sum,max_sum);






*) 시나리오1 : 경우의 수
좌표 갯수 : a*b
좌표(y,x)당 경우의 수 : a-y + b-x = (a+b) - (x+y) => 최대 a+b
전체 경우의 수 : ab(a+b) = a^b + ab^ => o(n^3)

mp1[0][0]
    (8방향순회)
        if 방문처리 되어있으면 : continue


테스트 1. 순회 
mp1[0][0] : 4 (1 0 0 0)
    (1 1 0 0) vis 체크 & 
        가로 : 49
        세로 : 42
    (1 1 1 0) vis 체크 & 
        가로 : 493
        세로 : 423
    (1 1 1 1) vis 체크 & 
        가로 : 4937
        세로 : 4239
...
출력 :
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cout << "mp1["<<i<<"]["<<j<<"]"<<"\n";
            // 가로
            num =0;
            for(int k=j;k<4;k++){
                int res =0;
                num |= (1<<k);
                for(int aa=0;aa<4;aa++){
                    if(num&(1<<aa)){
                        cout<<"1";
                        res=10*res+mp1[i][aa];
                    }
                    else{cout<<"0";}
                }cout<<": ";cout << res <<"\n";
            }
            // 세로
            num =0;
            for(int k=i;k<4;k++){
                int res =0;
                num |= (1<<k);
                for(int aa=0;aa<4;aa++){
                    if(num&(1<<aa)){
                        cout<<"1";
                        res=10*res+mp1[aa][j];
                    }
                    else{cout<<"0";}
                }cout<<": ";cout << res <<"\n";
            }
            
            
        }
    }
출력 결과:
mp1[0][0]
1000: 4
1100: 49
1110: 493
1111: 4937
1000: 4
1100: 42
1110: 423
1111: 4239
..

*/