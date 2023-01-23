#include<bits/stdc++.h>
using namespace std;

int n,m,k,x,y,z;
const int dx[]={-1,0,1,1,1,0,-1,-1};
const int dy[]={-1,-1,-1,0,1,1,1,0};
int mp[11][11],cp[11][11]; // 현재 양분 정보
vector<int> tree[11][11];

void springSummer(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){ // 땅 순회
            sort(tree[i][j].begin(),tree[i][j].end()); // 오름차순 순회 (작은 애들 부터)
            vector<int> temp;
            int add_=0;
            if(tree[i][j].size()>0){
                for(int c=0;c<tree[i][j].size();c++){ // 1칸 안에 있는 나무들 순회 ()
                    cout << "("<<i<<","<<j<<")현재 땅 양분 : "<<mp[i][j]<<endl;
                    cout << "("<<i<<","<<j<<")나무 나이 : "<<tree[i][j][c]<<endl;
                    if(mp[i][j]-tree[i][j][c]>=0){ // 나무 양분 - 나무 나이 > 0
                        mp[i][j]-=tree[i][j][c];    // 양분 뽑아먹고
                        temp.push_back(tree[i][j][c]+1); // 나이 먹고ㅎㅎ(ㅠㅠ)
                        cout << "("<<i<<","<<j<<")뽑아먹은 후 양분: "<<mp[i][j]<<endl;
                    }
                    else{
                        add_+=(tree[i][j][c]/2);
                        cout << "("<<i<<","<<j<<")죽은 후 양분 플러스: "<<add_<<endl;
                    }
                }
                tree[i][j] = temp;  // 갈아끼웟 (죽은 나무 치웟)
                mp[i][j]+=add_; // 죽은 나무의 양분 더하기
                cout << "("<<i<<","<<j<<")=======결과========"<<endl;
                for(int c =0;c<tree[i][j].size();c++){  // 나무 순회
                cout << "나무 나이 : "<<tree[i][j][c]<<endl;
                }
                cout << "땅 양분 :"<<mp[i][j]<<endl;
            }
        }
    }
}
void fallWinter(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){ // 땅 순회
            if(tree[i][j].size()>0){
                for(int c=0;c<tree[i][j].size();c++){ // 1칸 안에 있는 나무들 순회 ()
                    // cout << "("<<i<<","<<j<<")나무 나이 : "<<tree[i][j][c]<<endl;
                    if(tree[i][j][c]%5==0){// 5의 배수일때만 번식
                        cout << "("<<i<<","<<j<<")5의 배수 나무 나이 : "<<tree[i][j][c]<<endl;
                        for(int d=0;d<8;d++){
                            int nx = j + dx[d]; int ny = i + dy[d];
                            if(nx<1||ny<1||nx>n||ny>n) continue;
                            cout << "("<<ny<<","<<nx<<")새로운 땅 위치"<<endl;
                            tree[ny][nx].push_back(1);
                        }
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            mp[i][j]+=cp[i][j];
        }
    }
}
int go_cnt(){ // 
    int res = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){ // 땅 순회
            if(tree[i][j].size()>0){
                res += tree[i][j].size();
            }
        }
    }    
    return res;
}
int main(){
    cin >> n >> m >> k ;
    fill(&mp[0][0],&mp[0][0]+10*10,5);
    
    for(int i =1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> cp[i][j];
        }
    }
    for(int i=1;i<=m;i++){
        cin >> x >> y >> z;     // x : 행 , y : 열
        tree[x][y].push_back(z);
    }
    for(int i=0;i<k;i++){
        springSummer();
        fallWinter();
    }
    int ret = go_cnt();
    cout << ret << endl;
    return 0;
}