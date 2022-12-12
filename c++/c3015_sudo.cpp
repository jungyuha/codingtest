/*
*) 입력
7
2
4
1
2
2
5
1

*) 메모리
vector<int> aLst; [2 4 1 2 2 5 1]

*) 시나리오
(리스트 순회) i=0;i<aLst.size();i++
    현재 인덱스 int cur = aLst[i];
    int mid_max = -1;
    (현재인덱스다으부터순회) j=i+1;j<aLst.size();j++
        (내 다음에 있는 애) int next = aLst[j];
        if 나랑 접근한 애 OR 여태 봐왔던 애들중에 제일 큰 애
            (마주볼 수 있다.) res++; 
            mid_max= next;
        if (근데 얘가 나보다 크면) cur < next :
            (이제 다음애들은 나를 못 보므로 나는 토스 ) break;
*/
