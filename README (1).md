# 5. 문자열

## \[1] char형 아스키코드

* a : 97 \~ z : 122
* A : 65 \~ Z :91
* 0 : 48 \~ 9 : 57
* 알파벳 개수 : 26개

```cpp
char c ;
// 알파벳 순서(int)
int test = c - 'a';
// 알파벳 문자
char test2 = 'a'+13;
//배열 인덱스로도 사용 가능
int cnt[100];
cnt['a'] = 1; // 이는 cnt[97] = 1; 과 같다.
// 아스키 코드 소문자 비교
if(c>='a' && c <= 'z')
// char형을 int로 변환하기
char c = '1';
int n = c - '0';
```

## \[2] 여러줄 입력받아 한 줄씩 처리하기

```cpp
/*
a
tv
ptoui
bontres
zoggax
wiinq
eep
houctuh
end
*/
#include <bits/stdc++.h>
using namespace std;

string buffer;
string s;
int main(){
    while(1){
        getline(cin,s);
        cout << "??  : " << s << "\n";
        if(s=="end") break;
    }

    return 0;
}
```

## \[3] 공백 포함하여 문자열을 입력받기

```cpp
string s;
getline(cin, s)
```

## \[4]   문자열을 int로 int를 문자열로

```cpp
string s;
int r = stoi(s);
s = to_string(r);
```

## \[5]   split 구현

```cpp
vector<string> split(string input , string delimiter){
    vector<string> ret;
    long long pos;
    string token;

    while((pos=input.find(delimiter)) != string::npos){
        token =  input.substr(0,pos);
        ret.push_back(token);
        input.erase(0,pos+delimiter.length());
    }
    ret.push_back(input);
    return ret;
}

string s;
cin >> s;
vector<string> hw = split(s,":");
```
