/*
*) 입력 
첫째 줄은 나열된 양의 실수들의 개수 N이 주어지고,
그 다음 줄부터 N개의 수가 한 줄에 하나씩 들어 있다. N은 10,000 이하의 자연수이다.
실수는 소수점 첫째자리까지 주어지며, 0.0보다 크거나 같고, 9.9보다 작거나 같다.

8
1.1
0.7
1.3
0.9
1.4
0.8
0.7
1.4
*) 메모리

*) 시나리오
max_=mp[0];
for(int i=1;i<n;i++) : mp 순회
    if(mp[i]<1) continue;
    for(int j=0;j<=i;j++) : i까지 순회
        double m_res=1;
        int st=j,ed=i;
        for(int k=st;k<=ed;k++){
            m_res *= mp[k];
        }
        max_=max(max_,m_res);
        
*) 출력
(1) 
    cout << endl;
   for(int i=0;i<n;i++){
        cout << mp[i] << " ";
    }
*/