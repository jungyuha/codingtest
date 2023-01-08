/*
*) 문제
첫째 줄에 N(1 ≤ N ≤ 2,000,000,000)과 M(1 ≤ M ≤ 10,000)이 빈칸을 사이에 두고 주어진다.
둘째 줄에는 각 놀이기구의 운행 시간을 나타내는 M개의 자연수가 순서대로 주어진다.
운행 시간은 1 이상 30 이하의 자연수이며, 단위는 분이다.

예제 입력 1 
3 5
7 8 9 7 8

22 5
1 2 3 4 5
*) 메모리
1. 시간 복잡도(최대) :  2000000000 * 30
int n,m,res,st,ed,mid;
int mp[10000];
*) 시나리오
st=1; ed=60000000000;

while(st<=ed):
    mid = (st+ed)/2;
    int m_res=0 : 놀이기구 탈 수 잇는 총 인원
    for(int i=0;i<m;i++): 놀이기구 순회 
        m_res+=(mid/mp[i]);
    if(m_res==n) :
        res = mid;
    if(m_res>=n):
        ed = mid-1;
    else if(m_res<n):
        st = mid+1;
int m_res=0;
for(int i=0;i<m;i++): 놀이기구 순회 
    m_res+=((res-1)/mp[i]);
for(int i=0;i<m;i++): 놀이기구 순회 
    if(res%mp[i]==0): m_res++;
    if(m_r==n):
        cout << i << endl;
        return 0;

*) 출력
(1) cout << "st : "<<st<<",ed : "<<ed<<",mid : "<<mid<<endl;
(2) cout << "mp : " <<mp[i] <<"   ";
(3) cout << mid/mp[i] << " , ";
(4) cout << ", m_res : "<<m_res<< endl;
*/