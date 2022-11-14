#include <bits/stdc++.h>
using namespace std;

string mp[10][10];
int vis[10][10];
int color[6]={0,5,5,5,5,5};
int tot,res;
int main(){

    for(int i =0;i<10;i++){
        for(int j=0;j<10;j++){
            cin >> mp[i][j];
            if(mp[i][j] == "1") tot++;
        }
    }
    // cout << "\n a \n";
    // for(int i =0;i<10;i++){
    //     for(int j=0;j<10;j++){
    //         cout << mp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n b \n";
    for(int a =5;a>0;a--){
        bool yn = true;
        for(int i =0;i<10;i++){
            for(int j=0;j<10;j++){
                yn = true;
                if(color[a] < 1) continue;
                for(int b=0;b<a;b++){
                    for(int c=0;c<a;c++){
                        if(mp[i+b][j+c] != "1"){
                            yn = false;
                        }
                    }
                    if(!yn) break;
                }
                if(yn){
                    //cout << "res : " << a << "\n";
                    res++;
                    for(int b=0;b<a;b++){
                        for(int c=0;c<a;c++){
                            mp[i+b][j+c]= to_string(a)+"!";
                        }
                    }   
                    color[a]--;
                    tot -=(a*a);
                }                
            }
        }        
        // mp[1][1]
        // bool yn = true;
        // if(color[a] < 1) continue;
        // for(int b=0;b<a;b++){
        //     for(int c=0;c<a;c++){
        //         if(mp[1+b][1+c] != "1"){
        //             yn = false;
        //         }
        //     }
        //     if(!yn) break;
        // }
        // if(yn){
        //     cout << "res : " << a << "\n";
        //     for(int b=0;b<a;b++){
        //         for(int c=0;c<a;c++){
        //             mp[1+b][1+c]= to_string(a)+"!";
        //         }
        //     }   
        //     color[a]--;
        //     tot -=(a*a);
        // }
    }
    // for(int i =0;i<10;i++){
    //     for(int j=0;j<10;j++){
    //         cout << mp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n b1 \n";
    if(tot==0){
        cout << res << "\n";
    }
    else{
        cout << "-1";
    }

    return 0;
}