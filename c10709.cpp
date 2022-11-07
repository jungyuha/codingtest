#include <bits/stdc++.h>
using namespace std;

int h,w; 
vector<char> mp1[100];
int lst[100];
int main(){

    cin >> h >> w;
    for(int i = 0;i<h;i++){
        for(int j=0;j<w;j++){
            char c;
            cin >> c;
            mp1[i].push_back(c);
        }
    }
    for(int i = 0; i<h ; i++){
        if(mp1[i][0] == 'c'){
            lst[0] = 0;
        }
        else{
            lst[0] = -1;
        }
        for(int j=1;j<w;j++){
            if(mp1[i][j]=='c'){
                lst[j]=0;
            }
            else if(lst[j-1] == -1){
                lst[j]=-1;
            }
            else{
                lst[j]=lst[j-1]+1;
            }
        }
        for(int j=0;j<w;j++){
            cout << lst[j] << " ";
        }
        cout << "\n";
        fill(lst,lst+100,0);
    }
    return 0;
}