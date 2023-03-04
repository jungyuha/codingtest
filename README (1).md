# 5. 문자열

## \[0] 목차

[#char](<README (1).md#char> "mention")

[#2](<README (1).md#2> "mention")

[#3](<README (1).md#3> "mention")

[#4-int-int](<README (1).md#4-int-int> "mention")

[#5-split](<README (1).md#5-split> "mention")

[#6](<README (1).md#6> "mention")

[#7](<README (1).md#7> "mention")

## \[1] char형 아스키코드 <a href="#char" id="char"></a>

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

## \[6] 문자열 일부 추출하기

```cpp
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string sentence = "i like coding";
    string find_str = "coding";
    string replace_str = "test";
    sentence.replace(sentence.find(find_str), find_str.length(), replace_str);
    cout << sentence << endl;
}

// i like test
```

* setence.find(find\_str) : 전체 문자열에서 "coding"을 찾아 그 위치를 알아냅니다.&#x20;
* find\_str.length(): 찾아야 할 문자열의 길이를 replace 함수에 알려줍니다.&#x20;
* replace\_str : 찾아낸 문자열을 교체할 새로운 문자열입니다.

## \[7] 숫자로 구성된 문자열 자릿수 계산 및 변경하기

```cpp
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s1 = "12345";
    cout << s1[0] <<endl;
    
    int n=s1[0]-'0';
    n+=3;
    cout << char('0'+n) << endl;
    
    s1[0]=char('0'+n);
    cout << s1 << endl;
}
// 1
// 4
// 42435
```

* s1\[0] : 문자열의 첫번째 문자
* int n=s1\[0]-'0': 문자열의 첫번째 문자의 숫자(int 타입)
* char('0'+n) : 문자타입의 숫자
* s1\[0] = char('0'+n) : 문자열의 첫번째 문자 치환

## \[8] 문자열 일부 변경하기(문자열 숫자 추출)

```cpp
string s1 = "12345";
cout << s1[0] <<endl;
int n=s1[0]-'0';
n+=3;
cout << char(n+'0') << endl;
s1[0]=char(n+'0');
cout << s1 << endl;
```

* s1\[0] : 문자열의 첫번째 문자
* 문자열의 숫자 추출하기
  * ```cpp
    int n=s1[0]-'0';
    ```
* 숫자열을 문자로 변환
  * ```cpp
    char(n+'0')
    ```
* 바꾼 숫자를 다시 문자열 치환
  * ```cpp
    s1[0]=char(n+'0');
    ```

