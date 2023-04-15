#include<bits/stdc++.h>
using namespace std;
int n;
queue<pair<int,int>> q1;
vector<pair<int,int>> p_arr;
map<int,vector<pair<int,int>>> ver_arr,hor_arr; // start , end
void init(){
    cin >> n;
    int a,b,cx,cy,nx,ny;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        q1.push({a,b});
        //p_arr.push_back({a,b});
        //x_arr[a].push_back(b); y_arr[b].push_back(a);
    }
    cx = q1.front().first; cy = q1.front().second; q1.pop();
    int fx , fy ; fx = cx ; fy = cy;
    while(!q1.empty()){
        nx = q1.front().first; ny = q1.front().second;
        if(nx==cx){ // 세로선 y_arr
            ver_arr[cx].push_back({cy,ny});
        }
        else if(ny==cy){  //  가로선 x_arr
            hor_arr[cy].push_back({cx,nx});
        }
        cx = nx; cy = ny; q1.pop();
    }
    if(fx==cx){ // 세로선 y_arr
        ver_arr[cx].push_back({cy,fy});
    }
    else if(fy==cy){  //  가로선 x_arr
        hor_arr[cy].push_back({cx,fx});
    }
    for(auto el : ver_arr){
        cout << "x :: " <<el.first<<endl;
        for(pair<int,int> el2 : el.second){
            cout <<"    ("<< el.first<<","<<el2.first<<") ~ " << "(" <<el.first<<","<<el2.second<<")"<<endl;
        }
    }
    for(auto el : hor_arr){
        cout << "y :: " <<el.first<<endl;
        for(pair<int,int> el2 : el.second){
            cout <<"    ("<< el2.first<<","<<el.first<<") ~ " << "(" <<el2.second<<","<<el.first<<")"<<endl;
        }
    }
}
int main(){
    init();
    return 0;
}