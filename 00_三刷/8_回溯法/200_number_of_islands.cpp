/* leetcode T200:岛屿数量
 * 原题链接：https://leetcode.cn/problems/number-of-islands/
 * */

/* 方法一：并查集
 *
 * 算法思想：
 * 每次比较上边grid[i-1][j]和左边grid[i][j-1]这两个元素集合
 *
 * 复杂度分析：
 * 时间复杂度：O((m*n)^2log(m*n))。
 * 空间复杂度：O(m*n)，parent数组。
 *
 * 方法二：dfs递归
 * */


#include <vector>

using namespace std;

// 方法一：并查集
int findParent(vector<int>& parent, int index) {
    if (parent[index] != index) {
        parent[index] = findParent(parent, parent[index]);
    }
    return parent[index];
}

void unionParent(vector<int>& parent, int index1, int index2) {
    parent[findParent(parent, index1)] = findParent(parent, index2);
}

int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
    int m = grid.size(), n = grid[0].size();// 行列数
    vector<int> parent(m*n);
    int res = 0;

    // 初始化parent数组
    for (int i = 0; i < m*n; i++) parent[i] = i;

    // 并查
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '0') continue;
            if (i > 0 && grid[i-1][j] == '1') unionParent(parent, i*n + j, (i-1)*n + j);
            if (j > 0 && grid[i][j-1] == '1') unionParent(parent, i*n + j, i*n + j - 1);
        }
    }

    // 统计
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '0') continue;
            else if (parent[i*n+j] == i*n + j) res++;
        }
    }

    return res;
}


// 方法二：DFS
void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int m, int n, int i_, int j_) {
    for (int j = j_ + 1; j < n; j++) {
        if (!visited[i_][j] && grid[i_][j] == '1') {
            visited[i_][j] = 1;
            dfs(grid, visited, m, n, i_, j);
        }
    }
    for (int i = i_ + 1; i < m; i++) {
        if (!visited[i][j_] && grid[i][j_] == '1') {
            visited[i][j_] = 1;
            dfs(grid, visited, m, n, i, j_);
        }
    }
    return;
}


int numIslands(vector<vector<char>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    int res = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                dfs(grid, visited, m, n, i, j);
                res++;
            }
        }
    }
    return res;
}

// 方法二：dfs递归
void dfs(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& used) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return;
    if (used[i][j] == true || grid[i][j] == '0') return;

    used[i][j] = true;
    // 四个方向遍历???
    dfs(grid, i-1, j, used);
    dfs(grid, i, j-1, used);
    dfs(grid, i+1, j, used);
    dfs(grid, i, j+1, used);

    return;
}

int solve(vector<vector<char> >& grid) {
    // write code here
    int m = grid.size(), n = grid[0].size();// 行/列数
    vector<vector<bool>> used(m, vector<bool>(n, false));

    int ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (used[i][j] == false && grid[i][j] == '1') {
                dfs(grid, i, j, used);
                ans++;
            }
        }
    }

    return ans;
}