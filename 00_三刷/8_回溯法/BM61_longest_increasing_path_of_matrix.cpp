/* BM61 矩阵最长递增路径
 * 原题链接：https://www.nowcoder.com/practice/7a71a88cdf294ce6bdf54c899be967a2?tpId=295&tqId=1076860&ru=/exam/oj&qru=/ta/format-top101/question-ranking&sourceUrl=%2Fexam%2Foj
 * 算法思想：
 * 需要一个辅助数组存放每个点的最长路径
 * /

class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 递增路径的最大长度
     * @param matrix int整型vector<vector<>> 描述矩阵的每个数
     * @return int整型
     */
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j) {
        if (dp[i][j] != 0) return dp[i][j];

        dp[i][j]++;
        for (int k = 0; k < 4; k++) {
            int nexti = i + dirs[k][0];
            int nextj = j + dirs[k][1];

            if (nexti >= 0 && nexti < matrix.size() && nextj >= 0 && nextj < matrix[0].size() && matrix[nexti][nextj] > matrix[i][j]) {
                dp[i][j] = max(dp[i][j], dfs(matrix, dp, nexti, nextj) + 1);
            }
        }
        return dp[i][j];
    }

    int solve(vector<vector<int> >& matrix) {
        // write code here
        int m = matrix.size(), n = matrix[0].size();
        if (m == 0 || n == 0) return 0;
        vector<vector<int>> dp(m, vector<int>(n, 0));

        int ans = -1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, dfs(matrix, dp, i, j));
            }
        }

        return ans;
    }
};