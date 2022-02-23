/* leetcode T62:不同路径
 * 原题链接：https://leetcode-cn.com/problems/unique-paths/
 * */

/* 方法一：dp动态规划
 *
 * 算法思想：
 * 1 dp数组：dp[i][j]从起始点到位置[i][j]的路径总数
 * 2 递推公式/状态方程：dp[i][j] = dp[i-1][j] + dp[i][j-1];// 位置[i][j]主要有左边和上边两个方向的路径来源
 * 3 dp初始化：for (int i = 0; i < m; i++) dp[i][0] = 1;for (int j = 0; j < n; j++) dp[0][j] = 1;(上侧和左侧只有一个路径)
 * 4 dp遍历顺序：从左上到右下
 *
 * 复杂度分析：
 * 时间复杂度：O(m*n)，两层循环。
 * 空间复杂度：O(m*n)，dp数组。
 * */

#include <vector>

using namespace std;

int uniquePaths(int m, int n) {
    // dp数组
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // dp初始化
    for (int i = 0; i < m; i++) dp[i][0] = 1;
    for (int j = 0; j < n; j++) dp[0][j] = 1;

    // dp遍历顺序
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1];// dp方程

    return dp[m-1][n-1];
}