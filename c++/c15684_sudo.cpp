/*
// 세로선 갯수 , 현재사다리갯수,(세로선마다의 가능한)가로선 갯수
(a b c)
5 5 6
1 1
3 2
2 3
5 1
5 4
(세로선 좌표 , 세로선 번호)
*) 메모리
int pp[31][11] = { //[가로선(세로선좌표=level)][세로선번호] 
vector<pair<int,int>> tp; // 추가사다리 후보 목록(세로선좌표 , 세로선번호)
    0{0,0,0...},
    1{0,1,-1, 0,0,0},
    2{0,0, 0,1,-1,0..},
    3{0,0, 1,-1,0,0..},
    4{0,0, 0, 0,0,0..},
    5{0,1, -1,0,1,-1,.. },
    6{0,0, 0, 0,0, 0,..},
}
세로선 1
    가로선 1
    가로선 5

*)시나리오 - 사다리 타기 (1번 시작)
bool funcC()
세로선 int col =  1
level : 1 (현재위치)

(사다리 선택)
int col
while : 1
    int choose : 1;
    bool popYn=false;
    int next_col=0;
    while(choose<=c){  // 같은 사다리에서 이동
        if(choose >= level && (pp[choose][col]==1||pp[choose][col]==-1)){
            popYn = true;
            level = choose+1;
            if(pp[choose][col]==-1){
                next_col = col-1;
            }else if(pp[choose][col]==1){
                next_col = col+1;
            }
            col = next_col;
            break;
        }
        choose++;
    }
    if(!popYn) break;
int 도착 세로선 : col

*)시나리오 - 추가할 사다리 뽑기

1.추가할 수 있는 사다리 목록 => (세로선좌표 , 세로선번호)
(가로선순회) int i =1 ; i <= 가로선 점선 갯수(c) ;i++
    (세로선 순회) int j =1 ; j < a;j++
    if(pp[i][j]==0){
        tp.push_back({i,j});
    }

2.사다리 뽑기 조합
int min_ =1;
int res =0;
while : min_ <=t.size()
    funcA(min_)
    if(res > 0) break;
    min_++;

3.조합뽑기 함수
funcA(int start,int min_)
    if(start == min_){
        //사다리타기
        bool funcC
        if(funcC && res == 0) res = min_;
        return;
    }
    for(int i = start ; i<min_){
        cout << i<<tp[i].first<<tp[i].second << "pp:" << pp[tp[i].first][tp[i].second];
        pp[tp[i].first][tp[i].second] =1;
        pp[tp[i].first][tp[i].second+1] =-1;
        funcA(i+1,2);
    }

4. 조합출력 함수
funcB()


*) 사다리타기 단독 코드 
    // 사다리 타기
    int level =1;
    int col= 3;
    while(1){// 다른 사다리로 이동
        cout <<"level : "<<level<<", col :"<<col<<"\n";
        
        bool popYn = false;
        int choose = 1;
        int next_col=0;
        while(choose <= c){ // 같은 사다리에서 이동
            cout << "   choose : "<<choose <<",level : "<<level<<",pp[choose][col] :"<<pp[choose][col]<<"\n";
            if(choose >= level && (pp[choose][col]==1||pp[choose][col]==-1)){
                popYn=true;
                level = choose+1;
                if(pp[choose][col]==-1){
                    next_col = col-1;
                }else if(pp[choose][col]==1){
                    next_col = col+1;
                }
                col = next_col;
                cout << "       popYn : "<<popYn <<",level : "<<level<<",next_col :"<<next_col<<"\n";
                break;
            }
            choose++;
        }
        if(!popYn) break;
    }
    cout << "res col : "<< col <<"\n";
*/