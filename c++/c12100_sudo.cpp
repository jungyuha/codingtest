/*
0248 인거보니 비트연산자 문제인듯? 아닌가봄 ㅎㅎ;;
dfs로 풀어보자

*) 입력
4
4 2 2 0
0 2 0 0 
0 0 2 2
2 4 4 0

4
2 4 16 8
8 4 0 0 
16 8 2 0
2 8 2 0

4
2 4 8 2
2 4 0 0 
2 0 0 0
2 0 2 0
*) 메모리
int a,mp[20][20];
const int dx[]={0,1,0,-1};
const int dy[]={-1,0,1,0};
*) 시나리오

(func1)
void func1(int index,int tp[20][20],int k)
    if(index==k){
        맵 값 계산
    }
    (상하좌우 4순회) i=0;i<4;i++
        if 상 :
        else if 하 :
        else if 좌 :
        else if 우 :
        func1(index+1,tp,k)
(메인)
for(int i=1;i<=5;i++){ 최대 5번
    func1(0,mp,i);
}





*) 출력
(1) 
    cout<<"func1 :"<<index<<",k:"<<k<<endl;
(2)
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            cout << ttp[i][j] <<" ";
        }
        cout <<endl;
    }
(3)
cout<<"상:"<<index<<endl;
cout<<"하:"<<index<<endl;
cout<<"좌:"<<index<<endl;
cout<<"우:"<<index<<endl;
(4)
        for(int i=0;i<a;i++){
            for(int j=0;j<a;j++){
                cout << tp[i][j] <<" ";
            }
            cout <<endl;
        }
*/