/*
*) 입력
1
5 3
8 1 7 3 1 
3 6 1
*) 메모리
int t,n,m,a,b,aLst[20000],bLst[20000];
*) 시나리오
(b리스트 오름차순 정렬)
(a리스트 순회) int i=0;i<a;i++
    lower_bound(bLst,bLst+b,aLst[i])
    
*) 출력
(1)
            cout << endl << endl;
        for(int i=0;i<a;i++){
            cout << aLst[i] << " ";
        } cout << endl ;
        for(int i=0;i<b;i++){
            cout << bLst[i] << " ";
        } 
        cout << endl ;
(2)
cout << "m_cnt :" << m_cnt << " , res :"<< res<<endl;
*/