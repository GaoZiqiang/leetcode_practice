/* leetcode T63:不同路II
 * 原题链接：https://leetcode-cn.com/problems/unique-paths-ii/
 * */

/* 方法一：dp动态规划 基于T62:不同路径
 *
 * 算法思想：
 * 1 dp数组：dp[i][j]从起始点到位置[i][j]的路径总数
 * 2 递推公式/状态方程：dp[i][j] = dp[i-1][j] + dp[i][j-1];// 位置[i][j]主要有左边和上边两个方向的路径来源
 * 3 dp初始化：for (int i = 0; i < m; i++) dp[i][0] = 1;for (int j = 0; j < n; j++) dp[0][j] = 1;(上侧和左侧只有一个路径)
 * 4 dp遍历顺序：从左上到右下
 *
 * 改进点：
 * if(obstacleGrid[i][j])// 有障碍
 *  dp[i][j] = 0;
 * else
 *  dp[i][j] = dp[i-1][j] + dp[i][j-1];// 递推方程
 *
 * 复杂度分析：
 * 时间复杂度：O(m*n)，两层循环。
 * 空间复杂度：O(m*n)，dp数组。
 * */

#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    // dp数组
    vector<vector<int>> dp(m, vector<int>(n, 0));

    if (obstacleGrid[m-1][n-1])
        return 0;

    if (obstacleGrid[0][0])
        return 0;

    // dp遍历顺序
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {// 起始点--dp初始化
                if (obstacleGrid[i][j])
                    dp[i][j] = 0;
                else
                    dp[i][j] = 1;
            }
            else if(j == 0 && i > 0) {// 左侧
                if (obstacleGrid[i][j]) {
                    dp[i][j] = 0;
                } else
                    dp[i][j] = dp[i-1][j];
            } else if( i == 0 && j > 0) {// 上侧
                if (obstacleGrid[i][j])
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i][j-1];
            } else {// 其他
                if(obstacleGrid[i][j])// 有障碍
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];// 递推方程
            }
        }

    return dp[m-1][n-1];
}