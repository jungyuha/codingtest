# \[7] DP 솔루션

#### (1) 7-H:2293

<mark style="background-color:green;">**문제 분류 : 왼쪽 냅색 ( 다른 애들 더해주기 ) DP**</mark>

![](<../.gitbook/assets/image (3) (1) (1).png>)

* 경우의 수 : 더하기
* 무한대 -> 왼쪽부터 dp 누적
* **점화식**
* **arr\[0]=1**

#### (2) 7-I:4781 사탕가게

![](<../.gitbook/assets/image (2) (1) (1).png>)

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

      <figure><img src="../.gitbook/assets/image (1) (1).png" alt="" width="375"><figcaption></figcaption></figure>
  * <mark style="background-color:red;">**틀린 방법**</mark>
    *

        <figure><img src="../.gitbook/assets/image (1) (1) (1).png" alt="" width="375"><figcaption></figcaption></figure>



#### _(7) 7 - M : 16235_ 나무 재테크

{% embed url="http://boj.kr/6724b47bbb4244c7a74a38a5c7f2b70c" %}

<mark style="background-color:green;">**문제 분류 :  구현 (봄/여름/가을/겨울)**</mark>

* <mark style="background-color:green;">**한 칸에 나무 여러개 => 한 칸의 자료형이 vector가 됨 (나무를 오름차순 해야함)**</mark>
* <mark style="background-color:green;">**temp 배열 사용 => 양분을 다음 계절에 넣기 위해**</mark>
