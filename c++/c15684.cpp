#include <bits/stdc++.h>
using namespace std;

int a,b,c,res; // a: 세로선 갯수 , b:사다리갯수 ,c: 가로선갯수(점선)
int pp[31][11];
vector<pair<int,int>> tp; // 추가사다리 후보 목록(세로선좌표 , 세로선번호)
bool funcC(){// 사다리타기
cout <<"사다리타기 \n";
    bool resYn = true;
    for(int i=1;i<=a;i++){
        // 사다리 타기
        int col= i; // 시작 지점
        int res_ =0; // 결과
        int level =1;
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
        res_ = col; cout << "res col : "<< col <<"\n";
        if(res_!=i){
            resYn = false;
            break;
        }
    }
    return resYn;
}
void funcA(int start,int min_){
    if(start == min_){
        //사다리타기
        bool yn = funcC();
        if(yn && res == 0) res = min_;
        return;
    }
    for(int i = start ; i<min_;i++){
        cout <<"choose :"<<i<<",tp :"<<tp[i].first<<","<<tp[i].second << "\n" ;
        pp[tp[i].first][tp[i].second] =1;
        pp[tp[i].first][tp[i].second+1] =-1;
        funcA(i+1,2);
    }
}
int main(){

    cin >> a >> b >> c;
    for(int i=0;i<b;i++){
        int m,n;
        cin >> m >> n; // m : 세로선좌표(level) , n : 세로선 번호
        pp[m][n]=1;
        pp[m][n+1]=-1;
    }
    for(int i=1;i<=c;i++){
        for(int j=1;j<a;j++){
            if(pp[i][j]==0){
                tp.push_back({i,j});
            }
        }
    }
    
    int min_=0;
    while (min_ <= tp.size()){
        cout << "min_ :"<<min_<<",tp.size():" <<tp.size()<<"\n";
        funcA(0,min_);
        cout << "res :"<<res<<"\n";
        if(res > 0) break;
        min_++;
    }

    return 0;
}
/*
*) 출력
1.pp
for(int i=1;i<=c;i++){
        for (int j = 1; j <= a; j++)
        {
            cout << pp[i][j];
        }
        cout << "\n";
    }
2.tp
for(pair<int,int> el : tp){
        cout << "el1:"<<el.first<<",el2:"<<el.second<<"\n";
    }
*/