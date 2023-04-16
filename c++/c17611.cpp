#include<bits/stdc++.h>
using namespace std;
int n,arr_x[1000010],arr_y[1000010],max_x,max_y;
queue<pair<int,int>> q1;
vector<pair<int,int>> p_arr;
map<int,vector<pair<int,int>>> ver_arr,hor_arr; // start , end
void go(){
    cin >> n;
    int a,b,cx,cy,nx,ny;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        q1.push({a,b});
        //p_arr.push_back({a,b});
    }
    cx = q1.front().first; cy = q1.front().second; q1.pop();
    int fx , fy ; fx = cx ; fy = cy;
    while(!q1.empty()){
        nx = q1.front().first; ny = q1.front().second;
        if(nx==cx){ // 세로선 y_arr
            ver_arr[cx].push_back({cy,ny});
            arr_x[cx+500000]=-1;
            for(int i = min(cy,ny)+500000;i<=max(cy,ny)+500000;i++){
                if(arr_y[i]==-1) continue;
                arr_y[i]++;
                max_y = max(max_y,arr_y[i]);
            }
        }
        else if(ny==cy){  //  가로선 x_arr
            hor_arr[cy].push_back({cx,nx});
            arr_x[cy+500000]=-1;
            for(int i = min(cx,nx)+500000;i<=max(cx,nx)+500000;i++){
                if(arr_x[i]==-1) continue;
                arr_x[i]++;
                max_x = max(max_x,arr_x[i]);
            }
        }
        cx = nx; cy = ny; q1.pop();
    }
    if(fx==cx){ // 세로선 y_arr
        ver_arr[cx].push_back({cy,fy});
    }
    else if(fy==cy){  //  가로선 x_arr
        hor_arr[cy].push_back({cx,fx});
    }
    // for(auto el : ver_arr){
    //     cout << "x :: " <<el.first<<endl;
    //     for(pair<int,int> el2 : el.second){
    //         cout <<"    ("<< el.first<<","<<el2.first<<") ~ " << "(" <<el.first<<","<<el2.second<<")"<<endl;
    //     }
    // }
    // for(auto el : hor_arr){
    //     cout << "y :: " <<el.first<<endl;
    //     for(pair<int,int> el2 : el.second){
    //         cout <<"    ("<< el2.first<<","<<el.first<<") ~ " << "(" <<el2.second<<","<<el.first<<")"<<endl;
    //     }
    // }
}
int main(){
    go();
    cout << max(max_y,max_x)<<endl;
    return 0;
}