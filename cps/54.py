# 54. 올바른 괄호(stack)
# 괄호가 입력되면 올바른 괄호이면 “YES", 올바르지 않으면 ”NO"를 출력합니다.
# (())() 이것은 괄호의 쌍이 올바르게 위치하는 거지만, (()()))은 올바른 괄호가 아니다.
# ▣ 입력설명
# 첫 번째 줄에 괄호 문자열이 입력됩니다. 문자열의 최대 길이는 30이다.
# ▣ 출력설명
# 첫 번째 줄에 YES, NO를 출력한다.
# ▣ 입력예제 1
# (()(()))(()
# ▣ 출력예제 1
# NO
# ▣ 입력예제 2
# ()()(()())
# ▣ 출력예제 2
# YES
# 스택 구현

import sys

stack = []
res = ''
a = sys.stdin.readline().strip()
a = list(a)
#print(a)

# (( )) ()
for el in a :
    if el == '(':
        stack.append(el)
#        print(stack)
    elif el == ')':
        if len(stack) == 0:
            res = "NO"
            break;
        else:
            stack.pop(len(stack)-1)
#            print(stack)
if res != "NO" and len(stack) == 0:
    res = "YES"
else:
    res = "NO"
#print(stack)
print(res)


