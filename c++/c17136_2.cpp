#include <bits/stdc++.h>
using namespace std;

const int INF = 987;
int vis[10][10],mp[10][10],mp2[10][10],depth;
int paper[6]={0,5,5,5,5,5};
vector<pair<int,int>> pLst;
void showVis(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout << vis[i][j] << " ";
        }
        cout << endl;
    }
}
void showMp(){
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout << mp2[i][j] << " ";
        }
        cout << endl;
    }
}
void showPaper(){
    for(int i=1;i<6;i++){
        cout << paper[i] << " ";
    }
    cout << endl;
}
void draw (int cy , int cx ,int k,int d){
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            vis[cy+i][cx+j]=d;
        }
    }
    //showVis();
}
bool drawTest(int cy , int cx , int k){
    bool yn = true;
    if(paper[k]==0) { return false; }
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            if(vis[cy+i][cx+j]==1 || mp2[cy+i][cx+j]==0 || cy+i < 0 || cx+j <0 || cy+i >= 10 || cx+j >= 10) {
                //cout << "2 : " <<cy+i<<","<<cx+j<<"=>"<<mp[cy+i][cx+j]<< endl;
                yn = false;
                break;
            }
        }
    }
    if(yn){
        draw(cy,cx,k,1);  
    }
    else{ // 그래프 원복
        draw(cy,cx,k,0);
    }
    return yn;
}
int goTest(int idx){
    //showVis();
    //cout << "go : "<<pLst[idx].first<<","<<pLst[idx].second <<"("<<idx<<")"<< endl;
    if(idx >= pLst.size()) return 0;
    int ret = INF;
    for(int i=1;i<=5;i++){
        //cout << "i : "<<i <<"("<<idx<<")"<< endl;
        if(drawTest(pLst[idx].first,pLst[idx].second,i)){
            //cout << "성공 ! " << endl;
            paper[i]--;
            // 작업중
            int new_idx=0;
            for(new_idx=idx+1;new_idx<pLst.size();new_idx++){
                // cout << "vis :: "<<pLst[new_idx].first<<","<<pLst[new_idx].second<<":"<<vis[pLst[new_idx].first][pLst[new_idx].second]<<endl;
                if(vis[pLst[new_idx].first][pLst[new_idx].second]==0) break;
            }   
            //cout << "new_idx : "<<new_idx << endl<<endl;
            ret=min(ret,goTest(new_idx)+1);
            //ret = min(ret,goTest(new_idx)) + 1;
            //cout << "idx : "<<idx <<",ret :"<<ret<< endl;
            // 작업중
            // 원복
            draw(pLst[idx].first,pLst[idx].second,i,0);
            paper[i]++;
        }
        else{
            //cout << "실패 ! "<<endl;
          //  if(idx==0) showMp(); // showPaper(); // showVis();
        }
        //showPaper();
        //ret = min(ret,);
    }
    return ret;
}
int dfs(int idx){
    vector<int> temp;
    cout << "dfs : "<<idx << endl;
    if(idx==pLst.size()){
        // 방문 가능할 점이 이제 없거나
        return 0;
    }
    int ret=0,new_idx=idx+1;
    // 자기칸 색칠 1칸
    int ret1=0;
    if(drawTest(pLst[idx].first,pLst[idx].second,1)){
        // 색칠 성공하면
        cout << "성공("<<idx+1<<"):1"<<endl;
        //showVis();
        paper[1]--;
        while(new_idx<pLst.size()){
            if(vis[pLst[new_idx].first][pLst[new_idx].second]==0) break; // 방문 가능하면 break
            new_idx++;
        }
        ret1 = 1;
        ret1 += dfs(new_idx);// 방문 가능하거나 또는 방문 가능할 점이 이제 없거나
        
        // 방문 마치면 다시 원복
        draw(pLst[idx].first,pLst[idx].second,1,0);
        paper[1]++; 
    }
    else{
        // 색칠 실패하면
        cout << "실패("<<idx+1<<"):1"<<endl;
        ret1 = INF;
    }
    temp.push_back(ret1);
   // cout << "end => idx:"<<idx+1<<",1 : "<<ret1<<endl;

    // 자기칸 색칠 2칸
    int ret2=0;
    if(drawTest(pLst[idx].first,pLst[idx].second,2)){
        // 색칠 성공하면
        //cout << "성공("<<idx+1<<"):2"<<endl;
        //showVis();
        paper[2]--;
        while(new_idx<pLst.size()){
            if(vis[pLst[new_idx].first][pLst[new_idx].second]==0) break; // 방문 가능하면 break
            new_idx++;
        }
        ret2 = 1;
        ret2 += dfs(new_idx);// 방문 가능하거나 또는 방문 가능할 점이 이제 없거나
        
        // 방문 마치면 다시 원복
        draw(pLst[idx].first,pLst[idx].second,2,0);
        paper[2]++; 
    }
    else{
        // 색칠 실패하면
        //cout << "실패("<<idx+1<<"):2"<<endl;
        ret2 = INF;
    }
    temp.push_back(ret2);
    //cout << "end => idx:"<<idx+1<<",2 : "<<ret2<<endl;
    
    // 자기칸 색칠 3칸
    int ret3=0;
    if(drawTest(pLst[idx].first,pLst[idx].second,3)){
        // 색칠 성공하면
        cout << "성공("<<idx+1<<"):3"<<endl;
        if(idx==18) {showVis();depth=18;} else {depth=0;}
        paper[3]--;
        while(new_idx<pLst.size()){
            if(vis[pLst[new_idx].first][pLst[new_idx].second]==0) break; // 방문 가능하면 break
            new_idx++;
        }
        if(idx==18) cout << "new_idx("<<idx+1<<"):"<<new_idx<<endl;
        ret3 = 1;
        ret3 += dfs(new_idx);// 방문 가능하거나 또는 방문 가능할 점이 이제 없거나
        if(idx==18) cout << "new_idx2("<<idx+1<<"):"<<new_idx<<endl;
        // 방문 마치면 다시 원복
        draw(pLst[idx].first,pLst[idx].second,3,0);
        paper[3]++; 
    }
    else{
        // 색칠 실패하면
        cout << "실패("<<idx+1<<"):3"<<endl;
        ret3 = INF;
    }
    temp.push_back(ret3);
    cout << "end => idx:"<<idx+1<<",3 : "<<ret3<<endl;
    // 자기칸 색칠 4칸~!
    int ret4=0;
    if(drawTest(pLst[idx].first,pLst[idx].second,4)){
        // 색칠 성공하면
        //cout << "성공("<<idx+1<<"):4"<<endl;
        paper[4]--;
        while(new_idx<pLst.size()){
            if(vis[pLst[new_idx].first][pLst[new_idx].second]==0) break; // 방문 가능하면 break
            new_idx++;
        }
        ret4 = 1;
        ret4 += dfs(new_idx);// 방문 가능하거나 또는 방문 가능할 점이 이제 없거나
        
        // 방문 마치면 다시 원복
        draw(pLst[idx].first,pLst[idx].second,4,0);
        paper[4]++; 
    }
    else{
        // 색칠 실패하면
        //cout << "실패("<<idx+1<<"):4"<<endl;
        ret4 = INF;
    }
    temp.push_back(ret4);
    cout << "end => idx:"<<idx+1<<",4 : "<<ret4<<endl;
    // 자기칸 색칠 5칸~!
    int ret5=0;
    if(idx==22) {cout << "hi"; showVis();}
    if(drawTest(pLst[idx].first,pLst[idx].second,5)){
        // 색칠 성공하면
        cout << "성공("<<idx+1<<"):5"<<endl;
        if(idx==22) showVis();
        paper[5]--;
        while(new_idx<pLst.size()){
            if(vis[pLst[new_idx].first][pLst[new_idx].second]==0) break; // 방문 가능하면 break
            new_idx++;
        }
        ret5 = 1;
        ret5 += dfs(new_idx);// 방문 가능하거나 또는 방문 가능할 점이 이제 없거나
        
        // 방문 마치면 다시 원복
        draw(pLst[idx].first,pLst[idx].second,5,0);
        paper[5]++; 
    }
    else{
        // 색칠 실패하면
        cout << "실패("<<idx+1<<"):5"<<endl;
        ret5 = INF;
    }
    temp.push_back(ret5);
    cout << "end => idx:"<<idx+1<<",5 : "<<ret5<<endl;
    sort(temp.begin(),temp.end());

    return temp[0];
}

int main(){
    int c;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cin >> c;
            mp[i][j]=c;mp2[i][j]=c;
            if(c==1) pLst.push_back({i,j}); // 행,열
        }
    }
    
    //vis[2][2]=1;
    //drawTest(5,5,5);
    //int res=goTest(0);
    int res = dfs(0);
    cout << res << endl;
    return 0;
}
/*
0 0 0 0 0 0 0 0 0 0
0 1 1 0 0 0 0 0 0 0
0 1 1 0 0 0 0 0 0 0
0 0 0 0 1 1 0 0 0 0
0 0 0 0 1 1 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0

0 0 0 0 0 0 0 0 0 0
0 1 1 1 1 1 0 0 0 0
0 1 1 1 1 1 0 0 0 0
0 1 1 1 1 1 0 0 0 0
0 1 1 1 1 1 0 0 0 0
0 1 1 1 1 1 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
*/