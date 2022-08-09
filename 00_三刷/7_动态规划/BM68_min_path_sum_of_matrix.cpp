/* BM68 矩阵的最小路径和 对比 NC138 矩阵最长递增路径
 * 原题链接：https://www.nowcoder.com/practice/7d21b6be4c6b429bb92d219341c4f8bb?tpId=295&tqId=1009012&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj%3Fpage%3D1%26tab%3D%25E7%25AE%2597%25E6%25B3%2595%25E7%25AF%2587%26topicId%3D295
 * 算法思想：
 * 动态规划dp
 * /

class Solution {
public:
    int dirs[2][2] = {{-1, 0}, {0, -1}};

public:
    /**
     *
     * @param matrix int整型vector<vector<>> the matrix
     * @return int整型
     */
    int minPathSum(vector<vector<int> >& matrix) {
        // write code here
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 101));

        dp[0][0] = matrix[0][0];

        // 初始化第一行
        for (int i = 1; i < n; i++) dp[0][i] = dp[0][i-1] + matrix[0][i];

        // 初始化第一列
        for (int j = 1; j < m; j++) dp[j][0] = dp[j-1][0] + matrix[j][0];

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + matrix[i][j];
            }
        }

        return dp[m-1][n-1];
    }
};