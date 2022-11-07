#include <bits/stdc++.h>
using namespace std;

/*
n : 종이의 줄의 개수
*/
int n ;
vector <string> strs1;
vector <int> res;
int res2[100];
int main(){
    fill(res2,res2+100,-1);
    cin >> n;

    for (int i =0;i<n;i++){
        string s;
        cin >> s;
        strs1.push_back(s);
    }

    for(string s : strs1){
        for(int i = 0 ; i<s.length();i++){
            if( (char)s[i] >= '0' && (char)s[i] <= '9'){
                res2[i]=(int)(s[i]-'0');
            }
        }
        // for(int i : res2){
        //     cout << i ;
        // }
        int j=0,num=0;
        bool numYn = false;
        while(j < 100){
            if(numYn && res2[j]==-1){
                res.push_back(num);
                num = 0;
                numYn = false;
                continue;
            }
            else if(res2[j]>-1){
                numYn = true;
                num = num*10 + res2[j];
            }
            j++;
        }
        fill(res2,res2+100,-1);
    }
    sort(res.begin(),res.end());

    for(int el : res){
        cout << el << "\n";
    }
    return 0;
}