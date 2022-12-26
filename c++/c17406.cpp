#include <bits/stdc++.h>
using namespace std;

int a,b,c,res=99999;
int mp[50][50];
int vis[6];
vector<tuple<int,int,int>> tu;

void func1(int tp[50][50],int k){
    if(k==c){ return ; }
    for(int i=0;i<c;i++){
        int dx = 1;int dy =0;
        if(vis[i]==1) continue;
        //(2) 
        int ly = get<0>(tu[i])-get<2>(tu[i])-1;
        int lx = get<1>(tu[i])-get<2>(tu[i])-1;
        int ry = get<0>(tu[i])+get<2>(tu[i])-1;
        int rx = get<1>(tu[i])+get<2>(tu[i])-1;
        int cx = lx;int cy = ly;
        //(3)
        int prev=tp[cy][cx]; int next;
        bool test = false;
        while(lx<=rx || ly <=ry){
            if(cx + dx > rx){// 오른쪽 부딪힘
                dx=0;dy=1;
            }
            if(cy + dy > ry){// 아래쪽 부딪힘
                dx=-1;dy=0;
            }
            if(cx + dx < lx){// 왼쪽 부딪힘
                dx=0;dy=-1;
            }

            if(cy + dy < ly){// 위쪽 부딪힘
                //(1)
               lx++;ly++;rx--;ry--;
               if(lx==rx && ly ==ry) break;
                cx = lx; cy = ly;
                dx=1;dy=0;prev=tp[cy][cx];next=0;
            }
            else{
                cx = cx+dx; cy = cy +dy;
                next = tp[cy][cx];
                tp[cy][cx] = prev;
                prev = next;
            }
        }
        // 배열값 구하기
        int m_res=9999;
        for(int j=0;j<a;j++){
            int m=0;
            for(int k=0;k<b;k++){
                m += tp[j][k];
            }
            m_res = min(m_res,m);
        }
        res = min(res,m_res);

        vis[i]=1;
        func1(tp,k+1);
        vis[i]=0;
    }

}
int main(){
    cin >> a >> b>> c;
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            cin >> mp[i][j];
        }
    }
    for(int i=0;i<c;i++){
        int aa,bb,cc;
        cin >> aa >> bb >> cc;
        tu.push_back(make_tuple(aa,bb,cc));
    }
    //(1)

    func1(mp,0);
    cout <<res<<endl;
    return 0;
}