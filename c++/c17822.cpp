#include <bits/stdc++.h>
using namespace std;

int n,m,t,res;
vector<vector<int>> rc;
vector<pair<int,int>> _change;
void rotate(int i,int rl,int n){
    // 회전
    n%=m;
    if(rl==0){
        // 시계방;
        rotate(rc[i].begin(),rc[i].end()-n,rc[i].end());
    }
    else if(rl==1){
        // 반시계방향
        rotate(rc[i].begin(),rc[i].begin()+n,rc[i].end());
    }
}
void swap(int i,int j){
    // 인접 swap
    vector<pair<int,int>> lst;
    // 상 , 하
    int j1 = (j-1+m)%m; lst.push_back({i,j1});
    int j2 = (j+1+m)%m; lst.push_back({i,j2});
    // 좌 , 우
    int i1 =i-1; if(i-1>=0) lst.push_back({i1,j});
    int i2 =i+1; if(i+1<n) lst.push_back({i2,j});
    bool yn =false;
    for(int k=0;k<lst.size();k++){
         if(rc[i][j]==rc[lst[k].first][lst[k].second]){
            _change.push_back({lst[k].first,lst[k].second});
            yn =true;
         }
    }
    if(yn) _change.push_back({i,j});
}
void setAverage(){
    // 평균 계산 테스트
    int tot=0,cnt=0; double average=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(rc[i][j]==-1) continue;
            tot+=rc[i][j]; cnt ++;
        }
    }
    average = (double)tot/(double)cnt;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(rc[i][j]==-1) continue;
            if((double)rc[i][j] > average ) {
                rc[i][j]--;
            }
            else if((double)rc[i][j] < average ) {
                rc[i][j]++;
            }
        }
    }
}
int main(){

    cin >> n >> m >> t;
    for(int i=0;i<n;i++){
        vector<int> nw;
        for(int j=0;j<m;j++){
            int c; cin >> c;
            nw.push_back(c);
        }
        rc.push_back(nw);
    }
    while(t){
        // 처리
        int x,d,k;
        cin >> x >> d >> k;
        for(int i=x;i<=n;i+=x){
            // 원판 회전
            rotate(i-1,d,k);
            // 인접 x 처리
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(rc[i][j]!=-1){
                        swap(i,j);
                    }
                }
            }
            int size = _change.size();
            for(int i=0; i<size;i++){
                pair<int,int> el = _change.back();
                rc[el.first][el.second]=-1;
                _change.pop_back();
            }
            // 인접 x 처리 끝            
            // 평균 계산
            if(size==0){
                setAverage();
            }    
        t--;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(rc[i][j]==-1) continue;
            res+=rc[i][j];
        }
    }
    cout << res << endl;

    return 0;
}