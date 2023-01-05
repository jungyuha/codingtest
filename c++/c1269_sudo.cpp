/*
*) 입력
첫째 줄에 집합 A의 원소의 개수와 집합 B의 원소의 개수가 빈 칸을 사이에 두고 주어진다.
둘째 줄에는 집합 A의 모든 원소가, 셋째 줄에는 집합 B의 모든 원소가 빈 칸을 사이에 두고 각각 주어진다.
각 집합의 원소의 개수는 200,000을 넘지 않으며, 모든 원소의 값은 100,000,000을 넘지 않는다.
5 5
1 1 1 1 1
1 1 1 1 1

3 5
1 2 4
2 3 4 5 6
*) 메모리
int a,b,aLst[200000],bLst[200000],res;

*) 시나리오1 (이진탐색) => 함수명 :  goBiTree
(aLst,bLst 정렬)
int a_res=a,b_res=b;
(a순회) int i=0;i<a;i++
    int s=0,e=b-1,mid=0;
    while s <= e :
        mid = (s+e)/2;
        if(bLst[mid] == aList[i]) :
            a_res--;
            break;
        else if(bLst[mid] > aList[i]) :
            e = mid-1;
        else if(bLst[mid] < aList[i]) :
            s = mid+1;
(b순회) int i=0;i<b;i++
    int s=0,e=a-1,mid=0;
    while s <= e :
        mid = (s+e)/2;
        if(mid == bList[i]) :
            b_res--;
            break;
        else if(mid > bList[i]) :
            e = mid-1;
        else if(mid < bList[i]) :
            s = mid+1;
res = a_res+b_res;
*) 시나리오 1 출력
(1) cout << "a :"<< aLst[i]  << "a_res : "<< a_res <<endl;
(2) cout << " s :"<< s << ",e : "<<e<< ",mid : "<<mid<< ",b : "<<bLst[mid]<< endl;
(3) cout << "같음 : "<< aLst[i] << endl;
(4) cout << "a_res : "<< a_res <<endl;     
(5) cout << "b :"<< bLst[i]  << "b_res : "<< b_res <<endl;    
(6) cout << " s :"<< s << ",e : "<<e<< ",mid : "<<mid<< ",a : "<<aLst[mid]<< endl;
(7) cout << "같음 : "<< bLst[i] << endl;
(8) cout << "b_res : "<< b_res <<endl;

*) 시나리오2 (이진탐색 : lower_bound 함수 활용) => 함수명 : goBound
(aLst,bLst 정렬)
int a_res=a,b_res=b;
(a순회) int i=0;i<a;i++
    int index = lower_bound(bLst,bLst+b,aLst[i])-bLst;
    if(bLst[index] == aList[i]) :
        a_res--;
(a순회) int i=0;i<b;i++
    int index = lower_bound(aLst,aLst+a,bLst[i])-aLst;
    if(aLst[index] == bList[i]) :
        b_res--;
res = a_res+b_res;

*) 시나리오2 출력
(1) cout << "a :"<< aLst[i]  << "a_res : "<< a_res <<endl;
(2) cout << "a :"<< aLst[i]  << "b : "<< bLst[index] <<endl;
(3) cout << "같음 : "<< aLst[i] << endl;
(4) cout << "a_res : "<< a_res <<endl; 
(5) cout << "b :"<< bLst[i]  << "b_res : "<< b_res <<endl;
(6) cout << "b :"<< bLst[i]  << "a : "<< aLst[index] <<endl;
(7) cout << "같음 : "<< bLst[i] << endl;
(8) cout << "b_res : "<< b_res <<endl;     
*/