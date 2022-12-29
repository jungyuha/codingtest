/*
*) 입력
10
10 -4 3 1 5 6 -35 12 21 -1
*) 메모리
int a;
vector <int> lst;
*) 시나리오
(순회 : i개 뽑기) i=1;i<=a;i++
    (lst 순회 : 제일 첫번째 수) j=0;j<a;j++
        if (j+i>a) break;
        (i개 연속 뽑기) k = j ; k <  j+i ; k++
            합계산



*) 출력
(1)
cout << i<<"개 뽑기" << endl; 
(2)
cout <<"제일 첫번째 인덱스 : "<<j << "=>"; 
(3)
cout << k << " "; 
(4)
cout << endl;
*) 기타
*/