/*
*) 입력
6
10 20 10 30 20 50
*) 메모리
int a;
vector<int> lst;
*) 시나리오
lst : 10 20 10 30 20 50
rnk :  1  2  1  3  2  4

rnk a만큼 1로 초기화

(lst 순회) int i=0;i<a;i++
    (lst 순회) int j=0;j<i;j++
        if(lst[i]>lst[j] && rnk[i] < rnk[j]+1){
            rnk[i]=rnk[j]+1;
        }

*) 출력

*/