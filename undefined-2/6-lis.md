# \[6] 이분탐색,LIS 솔루션

#### (1) 6-H:2776

풀이 : 이분탐색

![](<../.gitbook/assets/image (6).png>)

#### (2) 6-I:14627

풀이 : 이분탐색

![](<../.gitbook/assets/image (7).png>)

#### _(6) 6 - J : 1561 놀이공원_&#x20;

{% embed url="http://boj.kr/c2fb354cd24049edb34fbd09a91a38d3" %}

* <mark style="background-color:green;">**문제 분류 : 이분탐색**</mark>
  * <mark style="background-color:green;">**특정 시간이 mid일 때 n명 이상을 태울 수 있는지 확인**</mark>
  * <mark style="background-color:green;">**덩어리를 만드는 문제**</mark>
* 최대 600억 ( 놀이기구 1개만 있고 30분 \* 최대 인원수 20억명 )
* 순차적으로 하나하나 탐색하는 문제가 아님
*   한번에 7명을 태울수 있음 => 만약 30명 정도 있으면 4\~5덩어리 정도 있겠지 -> <mark style="background-color:red;">**이 덩어리를 먼저 계산**</mark>해버린다.

    (_**8–H:17297**에도 먼저 계산해버리는 누적 자르기 문제_)

    * ![](<../.gitbook/assets/image (27).png>)
    * mid 이분 탐색

#### (4) _6 - K : 14003_ 가장 긴 증가하는 부분 수열 5

{% embed url="http://boj.kr/b4a30d5a7f404a25bf3097a45808b5e2" %}
