/*
*) 입력

예제 입력 1 

*) 메모리
int w,h,dp[35][65][2];
*) 시나리오

int go(int w_,int h_,int hw):
// w = 0 , h = 1
    if(w_ < 0 || h_ < 0 ) return 0;
    if(w_== 0 && h_ == 0) return 1;
    if(dp[w_][h_][hw]!=-1) return dp[w_][h_][hw];

    int res = go(w_,h_-1,0) + go(w_-1,h_+1,1);
    dp[w_][h_][hw]= res;
    
    return res;

(메인)
    cout << go(n,0,0);
*) 출력
(1) 
cout << "cx :"<<cx<< ",cy :"<<cy<< ",res :"<<res <<endl;
*/