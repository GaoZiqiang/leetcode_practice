/* leetcode T64:最小路径和
 * 原题链接：https://leetcode-cn.com/problems/minimum-path-sum/
 * */

/* 方法一：动态规划--二维
 *
 * 算法思想：
 * 核心：
 * 从矩阵全局的角度来看，每个元素grid[i][j]都有不同的路径可以到达当前元素grid[i][j]
 * 然后根据当前元素grid[i][j]位置的不同，可以分为以下几种情况：
 * 1 第一个点，没有其他选择
 * 2 第0行，边界行，只有一个选择--走从当前元素grid[i][j]左边那个到当前元素这条路径
 * 3 第0列，边界列，只有一个选择--走当前元素上边那个到当前元素这条路径
 * 4 中间行列，此时当前元素grid[i][j]有上边和左边两个方向的路径可以选择
 *
 * 关键点：
 * 1 使用dp[m][n]二维数组记录的是：
 * 从起点触发到当前元素的最小路径的元素和
 * 2 因此，具体到每个元素grid[i][j]，通过判断上边和左边两个方向上，哪个路径最小，就选择从哪个路径到当前元素grid[i][j]
 *
 * 复杂度分析：
 * 时间复杂度：O(m*n)，二维数组。
 * 空间复杂度：O(m*n)，dp[m][n]二维数组。
 *
 * 参考讲解：《谷歌高畅》P43
 * */


// 实现方法
#include <vector>
#include <iostream>

using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));// dp[i][j]：到当前元素为止的最小路径和
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {// 第一个点，没有其他选择
                dp[i][j] = grid[i][j];
            } else if (i == 0) {// 第0行，边界行，只有一个选择--走从当前元素grid[i][j]左边那个到当前元素这条路径
                dp[i][j] = dp[i][j-1] + grid[i][j];
            } else if (j == 0) {// 第0列，边界列，只有一个选择--走当前元素上边那个到当前元素这条路径
                dp[i][j] = dp[i-1][j] + grid[i][j];
            } else {// 中间行列，此时当前元素grid[i][j]有上边和左边两个方向的路径可以选择
                dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i][j];
            }
        }
    }
    return dp[m-1][n-1];
}

int main() {
    vector<vector<int>> grid = {{1,2,3}, {4,5,6}};
    cout << minPathSum(grid);
}