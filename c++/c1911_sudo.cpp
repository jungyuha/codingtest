/*
*) 입력
3 3
1 6
13 17
8 12

*) 메모리
int a,t,cx,res;
priority_queue<int,vector<int>,greater<int>> q1;
*) 시나리오
물웅덩이 q1에 추가
(q1 순회)
    int start = q1.front();
        (t 순회)
            cx = start+t;
            if q1.front() == cx :
                q1.pop()
        res++;
*) 출력
1) 비트 순회
    for(int i=1;i<pow(2,2);i++){ // 1 2 3 
        for(int j =0;j<2;j++){
            if(i&(1<<j)){
                //00 01 10 11 100
                cout <<"1";
            }
            else{
                cout <<"0";
            }
        }
        cout << endl;
    }
(2)
cout << "start : "<<start<<endl;
(3)
cout << "q1.top() : "<<cx<<endl;
*) 기타
- 각 위치는 0이상 1,000,000,000이하의 정수
*/