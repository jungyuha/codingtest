# \[2] DFS,BFS 솔루션

#### (1) 2-H:4659

* 연속성 유무
  * cnt 활용
* 연속 동일값 체크
  * prev 활용

#### (2) 2-I:2870 수학숙제

* int는 숫자 10글자까지만 표현이 가능(10^9)
* long은 19글자(10^18)
* 하지만 여기서는 한 줄이 100글자
* **숫자를 String으로 표현**
* 문자열로된 수를 비교하는 custom operator 필요
  * ![](<../../.gitbook/assets/image (22).png>)
* 아스키코드 (65,97) : 숫자체크는 if ( a< 65 )
  * ![](<../../.gitbook/assets/image (21).png>)

#### _(3) 2 - J : 10709_ [기상캐스터](https://www.acmicpc.net/problem/10709)

{% embed url="http://boj.kr/2e4e57d962ef41a9bb4bc8f670ac158c" %}

* <mark style="background-color:green;">**문제 분류 :**</mark> <mark style="background-color:green;"></mark><mark style="background-color:green;">문자 배열을 받아 숫자배열로 만드는 문제</mark>
* 구름(c)는 0으로 표기
  * 다음 구름을 만날 때 까지 카운트를 증가시킴
* 구름이 아니면 -1 표기
* 초기화 방법 : 구름이 있으면 0 , 없으면 -1로 먼저 초기화한다.
