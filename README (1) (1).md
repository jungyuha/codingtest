# 9. 배열

### (1) 1차원 배열 초기화

<pre class="language-cpp"><code class="lang-cpp">int a[51];

int main(){ 
<strong>        fill(a,a + 51, 0);
</strong>return 0;
}
</code></pre>

### (2) 2차원 배열 초기화

* memset()의 경우 초기화시킬 수 있는 값은 0과 -1로 제한이 됩니다.

<pre class="language-cpp"><code class="lang-cpp">int a[51][51];
bool visited[51][51]; 

int main(){ 
<strong>        fill(&#x26;a[0][0], &#x26;a[0][0] + 51 * 51, 0);
</strong>        fill(&#x26;visited[0][0], &#x26;visited[0][0] + 51 * 51, 0);        
        memset(visited, 0, sizeof(visited));
return 0;
}
</code></pre>

### (2) 함수의 매개변수에 배열 주소 넣고 참조하기

```cpp
void printArray(int* array, int length)
{
    for (int index=0; index < length; ++index)
        std::cout << array[index] << ' ';
}
int main()
{
    int array[6] = { 6, 5, 4, 3, 2, 1 }; // remember, arrays decay into pointers
    printArray(array, 6); // so array evaluates to a pointer to the first element of the array here, no & needed
}
```

### (3) 2차원 배열 90도 회전하기 ( 오른쪽 방향 )

<mark style="background-color:green;">**배열 회전**</mark>

* <mark style="background-color:green;">**90도 회전 : a\[i]\[j] = a\[n-j-1]\[i]**</mark>
  * 인덱스는 0부터 시작하고 , n은 변의 길이이다.
  * ![](.gitbook/assets/BACE32B3-0FDE-4A80-A459-C235518C555F.jpeg)
