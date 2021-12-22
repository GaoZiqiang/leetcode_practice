/* leetcode T542:01 矩阵
 * 原题链接：https://leetcode-cn.com/problems/01-matrix/
 * */

/* 方法一：动态规划--二维
 *
 * 算法思想：
 * 核心：
 * 跟T64:最小路径和有相似之处
 * 本题中，中间点需要进行上下左右四个方向的判断，为了使问题简化，分为两次遍历矩阵：
 * 第一次，对每个点的上边和左边进行判断--即从左上到右下这个方向；
 * 第二次，对每个点的下边和右边进行判断--即从右下到左上这个方向；
 *
 * 关键点：
 * 1 若矩阵中mat[i][j] == 0，则dp[i][j] = 0；
 * 2 若mat[i][j] != 0，则需要判断点ij上下左右四个方向上距离最近的0点：
 * dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
 *
 * 复杂度分析：
 * 时间复杂度：O(m*n)，二维数组。
 * 空间复杂度：O(m*n)，dp[m][n]二维数组。
 *
 * 参考讲解：《谷歌高畅》P44。
 * */


// 实现方法
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    if (mat.empty()) return {};
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> dp(m, vector<int>(n, INT32_MAX - 1));
    // 先对上边和左边进行判断
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == 0) {
                dp[i][j] = 0;
            } else {
                // 分别对左边和上边进行判断
                if (j > 0) {// 先判断左边
                    dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);
                }
                if (i > 0) {//再判断上边
                    dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
                }
            }
        }
    }
    // 再对下边和右边进行判断
    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            if (mat[i][j] != 0) {
                if (j < n - 1) {// 先判断右边
                    dp[i][j] = min(dp[i][j], dp[i][j+1] + 1);
                }
                if (i < m - 1) {// 再判断下边
                    dp[i][j] = min(dp[i][j], dp[i+1][j] + 1);
                }
            }
        }
    }
    return dp;
}

int main() {
//    [[0,1,0,1,1],[1,1,0,0,1],[0,0,0,1,0],[1,0,1,1,1],[1,0,0,0,1]]
    vector<vector<int>> mat = {{0,1,0,1,1}, {1,1,0,0,1}, {1,0,1,1,1}, {1,0,0,0,1}};
    vector<vector<int>> res = updateMatrix(mat);
    int m = res.size(), n = res[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
}