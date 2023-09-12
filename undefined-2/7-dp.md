# \[7] DP 솔루션

#### (1) 7-H:2293

<mark style="background-color:green;">**문제 분류 : 왼쪽 냅색 ( 다른 애들 더해주기 ) DP**</mark>

![](<../.gitbook/assets/image (3) (1) (1) (1) (1) (1).png>)

* 경우의 수 : 더하기
* 무한대 -> 왼쪽부터 dp 누적
* **점화식**
* **arr\[0]=1**

#### (2) 7-I:4781 사탕가게

![](<../.gitbook/assets/image (2) (1) (1) (1) (1) (1) (1) (1).png>)

* 실수형 연산
* 무한대 -> 왼쪽부터 dp 누적&#x20;

#### (3) _7 - J : 12865_ [평범한 배낭](https://www.acmicpc.net/problem/12865)

<mark style="background-color:green;">**문제 분류 : 오른쪽 냅색 ( 다른 애들 더해주기 ) DP**</mark>

{% embed url="http://boj.kr/9bf457df9fb4457c8b5e70a52ca4c933" %}

#### (4) _7 - K : 1513_ 경로 찾기

* <mark style="background-color:green;">**문제 분류 : DP**</mark>
  * <mark style="background-color:green;">**상태값 : X , Y , C(오락실 방문 횟수) , prev( 직전에 방문한 오락실 번호 )**</mark>

{% embed url="http://boj.kr/60dbddfd09b34a019c1115999cf9eff1" %}

* ![](<../.gitbook/assets/image (35).png>)
* 표시할 수 있는 상태값 : X , Y , C(오락실 방문 횟수) , prev( 직전에 방문한 오락실 번호 )
* dp는 -1로 초기화 (정답이 되지 않는 수)
* 재귀 함수 오버플로우 처리 형태에는 2가지가 있음
  * 함수 초입에 검사하기
  * 함수 들어가기 전에 if문으로 검사하기
* return 0; 은 해당 경우를 배제시킨다는 뜻

#### (5) _7 - L : 1535 안녕_

{% embed url="http://boj.kr/a2dad6c8b1a74752b1127f90f914c5ac" %}

* <mark style="background-color:green;">**문제 분류 : 오른쪽 냅색 DP**</mark>
  * <mark style="background-color:green;">**값이 무제한이 아니라 할당양이 한정된 경우에는 오른쪽에서 부터 시작하는 DP를 써야한다.**</mark>
  *   <mark style="background-color:green;">**푸는 원리**</mark>

      <figure><img src="../.gitbook/assets/image (1) (1) (1) (1) (1) (1) (1) (1).png" alt="" width="375"><figcaption></figcaption></figure>
  * <mark style="background-color:red;">**틀린 방법**</mark>
    *

        <figure><img src="../.gitbook/assets/image (1) (1) (1) (1) (1) (1) (1) (1) (1).png" alt="" width="375"><figcaption></figcaption></figure>



#### _(7) 7 - M : 16235_ 나무 재테크

{% embed url="http://boj.kr/6724b47bbb4244c7a74a38a5c7f2b70c" %}

<mark style="background-color:green;">**문제 분류 :  구현 (봄/여름/가을/겨울)**</mark>

* <mark style="background-color:green;">**한 칸에 나무 여러개 => 한 칸의 자료형이 vector가 됨 (나무를 오름차순 해야함)**</mark>
* <mark style="background-color:green;">**temp 배열 사용 => 양분을 다음 계절에 넣기 위해**</mark>

#### (8) _7 - N : 17136_ 색종이 붙이기

{% embed url="http://boj.kr/ac40156090a44a3883d00e1da2250094" %}

* <mark style="background-color:green;">**문제 분류 1 : 휴리스틱 (큰색종이부터 고르기)**</mark>
  * ![](<../.gitbook/assets/image (73).png>)
* <mark style="background-color:green;">**문제 분류 2 : dfs 백트래킹 -> 경우의 수 가지치기**</mark>
  * ![](<../.gitbook/assets/image (71).png>) <mark style="background-color:green;">**탐색하지 않아도 되는 부분은 탐색 X**</mark>
  * <mark style="background-color:green;">**상태 :  X,Y,CNT(사용한 색종이의 수 )**</mark>
    * ![](<../.gitbook/assets/image (72).png>)

#### (9) 7-O:17837 새로운 게임 2

{% embed url="http://boj.kr/bd7ad2c207324e6e90f28954e5a7b4c5" %}

* <mark style="background-color:green;">**문제 분류 1: 구현**</mark>
  * 한칸에 여러개 -> vector 사용
  * 방향바꾸기
    * ![](<../.gitbook/assets/image (79).png>)
  * 말 움직이기
    * \
      ![](<../.gitbook/assets/image (80).png>)
    * c부터 옮기기
      * ![](<../.gitbook/assets/image (82).png>)
    *   c 말찾기

        <div align="left">

        <figure><img src="../.gitbook/assets/image (81).png" alt="" width="375"><figcaption></figcaption></figure>

        </div>

#### (P) 7-P:14867 물통

{% embed url="http://boj.kr/01ca758c46154055ab85443720f133cf" %}

#### (Q) _7 - Q : 1344_ 축구

{% embed url="http://boj.kr/21dcfcb491724456838629636319d766" %}

#### (R) 7-R:10942 팰린드롬?

{% embed url="http://boj.kr/fca6ee00be804cfabbc8c8090225bfd0" %}

* <mark style="background-color:green;">**문제 분류 1 : DP**</mark>
  * ![](<../.gitbook/assets/image (100).png>)
* 무식하게 풀 때 시간 복잡도 : NC2(n개중에 2개 고르고)xN(각각 비교하기)->40억 너무큼
* <mark style="background-color:blue;">문제 핵심 1 : i\~j 범위의 펠린드롬 여부를 나타내는 boolean 2차원 배열 필요</mark>
  * <mark style="background-color:blue;">dp\[i]\[i] = true</mark>
  * <mark style="background-color:blue;">dp\[i]==dp\[i+1] -> true</mark>
  * <mark style="background-color:blue;">펠린드롬인것에 양쪽 요소 1개가 서로 같으면 그것도 -> true</mark>&#x20;
