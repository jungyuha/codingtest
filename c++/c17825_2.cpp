#include <bits/stdc++.h>
using namespace std;
/*lst[1]={2} lst[2]={3} .. lst[5]={6,21} .. lst[20]={-1} lst[21]=22 lst[22]=23 lst[23]=26 lst[24]=25 lst[25]=26 lst[26]=30 lst[27]=28 lst[28]=29
lst[29]=26 lst[30]=31 lst[31]=20*/
/* 2(mp[1]) 4(=mp[2]) 6 8 10(mp[5]) 12(mp[6]) 14 16 18 20 22 24 26 28 30 32 34 36 38 40(mp[20])
 13(mp[21]) 16(22) 19(23) 22(mp[24]) 24(25) 25(26) 28(27) 27(28) 26(29) 30(30) 35(31) */
//mp2[5]=21 , mp2[15]=27 , mp2[10]=24
vector<int> lst[32]; // 인접리스트
vector<int> mp; // 각 위치의 점수
map<int,int> mp2;
int mal[4]; // 각 말의 위치
int cb[10]={1,4,1,4,1,2,3,4,1,2}; // 주사위 수
int score;
void dfs(int lvl){
    if(lvl == 3){
        cout << "\n";
        return;
    }
    for(int i =0;i<4;i++){
        int prev = mal[i];
        if(mp2.find(mal[i])!=mp2.end()){
            mal[i]=mp2[mal[i]]+cb[lvl]-1;
        }
        else{
            mal[i]=mal[i]+cb[lvl];
        }
        score = score + mp[mal[i]];
        cout << "["<<lvl << " : " << i << "," << mal[i] << "," << score << "("<<mp[mal[i]] << ")]" ;
        dfs(lvl+1);
        score = score - mp[mal[i]];
        mal[i]=prev;
        
    }
}
int main(){
    for(int i = 0;i<=19;i++){
        lst[i].push_back(i+1);
    }
    lst[20].push_back(-1); lst[21].push_back(22); lst[22].push_back(23); lst[23].push_back(26);
    lst[24].push_back(25); lst[25].push_back(26); lst[26].push_back(30); lst[27].push_back(28); lst[28].push_back(29);
    lst[29].push_back(26); lst[30].push_back(31); lst[31].push_back(20);

    mp.push_back(0);
    for(int i = 1;i<=20;i++){
        mp.push_back(2*i);
    }
    mp[21]=13;mp[22]=16;mp[23]=19;mp[24]=22;mp[25]=24;mp[26]=25;mp[27]=28;mp[28]=27;mp[29]=26;mp[30]=30;mp[31]=35;
    mp2[5]=21; mp2[15]=27; mp2[10]=24;

   dfs(0);
        /* 말 선택 => a : 0 / b : 1 / c : 2 / d : 3
    말의 위치 => mal[a] / mal[b] / mal[c] / mal[d]
    말의 위치에 있는 점수 => mp[mal[a]] / mp[mal[b]] / mp[mal[c]] / mp[mal[d]]
    주사위 값 => cp[lvl]
    주사위 1(lvl : 0) => [말 종류] a(=0)  / (여기까지)!!!!만약 lst[mal[a]].size()>1 가 존재한다면 [새로운 말의 위치 = 원래 위치 + 주사위 수] mal[a] = lst[mal[a]][1] + cp[lvl] -1 , 아니면 [새로운 말의 위치 = 원래 위치 + 주사위 수] mal[a] = mal[a] + cp[lvl] 
                        / [총 점수 = 기존 점수 + 새로운 말의 위치의 점수] score = score + mp[mal[a] + cp[lvl]] => 만약 mp2[mal[a] + cp[lvl]]가 존재한다면 [총 점수 = 기존 점수 + 새로운 말의 위치의 점수] score = score + mp[mp2[mal[a] + cp[lvl]].second + cp[lvl] -1]
        주사위 2(lvl : 1) : a => [말 종류] a(=0)  
            주사위 3(lvl :2): a => [말 종류] a(=0) 
            주사위 3: b(1) => [말 종류] b(=1)
            주사위 3: c
            주사위 3: d
                score = score - mp[mal[d] + cp[lvl]]
            score = score - mp[mal[a] + cp[lvl]]
    */
    //lvl : 0
    // for(int i=0;i<4;i++){
    //     mal[i]=mal[i]+cb[0];
    //     score = score + mp[mal[i]];
    //     cout << "[" << i << "," << mal[i] << "," << score << " ]" ;
    //     mal[i]=mal[i]-cb[0];
    //     score = score - mp[mal[i]];    
    //     // lvl : 1
    //     for(int j=0;j<4;i++){
    //         mal[j]=mal[j]+cb[1];
    //         score = score + mp[mal[i]];
    //         cout << "[" << i << "," << mal[i] << "," << score << " ]" ;
    //             score = score - mp[mal[i]];
    //             mal[j]=mal[j]-cb[1];
    //         // lvl : 2
    //         for(int k=0;k<4;k++){
    //             mal[k]=mal[k]+cb[2];
    //             score = score + mp[mal[k]];
    //             cout << "[" << k << "," << mal[k] << "," << score << " ]" ;
    //             score = score - mp[mal[k]];
    //             mal[k]=mal[k]-cb[2];
    //             // lvl : 3
    //             //return ;
    //         }
    //         score = score - mp[mal[i]];
    //     }
    // }
    cout << "a \n";
    // for(int i=1;i<=31;i++){
    //     cout << mp[i] << " ,";
    // }
    cout << "a1 \n";
        //case 1 : 주사위 수 3개 (1,2,3)
    /* 말 선택 => a : 0 / b : 1 / c : 2 / d : 3
    주사위 1(lvl : 0) : a(0)
        주사위 2(lvl : 1) : a
            주사위 3(lvl :2): a
            주사위 3: b(1)
            주사위 3: c
            주사위 3: d
        주사위 2 : b(1)
            주사위 3: a
            주사위 3: b
            주사위 3: c
            주사위 3: d
        주사위 2 : c(2)
            주사위 3: a
            주사위 3: b
            주사위 3: c
            주사위 3: d
        주사위 2 : d
            주사위 3: a
            주사위 3: b
            주사위 3: c
            주사위 3: d
    주사위 1 : b
        주사위 2 : a
            주사위 3: a
            주사위 3: b
            주사위 3: c
            주사위 3: d
        주사위 2 : b
            주사위 3: a
            주사위 3: b
            주사위 3: c
            주사위 3: d
        주사위 2 : c
            주사위 3: a
            주사위 3: b
            주사위 3: c
            주사위 3: d
        주사위 2 : d(3)
            주사위 3: a
            주사위 3: b
            주사위 3: c
            주사위 3: d    
    */
    cout << "a2 \n";
        //lvl : 0 , i는 말의 고유번호
    // for(int i=0;i<4;i++){
    //     cout << i << " ";
    //     // lvl : 1
    //     for(int j=0;j<4;i++){
    //         cout << j << " ";
    //         // lvl : 2
    //         for(int k=0;k<4;k++){
    //             cout << k << " ";
    //             // lvl : 3
    //             //return ;
    //         }
    //     }
    // }
    cout << "a3 \n";
        /* 말 선택 => a : 0 / b : 1 / c : 2 / d : 3
    말의 위치 => mal[a] / mal[b] / mal[c] / mal[d]
    말의 위치에 있는 점수 => mp[mal[a]] / mp[mal[b]] / mp[mal[c]] / mp[mal[d]]
    주사위 값 => cp[lvl]
    주사위 1(lvl : 0) => [말 종류] a(=0)  / [새로운 말의 위치 = 원래 위치 + 주사위 수] mal[a] = mal[a] + cp[lvl] / [총 점수 = 기존 점수 + 새로운 말의 위치의 점수] score = score + mp[mal[a] + cp[lvl]]
        주사위 2(lvl : 1) : a => [말 종류] a(=0)  / [새로운 말의 위치 = 원래 위치 + 주사위 수] mal[a] = mal[a] + cp[lvl] / [총 점수 = 기존 점수 + 새로운 말의 위치의 점수] score = score + mp[mal[a] + cp[lvl]]
            주사위 3(lvl :2): a => [말 종류] a(=0)  / [새로운 말의 위치 = 원래 위치 + 주사위 수] mal[a] = mal[a] + cp[lvl] / [총 점수 = 기존 점수 + 새로운 말의 위치의 점수] score = score + mp[mal[a] + cp[lvl]]
                score = score - mp[mal[a] + cp[lvl]]
            주사위 3: b(1) => [말 종류] b(=1)  / [새로운 말의 위치 = 원래 위치 + 주사위 수] mal[b] = mal[b] + cp[lvl] / [총 점수 = 기존 점수 + 새로운 말의 위치의 점수] score = score + mp[mal[b] + cp[lvl]]
            주사위 3: c
            주사위 3: d
                score = score - mp[mal[d] + cp[lvl]]
            score = score - mp[mal[a] + cp[lvl]]
        주사위 2 : b(1)
            주사위 3: a
            주사위 3: b
            주사위 3: c
            주사위 3: d
        주사위 2 : c(2)
            주사위 3: a
            주사위 3: b
            주사위 3: c
            주사위 3: d
        주사위 2 : d
            주사위 3: a
            주사위 3: b
            주사위 3: c
            주사위 3: d   
    */
   //lvl : 0
    // for(int i=0;i<4;i++){
    //     mal[i]=mal[i]+cb[0];
    //     score = score + mp[mal[i]];
    //     cout << "[" << i << "," << mal[i] << "," << score << " ]" ;
    //     mal[i]=mal[i]-cb[0];
    //     score = score - mp[mal[i]];    
    //     // lvl : 1
    //     for(int j=0;j<4;i++){
    //         mal[j]=mal[j]+cb[1];
    //         score = score + mp[mal[i]];
    //         cout << "[" << i << "," << mal[i] << "," << score << " ]" ;
    //             score = score - mp[mal[i]];
    //             mal[j]=mal[j]-cb[1];
    //         // lvl : 2
    //         for(int k=0;k<4;k++){
    //             mal[k]=mal[k]+cb[2];
    //             score = score + mp[mal[k]];
    //             cout << "[" << k << "," << mal[k] << "," << score << " ]" ;
    //             score = score - mp[mal[k]];
    //             mal[k]=mal[k]-cb[2];
    //             // lvl : 3
    //             //return ;
    //         }
    //         score = score - mp[mal[i]];
    //     }
    // }
    cout << "a4 \n";
    /* 말 선택 => a : 0 / b : 1 / c : 2 / d : 3
    말의 위치 => mal[a] / mal[b] / mal[c] / mal[d]
    말의 위치에 있는 점수 => mp[mal[a]] / mp[mal[b]] / mp[mal[c]] / mp[mal[d]]
    주사위 값 => cp[lvl]
    주사위 1(lvl : 0) => [말 종류] a(=0)  / 만약 mp2[mal[a]]가 존재한다면 [새로운 말의 위치 = 원래 위치 + 주사위 수] mal[a] = mp2[mal[a]].second + cp[lvl] -1 , 아니면 [새로운 말의 위치 = 원래 위치 + 주사위 수] mal[a] = mal[a] + cp[lvl] 
                        / [총 점수 = 기존 점수 + 새로운 말의 위치의 점수] score = score + mp[mal[a] + cp[lvl]] => 만약 mp2[mal[a] + cp[lvl]]가 존재한다면 [총 점수 = 기존 점수 + 새로운 말의 위치의 점수] score = score + mp[mp2[mal[a] + cp[lvl]].second + cp[lvl] -1]
        주사위 2(lvl : 1) : a => [말 종류] a(=0)  
            주사위 3(lvl :2): a => [말 종류] a(=0) 
            주사위 3: b(1) => [말 종류] b(=1)
            주사위 3: c
            주사위 3: d
                score = score - mp[mal[d] + cp[lvl]]
            score = score - mp[mal[a] + cp[lvl]]
    */
    return 0;
}