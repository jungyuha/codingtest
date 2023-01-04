/*
*) 입력
첫째 줄에 강의의 수 N (1 ≤ N ≤ 100,000)과 M (1 ≤ M ≤ N)이 주어진다.
다음 줄에는 강토의 기타 강의의 길이가 강의 순서대로 분 단위로(자연수)로 주어진다.
각 강의의 길이는 10,000분을 넘지 않는다.
9 3
1 2 3 4 5 6 7 8 9

5 2
2 4 6 8 10

*) 메모리
int n,m,tot,s,e,mid,res;
int mp[100000];
*) 시나리오
(mp 순회)
    tot=전체 합 계산
s = 최소값; e= tot;

while(s<=e) :
    mid = (s+e)/2;
    int m_sum =0,m_cnt=0,m_max=0;
    (mp 순회) int i =0;i<9;i++
        m_sum+=mp[i];
        if(m_sum>mid){
            m_sum-=mp[i];
            m_cnt++;
            i--;
            m_max=max(m_max,m_sum);
            m_sum = 0;
        }
    if(m_sum>0) :
        m_cnt++;
        m_max=max(m_max,m_sum);
    if(m_cnt == m):
        res = min(res,m_max);
    if(m_cnt > m):
        s = mid+1;
    else if(m_cnt <= m):
        e = mid-1;

res 출력

*) 출력
(1) cout << "mid : "<< mid << ",s :" << s<<",e: "<<e<< endl;
(2) cout << "초과 : " << m_sum << "," ;
(3)
    (3-1) vector<int> nwLst;
    (3-2) nwLst.push_back(mp[i]);
    (3-3) nwLst.pop_back();
    (3-4)   
        while(!nwLst.empty()){
            cout << nwLst.back() << " " ;
            nwLst.pop_back();
        }
        cout << endl;
(4) cout <<endl<< "m_cnt : "<< m_cnt <<",max: "<<m_max<< endl;
*/