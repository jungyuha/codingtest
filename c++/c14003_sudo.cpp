/*

*) 입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다.
둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다.
(-1,000,000,000 ≤ Ai ≤ 1,000,000,000)

9
10 20 13 15 30 10 30 20 50

6
10 20 10 30 20 50
*) 메모리
int mp[1000000],n;
vector<pair<int,int>> infoLst; // rank , prev

*) 시나리오
for(int i=0;i<n;i++) : mp 순회
    for(int j=0;j<i;j++) : i까지 순회
        if mp[i] > mp[j] :
            if(infoLst[j].first + 1 <= infoLst[i].first) : continue;
            infoLst[i].first = infoLst[j].first + 1;
            infoLst[i].second = j;

*) 출력

*/