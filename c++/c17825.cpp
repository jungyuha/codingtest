#include <bits/stdc++.h>
using namespace std;
/*lst[1]={2} lst[2]={3} .. lst[5]={6,21} .. lst[20]={-1} lst[21]=22 lst[22]=23 lst[23]=26 lst[24]=25 lst[25]=26 lst[26]=30 lst[27]=28 lst[28]=29
lst[29]=26 lst[30]=31 lst[31]=20*/
/* 2(mp[1]) 4(=mp[2]) 6 8 10(mp[5]) 12(mp[6]) 14 16 18 20 22 24 26 28 30 32 34 36 38 40(mp[20])
 13(mp[21]) 16(22) 19(23) 22(mp[24]) 24(25) 25(26) 28(27) 27(28) 26(29) 30(30) 35(31) */
//mp2[5]=21 , mp2[15]=27 , mp2[10]=24
vector<int> lst[32]; // 인접리스트
vector<int> mp; // 각 위치의 점수 (말 아이디 , 위치 인덱스)
tuple<int,int,int> history[11];//위치 히스토리
map<int,int> mp2;
int mal[4]; // 각 말의 위치
int cb[10];// 주사위 수
int score,max_;
string yn_ ;
void dfs(int lvl){
    if(lvl == 10){
        if(score > max_) {
            // cout << score << "," << yn_<< " hi\n";
            // for(tuple<int,int,int> el : history){               
            //     cout << "(" << get<0>(el) <<","<<get<1>(el)<<","<< get<2>(el)<<") ";
            // }
            // cout << "\n";
            max_ =score;
            
        }
        return;
    }
    
    for(int i =0;i<4;i++){
        if (mal[i]==-1) continue;
        int prev = mal[i];
        int step = cb[lvl];
        
        if(lst[prev].size()>1){  
            mal[i] = lst[mal[i]][1];
            step--;
        }
        //cout <<  "2" << lvl<< i<<  "\n";
        int prev_score = score;
        //cout <<  ",,,," << mal[0] << "\n";
        //if (mal[i]==-1) continue;
        for(int k = 0;k<step;k++){
            // 한칸 이동
            mal[i] = lst[mal[i]][0];
            if(mal[i]==-1) break;
        }
        //이동할 곳에 말이 있으면 안된다.
        yn_ = "Y";
        int j =0;
        for(int el : mal){
            if(el == mal[i] && j != i && mal[i]!= -1) {yn_="N"; break;}
            j++;
        }
        if(yn_=="N"){
            mal[i] = prev;
            continue;
        }
        if(mal[i]!=-1) score = score + mp[mal[i]];
//        cout << "["<<lvl << " : " << i << "," << mal[i] << "," << score << "("<<mp[mal[i]] << ")]" ;
        history[lvl]=make_tuple(i,mal[i],score);
        dfs(lvl+1);
        score = prev_score;
        mal[i]=prev;
        
    }
}
int main(){
    for(int i=0;i<10;i++){
        cin >> cb[i];
    }
    for(int i = 0;i<=19;i++){
        lst[i].push_back(i+1);
    }
    lst[20].push_back(-1); lst[21].push_back(22); lst[22].push_back(23); lst[23].push_back(26);
    lst[24].push_back(25); lst[25].push_back(26); lst[26].push_back(30); lst[27].push_back(28); lst[28].push_back(29);
    lst[29].push_back(26); lst[30].push_back(31); lst[31].push_back(20);
    lst[5].push_back(21);lst[10].push_back(24);lst[15].push_back(29);

    mp.push_back(0);
    for(int i = 1;i<=20;i++){
        mp.push_back(2*i);
    }
    mp[21]=13;mp[22]=16;mp[23]=19;mp[24]=22;mp[25]=24;mp[26]=25;mp[27]=28;mp[28]=27;mp[29]=26;mp[30]=30;mp[31]=35;
    mp2[5]=21; mp2[15]=27; mp2[10]=24;

   dfs(0);
   cout << max_ << "\n";
    return 0;
        /* 말 선택 => a : 0 / b : 1 / c : 2 / d : 3
    말의 위치 => mal[a] / mal[b] / mal[c] / mal[d]
    말의 위치에 있는 점수 => mp[mal[a]] / mp[mal[b]] / mp[mal[c]] / mp[mal[d]]
    주사위 값 => cp[lvl]
    주사위 1(lvl : 0) => [말 종류] a(=0) : mal[a]가 -1이 아닌 것만 선택한다.
                    =>  [현재 인접리스트 요소] lst[mal[a]] : 현재 위치로부터 주사위수만큼 다음 인접 리스트로 이동한다.
                        이동 조건 1.만약 현재 위치의 lst[mal[a]].size()>1 이라면 [다음 인접리스트 요소] lst[mal[a]][1] 존재하지 않는다면 lst[mal[a]][0]
                        이동 조건 2. 종료가 되면 그대로 -1로
                        이동 조건 3. 이동할 곳에 말이 있으면 안된다.
                        for(int k = 0;k<cp[lvl];k++){
                            // 한칸 이동
                            if(lst[mal[a]].size()>1){
                                mal[a] = lst[mal[a]][1];
                            }
                            else{
                                 mal[a] = lst[mal[a]][0];
                            }
                            if(mal[a]==-1) break;
                        }
                    => [총 점수 = 기존 점수 + 새로운 말의 위치의 점수] mal[a] 가 -1이 아닐 때에만 score = score + mp[mal[a]] 계산한다.
        주사위 2(lvl : 1) : a => [말 종류] a(=0)  
            주사위 3(lvl :2): a => [말 종류] a(=0) 
            주사위 3: b(1) => [말 종류] b(=1)
            주사위 3: c
            주사위 3: d
                score = score - mp[mal[d] + cp[lvl]]
            mal[a] 가 -1이 아닐 때에만 score = score - mp[mal[a] + cp[lvl]]
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
//    cout << "a \n";
    // for(int i=1;i<=31;i++){
    //     cout << mp[i] << " ,";
    // }
//    cout << "a1 \n";
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
//    cout << "a2 \n";
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
//    cout << "a3 \n";
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
//    cout << "a4 \n";
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
}