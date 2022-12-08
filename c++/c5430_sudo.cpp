/*
*) 입력
4
RDD
4
[1,2,3,4]
DD
1
[42]
RRD
6
[1,1,2,3,5,8]
D
0
[]

RDD
4
[12,232,223,44]
*) 메모리
vector<int> mp;
string func_str;

*) 시나리오
(맵순회)
    int start=0,end=mp.size()-1;
    bool res = true;
    int drc=0; // 앞 :0 , 뒤 :1 => 1->0 , 0->1
    (func_str 순회 : char c)
        if(c=='R'):
            drc &= ~(1<<0);// 앞이면 0이고 뒤이면 1인 drc값을 서로 끄고 킨다.
        else if(c=='D'):   
            if(시작인덱스 > 끝 인덱스):
                error처리; break;
            if drc == 앞 :
                start 인덱스 ++;
            else if drc == 뒤 :
                end 인덱스 --;

*) 핵심
- 입력되는 숫자가 1부터 100까지임

*) 출력
1. mp
for(int el : mp){
        cout << el << " ";
    }
*/