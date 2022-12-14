/*
*) 입력
9
5 12 7 10 9 1 2 3 11
13
*) 메모리
int a,p1,p2,x;
vector<int> lst;

*) 시나리오
lst 오름차순 정렬
p1=0;p2=a-1;
(l<r 반복)
    if  lst[p1]+lst[p2] == x :
        p2--;
        res++;
    else if lst[p1]+lst[p2] > x :
        p2-- ;
    else if lst[p1]+lst[p2] < x :
        p1++ ;    

*/