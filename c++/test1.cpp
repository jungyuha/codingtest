#include <bits/stdc++.h> 
using namespace std;
int main(){
    string dopa = "life is limited";

    cout << dopa << "\n";
    //문자열에서 부분배열(이 부분만을 끄집어낼 수 있겠죠?)
    cout << dopa.substr(0, 3) << "\n";
    // 반대로
    reverse(dopa.begin(), dopa.end());
    cout << dopa << "\n";
    // 추가한다.
    dopa += "dopa!!";
    cout << dopa << '\n';
    return 0;
}

// g++ -std=c++14 -Wall c2559.cpp -o test.out