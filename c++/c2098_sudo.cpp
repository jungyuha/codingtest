/*
*) 입력
첫째 줄에 도시의 수 N이 주어진다.
(2 ≤ N ≤ 16) 다음 N개의 줄에는 비용 행렬이 주어진다.
각 행렬의 성분은 1,000,000 이하의 양의 정수이며, 갈 수 없는 경우는 0이 주어진다.
W[i][j]는 도시 i에서 j로 가기 위한 비용을 나타낸다.

예제 입력 1 
4
0 10 15 20
5 0 9 10
6 13 0 12
8 8 9 0

*) 메모리
const int INF=987654321;
int mp[16][16];
int n,c

*) 시나리오
int go(현재 위치)
    if 모두 방문한 경우 :
        원점으로 돌아가는 경로의 가중치를 리턴
    if 현재 경로로 부터 다음 경로까지의 가중치가 정해져있는 경우(DP):
        저장된 가중치값을 리턴
    (현재 점으로 부터 순회할 수 있는 모든 경우를 순회)
        이미 방문한 경우 PASS
        다음 경로가 없는 경우 PASS
        res = min(res,go(다음 위치)+현재 위치의 가중치)
    return res
*) 기타
기존 : (1<<2)
3번째 비트 켜기 :
(1<<2)|(1<<3)
3번째 비트 끄기 :
(1<<2)&~(1<<3)
3번째 비트 켜져있는지 확인:
(1<<2) & (1<<idx)
4칸을 1로 다채우기 :
((1<<5)-1)

*) 순회 방법
예시 : a , b ,c 세 도시가 있다.
각 순회마다 시작점이 어딘지는 고려할 필요가 없다.
순회 1 : 
    a - b - c - a
순회 2 :
    a - c - b - a


*) 출력
    int a =4;
        for(int j=1;j<=a;j++){
            if(((1<<2)&~(1<<3))&(1<<j)){
                cout << "1 "; 
            }
            else{cout << "0 ";}
        }
        cout <<"\n";
*/