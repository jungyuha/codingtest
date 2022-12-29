#include <bits/stdc++.h>
using namespace std;

int a,res;
int vis[100][100];
const int dx[]={0,0,-1,-1};
const int dy[]={0,-1,-1,0};
int main(){
    cin >> a;
    while(a){
        int x,y,d,t;
        int last=0,fx=0,fy=0;
        vector<int> lst;
        cin >> x >> y >> d >> t;
        int cx=x,cy=y;
        lst.push_back(d);

        if(d == 0 ){
            fx=cx+1;fy=cy;
        }
        else if(d == 1 ){
            fx=cx;fy=cy-1;
        } 
        else if(d == 2 ){
            fx=cx-1;fy=cy;
        } 
        else if(d == 3 ){
            fx=cx;fy=cy+1;
        }
        cout << fx<<","<<fy<<endl;
        vis[cy][cx]=1;
        vis[fy][fx]=1;
        while(t){ 
            last=lst.size()-1;
            for(int i=last;i>=0;i--){
                if(lst[i]==0){
                    lst.push_back(1);
                    fy--;
                }
                else if(lst[i]==1){
                    lst.push_back(2);
                    fx--;
                }
                else if(lst[i]==2){
                    lst.push_back(3);
                    fy++;
                }
                else if(lst[i]==3){
                    lst.push_back(0);
                    fx++;
                }
                vis[fy][fx]=1;
                cout << fx<<","<<fy<<endl;
            }
            t--;
        }
        for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<vis[i][j];
        }
        cout << endl;
    }
        a--;
    }
    for(int i=1;i<100;i++){
        for(int j=1;j<100;j++){
            bool yn = true;
            for(int k=0;k<4;k++){
                int nx = j+dx[k]; int ny = i + dy[k];
                if(vis[ny][nx]==0) {
                    yn = false;
                    break; ;
                }
            }
            if(yn) {
                cout<<"::"<<i<<","<<j<<endl;
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}