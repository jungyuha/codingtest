/*

*) 입력
첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000)이 주어진다.
둘째 줄에는 수열 A를 이루고 있는 Ai가 주어진다. (1 ≤ Ai ≤ 1,000)
6
10 20 10 30 20 50

7
10 20 10 15 30 20 50
1  2  1  2  3  2  4
-1 0 -1  0  1  0  4

*) 메모리
int a,lastIndex,mp[1000],rnk[1000],prevLst[1000];
vector<int> realLst;
*) 시나리오
(rnk 1 초기화)
(prevLst -1 초기화)
(mp순회) int i=0;i<a;i++
    (i까지 mp순회) int j=0;j<i;j++
        if mp[i]>mp[j] :
            if rnk[j]+1 <= rnk[i] : continue
            rnk[i]=rnk[j]+1;
            prevLst[i]=j;
            lastIndex = i;
int p=lastIndex;
(prevLst 조회) while (p!=-1)
    realLst.push_back(mp[p]);
    p=prevList[p];
realLst 출력

*) 출력
*/