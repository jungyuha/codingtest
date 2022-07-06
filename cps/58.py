# 58. 이진트리 깊이우선탐색(DFS)
# 아래 그림과 같은 이진트리를 전위순회와 후위순회를 연습해보세요.
# 전위순회 출력 : 1 2 4 5 3 6 7
# 중위순회 출력 : 4 2 5 1 6 3 7
# 후위순회 출력 : 4 5 2 6 7 3 1

dfs1 = []
dfs2 = []
dfs3 = []

def DFS_binary_tree_1(root): # 전위 순회
    print(root)
    if root > 7:
        return
    dfs1.append(root)
    DFS_binary_tree_1(2*root)
    DFS_binary_tree_1(2 * root+1)

def DFS_binary_tree_2(root): # 중위 순회
    print(root)
    if root > 7:
        return
    DFS_binary_tree_2(2*root)
    dfs2.append(root)
    DFS_binary_tree_2(2 * root+1)

def DFS_binary_tree_3(root): # 후위 순회
    print(root)
    if root > 7:
        return
    DFS_binary_tree_3(2*root)
    DFS_binary_tree_3(2 * root+1)
    dfs3.append(root)

DFS_binary_tree_1(1)
DFS_binary_tree_2(1)
DFS_binary_tree_3(1)

print(dfs1)
print(dfs2)
print(dfs3)
