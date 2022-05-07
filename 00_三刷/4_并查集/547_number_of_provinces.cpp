/* leetcode T547:省份数量
 * 原题链接：https://leetcode-cn.com/problems/number-of-provinces/
 * */

/* 方法一：基于图的DFS/BFS递归遍历
 *
 * 算法思想：统计连通子图个数
 * 核心：
 * 图的DFS或BFS遍历，每个省份就是一个连通子图
 *
 * 关键点：
 * 与T695:岛屿的最大面积相比，如何判断两个节点是否相邻？
 * 判断if (isConnected[i][j] == 1)即可
 *
 * 复杂度分析：
 * 时间复杂度：O(n*n)，数组中元素个数。
 * 空间复杂度：O(n*n)，递归需要栈空间，递归的深度最大可能是整个网格的大小，故为m*n。
 *
 * 参考讲解：
 * https://leetcode-cn.com/problems/number-of-provinces/solution/sheng-fen-shu-liang-by-leetcode-solution-eyk0/
 *
 * 方法二：并查集
 *
 * 复杂度分析：
 * 时间复杂度：O(2*n^2*logn^2)。
 * 空间复杂度：O(n)，parent数组。
 * */

// 解决方法
#include <vector>

using namespace std;

// dfs递归
void dfs(vector<vector<int>>& isConnected, vector<int>& visited, int n, int i) {
    for (int j = 0; j < n; j++) {
        if (!visited[j] && isConnected[i][j]) {
            visited[j] = 1;
            dfs(isConnected, visited, n, j);
        }
    }
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<int> visited(n, 1);
    int res = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(isConnected, visited, n, i);
            res++;
        }
    }

    return res;
}

// 方法二：并查集
int Find(vector<int>& parent, int index) {
    if (parent[index] != index) {
        parent[index] = Find(parent, parent[index]);// 查找并更新parent的过程
    }
    return parent[index];
}

void Union(vector<int>& parent, int index1, int index2) {
    parent[Find(parent, index1)] = Find(parent, index2);// parent重新赋值的过程
    return;
}

int findCircleNum(vector<vector<int>>& isConnected) {
    int n = isConnected.size();
    vector<int> parent(n, 0);
    int res = 0;

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (isConnected[i][j]) {
                Union(parent, i, j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (parent[i] == i)
            res++;
    }

    return res;
}