# BFS

## \[1] 완전 탐색

### (1) 탐색 방식

* **한겹 한겹 넓어지는 방식**
  * ![](<../../.gitbook/assets/image (15).png>)
* **큐에다가 탐색할 모든 좌표가 한번씩은 들어간다.** = **출발점이 여러개가 되는 것이다.**
* **탐색할 좌표를 큐에다가 넣는다.**

### (2) 응용

1. **중간탐색 방식**
   * 모든 칸을 탐색하지 않고 한겹한겹 넓어지다가 **다시 거기서 탐색을 시작하고 또 탐색을 다시 시작하고**..
     * 메모리 초과 문제에서 해결방법이 될 수 있음
   * 반드시 visited를 체크하여 이미 방문한 정점은 다시 탐색하지 않는다.
   * 중간부터 다시 탐색할 수 있도록 다시 탐색할 좌표들을 담는 temp 큐가 필요하다.=큐가 2개가 필요하다.
2. **특정 부분을 제외하고 완전탐색하기**
3.

### (3) 예제

1. 백준 3197번
