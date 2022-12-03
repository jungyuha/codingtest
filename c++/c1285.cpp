#include <bits/stdc++.h>
using namespace std;

int a,cur,min_ = 999,n;
char mp[20][20];
pair<int,int> pp[40][20]; //{y,x}
int vis[20][20]; //{y,x}
int main(){

    cin >> a;
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            cin >> mp[i][j];
            if(mp[i][j]=='T') {cur++;}
        }
    }

    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            pp[i][j]={i,j};
        }
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            pp[i+a][j] = {j,i};
        }
    }
    n = 2*a;

    for(int i=1;i<=pow(2,n);i++){
        //cout <<"i : "<<i<<"\n";
        memset(vis,0,sizeof(vis));
        int temp=cur;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                for(int k=0;k<a;k++){
                    char c=mp[pp[j][k].first][pp[j][k].second];
                    //cout <<"pp["<<j<<"]["<<k<<"] : "<<"("<< pp[j][k].first<<","<<pp[j][k].second<<")";
                    //cout << ", vis : "<< vis[pp[j][k].first][pp[j][k].second];
                    if(vis[pp[j][k].first][pp[j][k].second]%2!=0){
                        if(c=='T'){
                            c= 'H';
                        }
                        else{
                            c = 'T';
                        }
                    }
                    //cout << ", c :" << c;
                    if(c=='H'){
                        temp++;
                    }
                    else if(c=='T'){
                        temp--;
                    }
                    //cout << ", temp :" << temp<< "\n";
                    vis[pp[j][k].first][pp[j][k].second]++;
                }
            }
        }
        if (temp < min_ && temp >=2 ) {
            min_ =temp;
            //cout << "min_ : " << min_;
        }
    }
cout  << min_;
    return 0;
}